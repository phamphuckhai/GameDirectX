#pragma once
#include "GameObject.h"
#include"Grid.h"
class Wall:public CGameObject 
{
	static Wall* m_instance;
	Wall();
public:
	static Wall* GetInstance();
	~Wall();
	void LoadResource();
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	void CreateWallStage2();
	void CreateWallStage3();
};