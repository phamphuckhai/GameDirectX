#pragma once
#include<iostream>
#include"GameState.h"
#include"Camera.h"
#include"TileMap.h"
#include"Grid.h"
#include"GameState1.h"
#include"GameState2.h"
#include"GameState3.h"
class GameStateManager
{
private:

	static GameStateManager *m_instance;
	GameStateManager();
	GameState* gamestate;
	EnumGameState CurState;//State hien tai
public:
	void ChangeState();
	~GameStateManager();
	static GameStateManager *GetInstance();
	void LoadReSource();
	void Update(DWORD dt);
	void render();

};
