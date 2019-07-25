#include"DeadEffect.h"
DeadEffect::DeadEffect()
{
	LoadResource();
}
DeadEffect::~DeadEffect()
{

}
void DeadEffect::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	LPDIRECT3DTEXTURE9 texDEffect = textures->Get(ID_TEX_ENEMY);

	sprites->Add(30080, 354, 229, 402, 277, texDEffect);

	ani = new CAnimation(100);
	ani->Add(30080);
	animations->Add(700, ani);

	AddAnimation(700);
}
void DeadEffect::ResetEffect(LPGAMEOBJECT obj)
{

}
void DeadEffect::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
}
void DeadEffect::Render(LPGAMEOBJECT obj)
{
		/*D3DXVECTOR3 p(0, 0, 0);
		int ani;
		ani = 0;
		p = obj->ConverObjectToViewPort();
	//	animations[ani]->Render(p.x, p.y);*/
	//LoadResource();
	//D3DXVECTOR3 P(0, 0, 0);
	//animations[2]->Render(P.x, P.y);
	//RenderBoundingBox();
}
void DeadEffect::Render()
{
}
void DeadEffect::Deactivate()
{
}