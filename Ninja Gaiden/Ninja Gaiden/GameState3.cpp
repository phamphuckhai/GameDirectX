#include"GameState3.h"
GameState3::GameState3()
{
	Map* tilemap = Map::GetInstance();
	tilemap->LoadStage3();
	Grid *grid = Grid::GetInstance();
	grid->CreateGridStage3();
	LoadResource();

}
GameState3::~GameState3()
{

}
void GameState3::LoadResource()
{

	Grid *grid = Grid::GetInstance();
	Ground *ground = new Ground();
	ground->CreateGroundStage3();
	Boss *bos = new Boss();
	bos->CreateBoss(64, 64, 1, 64, 448);
	grid->AddObject(bos);
}
void GameState3::Update(DWORD dt)
{

	Ryu *ryu = Ryu::GetInstance();
	Camera* c = Camera::GetInstance();
	Grid::GetInstance()->Update(c, dt);

	
}
void GameState3::Render()
{
	Camera* c = Camera::GetInstance();
	Map* tilemap = Map::GetInstance();
	Imformation *im = Imformation::GetInstance();

	tilemap->LoadStage3();

	tilemap->Render(c);
	im->render();
	Grid::GetInstance()->Render(c);
}
