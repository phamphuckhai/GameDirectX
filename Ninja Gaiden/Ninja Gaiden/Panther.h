#pragma once
#include"GameObject.h"
#include"Brick.h"
#include"Ryu.h"
#include"Global.h"

class Panther :public CGameObject
{
public:
	bool IsJump;
	bool IsRenderOke;
	Panther();
	~Panther();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	virtual void CreatePther(float x, float y, int direc, int A = 0, int B = 0);
	virtual void Iskill();
};