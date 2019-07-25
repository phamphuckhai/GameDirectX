#pragma once
#include"GameObject.h"
#include"Ryu.h"
#include"Global.h"

class Artillery :public CGameObject
{
public:
	bool IsRenderOke;
	Artillery();
	~Artillery();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	virtual void CreateAL(float x, float y);
	virtual void Iskill();
};
