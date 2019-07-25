#pragma once
#pragma once
#include"GameObject.h"
#include"Camera.h"
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
#include "DeadEffect.h"
#include"Ryu.h"
using namespace std;
class Grid
{
	vector<LPGAMEOBJECT> ObjectAble; //Tat ca cac Object kha dung (nam trong viewport)
	vector<LPGAMEOBJECT> *Object;//Luu Object vao Grid tuong ung 
	static Grid* m_instance;
	float SizeGrid;//Hinh vuong co chieu dai = chieu rong = size
	float MapWidth, MapHeight;
	int NumGrid;//So Grid
	Grid();
public:
	~Grid();
	void SetGrid();
	static Grid* GetInstance();
	void AddObject(LPGAMEOBJECT Addo);
	void Update(Camera *C, DWORD dt);
	void Render(Camera *C);
	void ResetObjectDie();
	void CreateGridStage1();
	void CreateGridStage2();
	void CreateGridStage3();
};