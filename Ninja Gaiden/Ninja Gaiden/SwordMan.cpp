#include"SwordMan.h"
#include"Textures.h"
SwordMan::SwordMan()
{
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void SwordMan::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + SWORDMAN_BBOX_W;
	bottom = y + SWORDMAN_BBOX_H;
}
void SwordMan::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	textures->Add(ID_TEX_ENEMY, L"Enemies\\Enemies.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 texSMan = textures->Get(ID_TEX_ENEMY);

	sprites->Add(30000, 848, 5, 872, 45, texSMan);//Move right
	sprites->Add(30001, 818, 5, 842, 45, texSMan);
	sprites->Add(30002, 794, 5, 817, 45, texSMan);

	sprites->Add(30010, 4, 5, 28, 45, texSMan);
	sprites->Add(30011, 34, 5, 58, 45, texSMan);
	sprites->Add(30012, 59, 5, 82, 45, texSMan); //Sman BB chuan 24x40

	ani = new CAnimation(100);
	ani->Add(30000);
	ani->Add(30001);
	ani->Add(30002);
	animations->Add(400, ani);

	ani = new CAnimation(100);
	ani->Add(30010);
	ani->Add(30011);
	ani->Add(30012);
	animations->Add(401, ani);

	/*AddAnimation(400);
	AddAnimation(401);*/
	sprites->Add(30090, 6, 51, 29, 90, texSMan);
	sprites->Add(30091, 36, 51, 59, 90, texSMan);
	sprites->Add(30092, 59, 51, 82, 90, texSMan);
	ani = new CAnimation(100);
	ani->Add(30090);
	ani->Add(30091);
	ani->Add(30092);
	animations->Add(800, ani);//1 - left


	sprites->Add(30100, 847, 51, 870, 90, texSMan);
	sprites->Add(30101, 817, 51, 840, 90, texSMan);
	sprites->Add(30102, 794, 51, 817, 90, texSMan);
	ani = new CAnimation(100);
	ani->Add(30100);
	ani->Add(30101);
	ani->Add(30102);
	animations->Add(900, ani);//0 - right

	AddAnimation(900);
	AddAnimation(800);
	//Dead effect
	LPDIRECT3DTEXTURE9 texDEffect = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30080, 354, 229, 402, 277, texDEffect);
	ani = new CAnimation(100);
	ani->Add(30080);
	animations->Add(700, ani);
	AddAnimation(700);//2



}
void SwordMan::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	float RyuX, RyuY;
	Ryu::GetInstance()->GetPosition(RyuX, RyuY);
	if (IsRenderOke == false)//Kiem tra dieu kien khi Ryu Tien den canh man hinh moi render
	{
		if (RyuX + 256 > x)
			IsRenderOke = true;
		else
			return;
	}

	CGameObject::Update(dt);
	//fall down
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
void SwordMan::Render()
{
	float RyuX, RyuY;
	Ryu::GetInstance()->GetPosition(RyuX, RyuY);
	if (IsRenderOke == false)//Kiem tra dieu kien khi Ryu Tien den canh man hinh moi render
	{
		if (RyuX + 256 > x)
			IsRenderOke = true;
		else
			return;
	}
		D3DXVECTOR3 P = CGameObject::ConverObjectToViewPort();
		int ani;
		if (IsAble == false)
		{
			ani = 2;
			IsDie = true;
			animations[ani]->Render(P.x, P.y);
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
}
SwordMan::~SwordMan()
{

}
void SwordMan::CreateSMan(float x, float y, int direcint, int A, int B)
{
	edgeA = A;
	edgeB = B;
	direction = direcint;
	if (direction > 0)
	{
		vx = SWORDMAN_SPEED;
	}
	else
	{
		vx = -SWORDMAN_SPEED;
	}
	SetPosition(x, y);
}
void SwordMan::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void SwordMan::Iskill()
{
	IsAble = false;
}