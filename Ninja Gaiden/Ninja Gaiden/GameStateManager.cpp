#include"GameStateManager.h"
GameStateManager* GameStateManager::m_instance = NULL;
GameStateManager* GameStateManager::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new GameStateManager();
	return m_instance;
}
GameStateManager::GameStateManager()
{
	this->CurState = GAME_STATE_1;
	gamestate = new GameState1();

}
GameStateManager::~GameStateManager()
{

}
void GameStateManager::LoadReSource()
{
	
	gamestate->LoadResource();
}
void GameStateManager::Update(DWORD dt)
{
	Ryu* ryu = Ryu::GetInstance();
	Map *map = Map::GetInstance();
	float x, y;
	ryu->GetPosition(x, y);
	if (x >= map->GetInWidth() * 32 - 32)
	{
		ChangeState();
	}
	gamestate->Update(dt);
}
void GameStateManager::render()
{
	gamestate->Render();
}
void GameStateManager::ChangeState()
{
	if (CurState == GAME_STATE_1)
	{
		Ryu::GetInstance()->ResetObject();
		CurState = GAME_STATE_2;
		gamestate = new GameState2();
		
	}
	else if (CurState == GAME_STATE_2)
	{
		Ryu::GetInstance()->ResetObject();
		CurState = GAME_STATE_3;
		gamestate = new GameState3();
	}
	else {
		//do nothing 
	}
}