#pragma once
#include"GameObject.h"
#include"Global.h"
#include"Ryu.h"
#include"Imformation.h"

class Boss :public CGameObject
{
	
public:
	Boss();
	int time;
	bool IsRenderOke;
	
	~Boss();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	virtual void CreateBoss(float x, float y, int direc, int A = 0, int B = 0);
	virtual void Iskill();
	void GetHp(int &a);
};