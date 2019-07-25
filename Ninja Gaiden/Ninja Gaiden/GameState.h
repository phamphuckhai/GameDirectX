#pragma once
#include"Ryu.h"
#include"TileMap.h"
#include"Grid.h"
#include"Ground.h"
#include"Imformation.h"
#include"SwordMan.h"
#include"Panther.h"
#include"dxsound.h"
#include"Wall.h"
#include"Bird.h"
#include"Runner.h"
#include"Boss.h"
#include"Banshee.h"
#include"MachineGunGuy.h"
//Game Sate la class thuan ao
class GameState
{
protected:

public:
	GameState();
	~GameState();
	virtual void LoadResource() = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
};