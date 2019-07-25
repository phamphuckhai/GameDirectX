#pragma once
#include "GameObject.h"
#include "Global.h"


class Weapon : public CGameObject
{
protected:
	LPGAMEOBJECT Obj;
public:
	void SetObj(LPGAMEOBJECT obj) { this->Obj = obj; }
	void LoadResource();
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};
