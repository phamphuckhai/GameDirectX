#include "Imformation.h"

Imformation* Imformation::m_instance = NULL;
Imformation* Imformation::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Imformation();
	return m_instance;
}
Imformation::Imformation()
{
	HPRyu = HPBOSS = 16;
	index = 1;
	Gettime = GetTickCount();
	font = NULL;
	LoadResource();
	time = 150;
}
Imformation::~Imformation()
{
	if (font != NULL)
		font->Release();
}
void Imformation::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;
	textures->Add(ID_TEX_NOHP, L"Mics\\NoHP.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_HP, L"Mics\\HP.png", D3DCOLOR_XRGB(255, 0, 255));
	LPDIRECT3DTEXTURE9 texNohp = textures->Get(ID_TEX_NOHP);
	LPDIRECT3DTEXTURE9 texHp = textures->Get(ID_TEX_HP);
	sprites->Add(50000, 0, 0, 10, 20, texHp);
	sprites->Add(50001, 0, 0, 10, 20, texNohp);

	ani = new CAnimation(100);
	ani->Add(50000);
	sprite.push_back(ani);

	ani = new CAnimation(100);
	ani->Add(50001);
	sprite.push_back(ani);
	font = NULL;
	AddFontResourceEx(FONT, FR_PRIVATE, NULL);
	HRESULT result = D3DXCreateFont(CGame::GetInstance()->GetDirect3DDevice(), 20, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Ninja Gaiden (NES)", &font);
	SetRect(&rect, 0, 0, SCREEN_WIDTH, 64);
	Text = "SCORE-000000 STAGE-3-1\n";
	Text += "TIMER-       NINJA	    \n";
	Text += "P-02         ENEMY	    \n";
}
void Imformation::Update(int hpryu, int hpboss)
{
	HPRyu = hpryu;
	HPBOSS = hpboss;
	if (GetTickCount() - Gettime > 1000)
	{
		time -= 1;
		Gettime = GetTickCount();
	}
	std::string Tstring = std::to_string(this->time);
	std::string Idx = std::to_string(this->index);
	int tmp;
	Ryu::GetInstance()->GetScore(tmp);
	std::string score = std::to_string(tmp);
	Text = "SCORE-"+ score +" STAGE-3-"+ Idx +"\n";
	Text += "TIMER-"+ Tstring +" NINJA	    \n";
	Text += "P-02			      ENEMY	    \n";
}
void Imformation::render()
{
	for (int i = 0; i < 16; i++)
		if (i < HPRyu)
			sprite[0]->Render(305 + 12 * i, 23);
		else
			sprite[1]->Render(305 + 12 * i, 23);
	for (int i = 0; i < 16; i++)
		if (i < HPBOSS)
			sprite[0]->Render(305 + 12 * i, 45);
		else
			sprite[1]->Render(305 + 12 * i, 45);
	font->DrawTextA(NULL, Text.c_str(), -1, &rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
}
void Imformation::ResetTime()
{
	time = 150;
	index++;
}


