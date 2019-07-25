#include"Boss.h"
#include"Textures.h"
Boss::Boss()
{
	hp = 16;
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void Boss::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + BOSS_W;
	bottom = y + BOSS_H;
}
void Boss::LoadResource()
{
	

	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;
	textures->Add(ID_TEX_ENEMY, L"Enemies\\Enemies.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 texBox = textures->Get(ID_TEX_ENEMY);
	
	sprites->Add(6000, 915, 21, 949, 69, texBox);//boss right
	sprites->Add(6001, 959, 15, 997, 69, texBox);
	
	sprites->Add(6010, 970, 106, 1004, 154, texBox);//left
	sprites->Add(6011, 922, 100, 960, 154, texBox);
	
	sprites->Add(6020, 926, 197, 942, 213, texBox);//effect dead
	sprites->Add(6021, 952, 188, 984, 220, texBox);
	
	ani = new CAnimation(100);
	ani->Add(6000);
	ani->Add(6001);
	animations->Add(10, ani);
	
	ani = new CAnimation(100);
	ani->Add(6010);
	ani->Add(6011);
	animations->Add(11, ani);
	
	ani = new CAnimation(100);
	ani->Add(6020);
	ani->Add(6021);
	animations->Add(12, ani);
	
	AddAnimation(10);//0
	AddAnimation(11);//1
	AddAnimation(12);//2
	SetPosition(64.0f, 164.0f);


}
void Boss::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	
	if (IsAble == true) {
		CGameObject::Update(dt);
		//fall down
		if (vy == 0)
			vy = -BOSS_JUMP;
		vy += GRAVITY * dt;

		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		coEvents.clear();
		CalcPotentialCollisions(coObjects, coEvents);
		if (coEvents.size() == 0)
		{
			x += dx;
			y += dy;
		}
		else
		{
			x += dx;//Khong quan tam den va cham ngang
			float min_tx, min_ty, nx = 0, ny;
			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
			// xu ly va cham voi block
			for (UINT i = 0; i < coEventsResult.size(); i++)
			{
				LPCOLLISIONEVENT e = coEventsResult[i];

				if (dynamic_cast<CBrick *>(e->obj))
				{
					CBrick *brick = dynamic_cast<CBrick *>(e->obj);

					// xu ly va cham voi block
					//y += min_ty * dy + ny * 0.1f;
					if (ny != 0) vy = 0;
				}
			}

		}
		if (x < edgeA || x>edgeB)
		{
			vx = -vx;
			direction = -direction;
		}
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}

}
void Boss::Render()
{
	
	D3DXVECTOR3 P = CGameObject::ConverObjectToViewPort();
	int ani;
	if (IsAble == false)
	{
		ani = 2;
		animations[ani]->Render(P.x, P.y);
		if(GetTickCount()-time>3000)
				IsDie = true;
	}
	else
	{
		if (direction > 0)
			ani = 0;
		else
			ani = 1;
		animations[ani]->Render(P.x, P.y);
		/*RenderBoundingBox();*/
	}
	Imformation *im = Imformation::GetInstance();
	Ryu *ryu = Ryu::GetInstance();
	im->Update(ryu->GetHp(),hp);
}
Boss::~Boss()
{

}
void Boss::CreateBoss(float x, float y, int direcint, int A, int B)
{
	edgeA = A;
	edgeB = B;
	direction = direcint;
	if (direction > 0)
	{
		vx = BOSS_SPEED;
	}
	else
	{
		vx = -BOSS_SPEED;
	}
	SetPosition(x, y);
}
void Boss::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void Boss::Iskill()
{
	hp--;
	if (hp == 0) {
		IsAble = false;
		time = GetTickCount();
	}
}
void Boss::GetHp(int &a)
{
	a = hp;
}
