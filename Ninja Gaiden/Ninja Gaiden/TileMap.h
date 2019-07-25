#pragma once
#include<iostream>
#include<stdio.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<time.h>
#include<dinput.h>
#include"Textures.h"
#include"Camera.h"
#include"GameState.h"
class Map {
private:
	static Map *m_instance;
	Map();
	int InTile, InWidth, InHeight;//InWidth = tile tren hang , InHeight = tile tren cot 
	int **MatrixMap;
	LPDIRECT3DTEXTURE9 TileSet;
public:
	~Map();
	static Map* GetInstance();
	/*void render();*/
	D3DXVECTOR3 ConvertWorldToViewPort(D3DXVECTOR3 C, D3DXVECTOR3 Source, D3DXVECTOR3 Pos);
	void Render(Camera *C);
	void LoadStage1();
	void LoadStage2();
	void LoadStage3();
	int GetInWidth() { return InWidth; }
	int GetInHeight() { return InHeight; }

};
