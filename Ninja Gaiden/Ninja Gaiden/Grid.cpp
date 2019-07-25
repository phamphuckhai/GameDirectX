#include"grid.h"
Grid* Grid::m_instance = NULL;
Grid* Grid::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Grid();
	return m_instance;
}
Grid::Grid()
{
	//Do the gioi game theo chieu cao tuong doi nho nen dung 1 row Grid
/*SizeGrid la hinh vuong va chon SizeGrid bang voi Map Height*/
	
}
void Grid::CreateGridStage1()
{
	SizeGrid = 256;//Do ta mac dinh SCREEN_HEIGHT luon bang MAP HEIGHT
	NumGrid = 2048 / SizeGrid;
	Object = new vector<LPGAMEOBJECT>[8];
}
void Grid::CreateGridStage2()
{

	SizeGrid = 256;//Do ta mac dinh SCREEN_HEIGHT luon bang MAP HEIGHT
	NumGrid = 3072 / SizeGrid;
	Object = new vector<LPGAMEOBJECT>[12];
}
void Grid::CreateGridStage3()
{

	SizeGrid = 256;//Do ta mac dinh SCREEN_HEIGHT luon bang MAP HEIGHT
	NumGrid = 512 / SizeGrid;
	Object = new vector<LPGAMEOBJECT>[2];
}
Grid::~Grid()
{
	delete[] Object;
}
void Grid::SetGrid()
{

}
void Grid::AddObject(LPGAMEOBJECT Addo)
{
	float x, y;
	Addo->GetPosition(x, y);
	int i = x / SizeGrid;
	Object[i].push_back(Addo);
}

void Grid::Render(Camera *C)
{
	int i = C->ConvertCameraPos().x / SizeGrid;
	int j = (C->ConvertCameraPos().x + SCREEN_WIDTH) / SizeGrid;
	if (NumGrid == 2)
		j = 1;
	Ryu::GetInstance()->Render();
	for (int k = i; k <= j; k++)
	{
		for (int h = 0; h < Object[k].size(); h++) //Render Object trong luoi
		{
			if (Object[k][h]->IsDie == false)
				Object[k][h]->Render();
		}
	}

}
void Grid::Update(Camera *C, DWORD dt)
{
	int i = C->ConvertCameraPos().x / SizeGrid;//Tim Grid bat dau
	int j = (C->ConvertCameraPos().x + SCREEN_WIDTH) / SizeGrid;//Tim Grid ket thuc
	if (NumGrid == 2)
		j = 1;
	//Reset doi tuong (IsDie==false) ngoai` camera
	//for (int k = 0; k < i; k++)
	//{
	//	for (int h = 0; h < Object[k].size(); h++)
	//	{
	//		Object[k][h]->IsDie = false;
	//	}

	//}
	//for (int k = j+1; k < NumGrid; k++)
	//{
	//	for (int h = 0; h < Object[k].size(); h++)
	//	{
	//		Object[k][h]->IsDie = false;
	//	}

	//}
	//Update luoi nhung doi tuong co kha nang tuong tac
	ObjectAble.push_back(Ryu::GetInstance());
	for (int k = i; k <= j; k++)
	{
		for (int h = 0; h < Object[k].size(); h++) {//Chi co Object trong i vs j co kha nang colision
			if (Object[k][h]->IsDie == false)
				ObjectAble.push_back(Object[k][h]);
		}
	}
	Ryu::GetInstance()->Update(dt, &ObjectAble);
	for (int k = i; k <= j; k++)
	{
		for (int h = 0; h < Object[k].size(); h++)
			Object[k][h]->Update(dt, &ObjectAble); //Update
	}
	ObjectAble.clear();
}

void Grid::ResetObjectDie()
{
	for (int k = 0; k < NumGrid; k++)
	{
		for (int h = 0; h < Object[k].size(); h++) 
		{
			Object[k][h]->IsAble=true;
			Object[k][h]->IsDie = false;
		}
	}
}