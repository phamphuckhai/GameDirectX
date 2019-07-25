#include"Panther.h"
#include"Textures.h"
Panther::Panther()
{
	IsJump = false;
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void Panther::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y - 15;
	right = x + PANTHER_BBOX_W;
	bottom = y + PANTHER_BBOX_H;
}
void Panther::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;
	LPDIRECT3DTEXTURE9 texPanther = textures->Get(ID_TEX_ENEMY);

	sprites->Add(30020, 797, 175, 828, 191, texPanther);//Move right
	sprites->Add(30021, 837, 175, 868, 191, texPanther);

	sprites->Add(30030, 48, 175, 79, 191, texPanther);//Move left
	sprites->Add(30031, 8, 175, 39, 191, texPanther);

	ani = new CAnimation(100);
	ani->Add(30020);
	ani->Add(30021);
	animations->Add(500, ani);

	ani = new CAnimation(100);
	ani->Add(30030);
	ani->Add(30031);
	animations->Add(501, ani);

	AddAnimation(500);
	AddAnimation(501);
	AddAnimation(700);//dead effect

	SetPosition(0.0f, 140.0f);


}
void Panther::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	float RyuX, RyuY;
	Ryu::GetInstance()->GetPosition(RyuX, RyuY);
	//Hon nua~ man hinh moi load no ra hoac xuat hien phia sau ryu 
	if (IsRenderOke == false)
	{
		if ((direction == -1 && (RyuX + 256 > x)) || ((direction == 1) && ((RyuX-170) > x)))
			IsRenderOke = true;
		else
			return;
	}

	//if (vy == 0)
	//{
	//	IsJump = true;
	//}
	if(vy==0)
		vy = -PANTHER_JUMP;
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
				if (ny != 0)
					if(vy>0)
					vy = 0;
			}
		}

	}
	if (direction==-1)
	{
		if (x < edgeA) {
			x = edgeB;
			y = 64;
		}
	}
	if (direction == 1)
	{
		if (x > edgeB) {
			x = edgeA;
			y = 64;
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}
void Panther::Render()
{
	float RyuX, RyuY;
	Ryu::GetInstance()->GetPosition(RyuX, RyuY);//Hon nua~ man hinh moi render
	if (IsRenderOke == false)
	{
		if ((direction == -1 && (RyuX + 256 > x)) || ((direction == 1) && ((RyuX-170) > x)))
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
Panther::~Panther()
{

}
void Panther::CreatePther(float x, float y, int direcint, int A, int B)
{
	edgeA = A;
	edgeB = B;
	direction = direcint;
	if (direction > 0)
	{
		vx = PANTHER_SPEED;
		vy = -PANTHER_JUMP;
	}
	else
	{
		vx = -PANTHER_SPEED;
		vy = -PANTHER_JUMP;
	}
	SetPosition(x, y);
}
void Panther::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void Panther::Iskill()
{
	IsAble = false;
}