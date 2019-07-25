#pragma once
#include "GameObject.h"
#include "Global.h"


class CBrick : public CGameObject
{
public:
	void LoadResource();
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};
