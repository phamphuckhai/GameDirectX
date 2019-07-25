#pragma once
#include "GameObject.h"
#include "Global.h"


class DeadEffect:public CGameObject
{
	
public:
	DeadEffect();
	~DeadEffect();
	int time;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Render();
	virtual void LoadResource();
	void ResetEffect(LPGAMEOBJECT obj);
	void Render(LPGAMEOBJECT obj);
	void Deactivate();
};
