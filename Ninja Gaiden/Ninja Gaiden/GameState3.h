#pragma once
#include"GameState.h"
class GameState3 :public GameState
{
public:
	GameState3();
	~GameState3();
	virtual void LoadResource();
	virtual void Update(DWORD dt);
	virtual void Render();
};