#include"Banshee.h"
#include"Textures.h"
Banshee::Banshee()
{
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void Banshee::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + BANSHEE_W;
	bottom = y + BANSHEE_H;
}
void Banshee::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	textures->Add(ID_TEX_ENEMY, L"Enemies\\Enemies.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 texBanshe = textures->Get(ID_TEX_ENEMY);

	sprites->Add(60000, 527, 7, 551, 50, texBanshe);//Move right
	sprites->Add(60001, 498, 7, 522, 50, texBanshe);
	sprites->Add(60002, 471, 7, 495, 50, texBanshe);

	sprites->Add(60010, 325, 7, 349, 50, texBanshe);
	sprites->Add(60011, 354, 7, 378, 50, texBanshe);
	sprites->Add(60012, 389, 7, 413, 45, texBanshe); //Sman BB chuan 24x40

	ani = new CAnimation(100);
	ani->Add(60000);
	ani->Add(60001);
	ani->Add(60002);
	animations->Add(3000, ani);

	ani = new CAnimation(100);
	ani->Add(60010);
	ani->Add(60011);
	ani->Add(60012);
	animations->Add(3001, ani);

	AddAnimation(3000);
	AddAnimation(3001);

	//Dead effect
	LPDIRECT3DTEXTURE9 texDEffect = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30080, 354, 229, 402, 277, texDEffect);
	ani = new CAnimation(100);
	ani->Add(30080);
	animations->Add(700, ani);
	AddAnimation(700);//2



}
void Banshee::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
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
void Banshee::Render()
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
Banshee::~Banshee()
{

}
void Banshee::CreateBS(float x, float y, int direcint, int A, int B)
{
	edgeA = A;
	edgeB = B;
	direction = direcint;
	if (direction > 0)
	{
		vx = BANSHEE_SPEED;
	}
	else
	{
		vx = -BANSHEE_SPEED;
	}
	SetPosition(x, y);
}
void Banshee::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void Banshee::Iskill()
{
	IsAble = false;
}