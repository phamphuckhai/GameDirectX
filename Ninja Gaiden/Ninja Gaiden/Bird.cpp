#include"Bird.h"
#include"Textures.h"
Bird::Bird()
{
	IsRenderOke = false;
	IsAble = true;
	IsDie = false;
	LoadResource();
}

void Bird::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + Bird_W;
	bottom = y + Bird_H;
}
void Bird::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	textures->Add(ID_TEX_ENEMY_2, L"Enemies\\Enemies2.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 texBird = textures->Get(ID_TEX_ENEMY_2);

	sprites->Add(40010, 83, 136, 98, 150, texBird);//bUTTERFLY
	sprites->Add(40011, 98, 136, 113, 150, texBird);

	sprites->Add(40020, 118, 133, 134, 148, texBird);
	sprites->Add(30021, 139, 135, 155, 150, texBird); //BIRD

	ani = new CAnimation(100);
	ani->Add(40010);
	ani->Add(40011);
	animations->Add(2000, ani);

	ani = new CAnimation(100);
	ani->Add(40020);
	ani->Add(30021);
	animations->Add(2001, ani);

	

	AddAnimation(2000);//0
	AddAnimation(2001);//1
	//Dead effect
	LPDIRECT3DTEXTURE9 texDEffect = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30080, 354, 229, 402, 277, texDEffect);
	ani = new CAnimation(100);
	ani->Add(30080);
	animations->Add(700, ani);
	AddAnimation(700);



}
void Bird::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	
}
void Bird::Render()
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
		
		IsDie = true;
		//Update Items
	}
	else
	{
		ani = Type;
		animations[ani]->Render(P.x, P.y);
		/*RenderBoundingBox();*/
	}
}
Bird::~Bird()
{

}
void Bird::CreateBird(float x, float y,int ani)
{
	SetPosition(x, y);
	Type = ani;
	
}
void Bird::ResetObject()
{
	IsAble = true;
	IsDie = false;

}
void Bird::Iskill()
{
	IsAble = false;
}