#pragma once
#include"GameObject.h"
#include"Global.h"
#include"Ryu.h"

class Banshee :public CGameObject
{
public:

	bool IsRenderOke;
	Banshee();
	~Banshee();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	virtual void CreateBS(float x, float y, int direc, int A = 0, int B = 0);
	virtual void Iskill();
};