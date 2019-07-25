#pragma once
#include"GameObject.h"
#include"Brick.h"
#include"Ryu.h"
#include"Global.h"

class SwordMan :public CGameObject
{
public:
	bool IsRenderOke;
	SwordMan();
	~SwordMan();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	virtual void CreateSMan(float x, float y, int direc, int A=0, int B=0);
	virtual void Iskill();
};