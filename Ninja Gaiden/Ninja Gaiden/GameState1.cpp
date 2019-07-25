#include"GameState1.h"
GameState1::GameState1()
{
	Map* tilemap = Map::GetInstance();
	tilemap->LoadStage1();
	Grid *grid = Grid::GetInstance();
	grid->CreateGridStage1();
	
}
GameState1::~GameState1()
{

}
void GameState1::LoadResource()
{
	Grid *grid = Grid::GetInstance();
	Ground *ground = new Ground();
	ground->CreateGroundStage1();
	//Add SwordMan
	SwordMan *SMan = new SwordMan();

	SMan->CreateSMan(243, 170, -1, 50, 500);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(292, 170, -1, 50, 500);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(338, 170, -1, 50, 500);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(450, 170, -1, 50, 500);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1285, 73, -1, 1280, 1375);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1443, 73, -1, 1440, 1461);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1475, 41, -1, 1472, 1510);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1874, 170, -1, 1794, 1990);
	grid->AddObject(SMan);

	SMan = new SwordMan();
	SMan->CreateSMan(1955, 170, -1, 1794, 1990);
	grid->AddObject(SMan);
	//Panther
	Panther *Pther = new Panther();

	Pther->CreatePther(243, 64, 1, 50, 500);
	grid->AddObject(Pther);

	Pther = new Panther();
	Pther->CreatePther(901, 64, -1, 0, 901);
	grid->AddObject(Pther);

	Pther = new Panther();
	Pther->CreatePther(935, 0, 1, 935, 935+1024);
	grid->AddObject(Pther);

	Pther = new Panther();
	Pther->CreatePther(1272, 64, -1, 1272-1024, 1272);
	grid->AddObject(Pther);
	//BUTTERFLY ID=0;
	Bird *bird = new Bird();

	bird->CreateBird(330, 171,0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(426, 171, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(570, 171, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(634, 161, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(763, 151, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(1147, 171, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(1179, 141, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(1323, 121, 0);
	grid->AddObject(bird);

	bird = new Bird();
	bird->CreateBird(1850, 171, 0);
	grid->AddObject(bird);		
	//Banshee
	Banshee *bs = new Banshee();
	bs->CreateBS(804, 106, -1, 801, 810);
	grid->AddObject(bs);
	//Machine gun guy
	MachineGunGuy *MGG = new MachineGunGuy();
	MGG->CreateMGG(1369,137,-1,1129,1387);
	grid->AddObject(MGG);
}
void GameState1::Update(DWORD dt)
{
	Ryu *ryu = Ryu::GetInstance();
	Camera* c = Camera::GetInstance();
	Imformation *im = Imformation::GetInstance();
	Grid::GetInstance()->Update(c, dt);
	im->Update(ryu->GetHp());
}
void GameState1::Render()
{
	Camera* c = Camera::GetInstance();
	Map* tilemap = Map::GetInstance();
	Imformation *im = Imformation::GetInstance();

	tilemap->LoadStage1();

	tilemap->Render(c);
	im->render();
	Grid::GetInstance()->Render(c);
}
