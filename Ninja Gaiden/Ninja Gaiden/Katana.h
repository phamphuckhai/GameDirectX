#pragma once
#include "weapons.h"
#include "Ryu.h"
#include "Global.h"


class Katana : public Weapon
{
	Katana();
	~Katana();
	static Katana* m_instance;
public:
	static Katana* GetInstance();
	void LoadResource();
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	bool IsCollision(LPGAMEOBJECT obj);
};
