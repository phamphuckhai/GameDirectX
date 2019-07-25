#pragma once
#pragma once
#include "d3dx9.h"
#include "Global.h"
#include <string>
#include "Ryu.h"
#include"Game.h"
#include <iostream>
#include"Textures.h"

using namespace std;
class Imformation  
{

private:
	static Imformation* m_instance;
	ID3DXFont *font;
	RECT rect;
	string Text;
	Imformation();
	int Gettime;
	int time;
	int index;
	int HPRyu, HPBOSS;
	vector<LPANIMATION> sprite;
public:
	static Imformation* GetInstance();
	~Imformation();

	void LoadResource();
	void Update(int hpryu, int hpboss=16);
	void render();
	void ResetTime();

};