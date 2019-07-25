#pragma once
#pragma once
#include"GameObject.h"
#include"Global.h"
#include"Ryu.h"
class Bird :public CGameObject
{
public:
	bool IsRenderOke;
	Bird();
	~Bird();
	int Type;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();

	virtual void ResetObject();
	void LoadResource();
	void CreateBird(float x, float y, int ani);
	virtual void Iskill();
};