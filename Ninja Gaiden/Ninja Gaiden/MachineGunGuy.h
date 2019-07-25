#pragma once
#include"GameObject.h"
#include"Ryu.h"
#include"Global.h"

class MachineGunGuy :public CGameObject
{
public:
	bool IsRenderOke;
	MachineGunGuy();
	~MachineGunGuy();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	virtual void CreateMGG(float x, float y, int direc, int A = 0, int B = 0);
	virtual void Iskill();
};