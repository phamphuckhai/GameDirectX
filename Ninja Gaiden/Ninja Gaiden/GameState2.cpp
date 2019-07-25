#include"GameState2.h"
GameState2::GameState2()
{
	Map* tilemap = Map::GetInstance();
	tilemap->LoadStage2();
	Grid *grid = Grid::GetInstance();
	grid->CreateGridStage2();
	LoadResource();
	
}
GameState2::~GameState2()
{

}
void GameState2::LoadResource()
{

	Grid *grid = Grid::GetInstance();
	Ground *ground = new Ground();
	ground->CreateGroundStage2();
	Wall *wall = Wall::GetInstance();
	wall->CreateWallStage2();
	//Add SwordMan
	SwordMan *SMan = new SwordMan();

	SMan->CreateSMan(291, 106, -1, 258, 410);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(386, 106, -1, 258, 410);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(870, 105, -1, 865, 880);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1161, 137, -1, 1160, 1238);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1217, 137, -1, 1160, 1238);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1892, 41, -1, 1890, 1942);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(2962, 137, -1, 2945, 3040);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(514, 83, -1, 0, 514);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(643, 50, -1, 0, 729);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(2277, 147, -1, 2240, 2320);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(2673, 115, -1, 2661, 2709);
	grid->AddObject(SMan);
	//Panther
	Panther *Pther = new Panther();

	Pther->CreatePther(2729, 64, 1, 2729, 3040);
	grid->AddObject(Pther);
	//Bird
	//BUTTERFLY ID=0;
	Bird *bird = new Bird();

	bird->CreateBird(346, 128, 1);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(104, 105, 1);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(1389, 106, 1);
	grid->AddObject(bird);
	//Runner
	Runner *run = new Runner();
	run->CreateRunner(365, 137, -1,0, 555);
	grid->AddObject(run);

	run = new Runner();
	run->CreateRunner(1575, 75, -1, 1313, 1603);
	grid->AddObject(run);

	run = new Runner();
	run->CreateRunner(1657, 43, -1, 1313, 1603);
	grid->AddObject(run);

	run = new Runner();
	run->CreateRunner(1615, 41, 1, 1615, 1891);
	grid->AddObject(run);

	//Banshee
	Banshee *bs = new Banshee();
	bs->CreateBS(1009, 134, -1, 966, 1090);
	grid->AddObject(bs);

	bs = new Banshee();
	bs->CreateBS(1157, 41, -1, 1097, 1184);
	grid->AddObject(bs);
	//Artillery
	
}
void GameState2::Update(DWORD dt)
{
	

	Ryu *ryu = Ryu::GetInstance();
	Camera* c = Camera::GetInstance();
	Imformation *im = Imformation::GetInstance();
	Grid::GetInstance()->Update(c, dt);
	im->Update(ryu->GetHp());
}
void GameState2::Render()
{
	Camera* c = Camera::GetInstance();
	Map* tilemap = Map::GetInstance();
	Imformation *im = Imformation::GetInstance();

	tilemap->LoadStage2();

	tilemap->Render(c);
	im->render();
	Grid::GetInstance()->Render(c);
}
