#pragma once
#include"GameState.h"
class GameState1:public GameState
{
public:
	GameState1();
	~GameState1();
	virtual void LoadResource();
	virtual void Update(DWORD dt);
	virtual void Render();
};