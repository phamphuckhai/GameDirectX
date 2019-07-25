#include"Artillery.h"
#include"Textures.h"
Artillery::Artillery()
{
	IsAble = true;
	IsDie = false;
	LoadResource();
	IsRenderOke = false;
}

void Artillery::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + SWORDMAN_BBOX_W;
	bottom = y + SWORDMAN_BBOX_H;
}
void Artillery::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	textures->Add(ID_TEX_ENEMY, L"Enemies\\Enemies.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 texE = textures->Get(ID_TEX_ENEMY);

	sprites->Add(70000, 101, 108, 125, 133, texE);//Move right


	ani = new CAnimation(100);
	ani->Add(70000);
	animations->Add(4000, ani);

	

	AddAnimation(4000);

	//Dead effect
	LPDIRECT3DTEXTURE9 texDEffect = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30080, 354, 229, 402, 277, texDEffect);
	ani = new CAnimation(100);
	ani->Add(30080);
	animations->Add(700, ani);
	AddAnimation(700);//2



}
void Artillery::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
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

	
}
void Artillery::Render()
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
Artillery::~Artillery()
{

}
void Artillery::CreateAL(float x, float y)
{

	SetPosition(x, y);
}
void Artillery::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void Artillery::Iskill()
{
	IsAble = false;
}