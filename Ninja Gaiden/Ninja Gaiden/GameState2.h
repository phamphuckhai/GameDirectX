#pragma once
#include"GameState.h"
class GameState2 :public GameState
{
public:
	GameState2();
	~GameState2();
	virtual void LoadResource();
	virtual void Update(DWORD dt);
	virtual void Render();
};