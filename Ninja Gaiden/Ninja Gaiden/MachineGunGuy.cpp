#include"MachineGunGuy.h"
#include"Textures.h"
MachineGunGuy::MachineGunGuy()
{
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void MachineGunGuy::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + MGG_W;
	bottom = y + MGG_H;
}
void MachineGunGuy::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	textures->Add(3, L"Enemies\\Enemies.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 MGGuy = textures->Get(3);

	sprites->Add(30040, 756, 60, 772, 92, MGGuy);//Move right
	sprites->Add(30041, 734, 60, 749, 92, MGGuy);
	sprites->Add(30042, 701, 60, 725, 92, MGGuy);//Gun
	sprites->Add(30043, 669, 60, 689, 92, MGGuy);
	sprites->Add(30044, 652, 68, 660, 71, MGGuy);//Amo

	sprites->Add(30050, 104, 60, 120, 92, MGGuy);//Move left
	sprites->Add(30051, 127, 60, 142, 92, MGGuy);
	sprites->Add(30052, 151, 60, 175, 92, MGGuy);//Gun
	sprites->Add(30053, 187, 60, 207, 92, MGGuy);
	sprites->Add(30054, 216, 68, 224, 71, MGGuy);//Amo

	ani = new CAnimation(100);
	ani->Add(30040);
	ani->Add(30041);
	animations->Add(500, ani);

	ani = new CAnimation(100);
	ani->Add(30050);
	ani->Add(30051);
	animations->Add(501, ani);

	AddAnimation(500);
	AddAnimation(501);




}
void MachineGunGuy::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
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
void MachineGunGuy::Render()
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
MachineGunGuy::~MachineGunGuy()
{

}
void MachineGunGuy::CreateMGG(float x, float y, int direcint, int A, int B)
{
	edgeA = A;
	edgeB = B;
	direction = direcint;
	if (direction > 0)
	{
		vx = MGG_SPEED;
	}
	else
	{
		vx = -MGG_SPEED;
	}
	SetPosition(x, y);
}
void MachineGunGuy::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void MachineGunGuy::Iskill()
{
	IsAble = false;
}
