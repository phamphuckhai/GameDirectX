#pragma once
#include "GameObject.h"
#include "Global.h"
#include"Grid.h"
#include"Brick.h"
#include"SwordMan.h"
#include"Katana.h"
#include"Wall.h"
#include"Bird.h"
#include"Runner.h"
#include"Boss.h"
#include"Banshee.h"
#include"MachineGunGuy.h"
#include"Artillery.h"
class Ryu : public CGameObject
{
private:
	int score;
	static Ryu *m_instance;
	int level;
	int untouchable;
	DWORD untouchable_start;
	bool IsJump;
	bool IsFighting;
	bool IsHurt;
	bool IsClimb;
	float TimeFighting, TimeHurt;
	
public:
	Ryu();
	static Ryu *GetInstance();
	int countmisc;
	void LoadResource();
	
	~Ryu();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	virtual void ResetObject();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void ReturnGround();
	int GetHp();
	void GetScore(int &sc) { sc = this->score; };
};