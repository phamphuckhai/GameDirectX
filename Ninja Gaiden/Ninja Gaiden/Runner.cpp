#include"Runner.h"
#include"Textures.h"
Runner::Runner()
{
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void Runner::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + RUNNER_W;
	bottom = y + RUNNER_H;
}
void Runner::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	LPDIRECT3DTEXTURE9 TexRunner = textures->Get(ID_TEX_ENEMY);

	sprites->Add(30060, 616, 62, 632, 94, TexRunner);//Move right
	sprites->Add(30061, 587, 62, 603, 94, TexRunner);

	sprites->Add(30070, 244, 62, 260, 94, TexRunner);//Move left
	sprites->Add(30071, 273, 62, 289, 94, TexRunner);

	ani = new CAnimation(100);
	ani->Add(30060);
	ani->Add(30061);
	animations->Add(600, ani);

	ani = new CAnimation(100);
	ani->Add(30070);
	ani->Add(30071);
	animations->Add(601, ani);

	AddAnimation(600);
	AddAnimation(601);

	SetPosition(512.0f, 121.0f);
	//Dead effect
	LPDIRECT3DTEXTURE9 texDEffect = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30080, 354, 229, 402, 277, texDEffect);
	ani = new CAnimation(100);
	ani->Add(30080);
	animations->Add(700, ani);
	AddAnimation(700);//2



}
void Runner::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	float RyuX, RyuY;
	Ryu::GetInstance()->GetPosition(RyuX, RyuY);
	//Hon nua~ man hinh moi load no ra hoac xuat hien phia sau ryu 
	if (IsRenderOke == false)
	{
		if ((direction == -1 && (RyuX + 256 > x)) || ((direction == 1) && ((RyuX - 170) > x)))
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
				if (ny != 0)
					if (vy > 0)
						vy = 0;
			}
		}

	}
	if (direction == -1)
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
void Runner::Render()
{
	float RyuX, RyuY;
	Ryu::GetInstance()->GetPosition(RyuX, RyuY);//Hon nua~ man hinh moi render
	if (IsRenderOke == false)
	{
		if ((direction == -1 && (RyuX + 256 > x)) || ((direction == 1) && ((RyuX - 170) > x)))
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
Runner::~Runner()
{

}
void Runner::CreateRunner(float x, float y, int direcint, int A, int B)
{
	edgeA = A;
	edgeB = B;
	direction = direcint;
	if (direction > 0)
	{
		vx = RUNNER_SPEED;
	}
	else
	{
		vx = -RUNNER_SPEED;
	}
	SetPosition(x, y);
}
void Runner::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void Runner::Iskill()
{
	IsAble = false;
}