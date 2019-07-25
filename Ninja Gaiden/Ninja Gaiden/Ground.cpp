#include"Ground.h"
#include"Brick.h"
Ground::Ground()
{
}

Ground::~Ground()
{
}

void Ground::CreateGroundStage1()
{
	Grid *grid = Grid::GetInstance();
	for (int i = 0; i < 34; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(0 + i * 16.0f, 215);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 2; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(577 + i * 16.0f, 215);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(641 + i * 16.0f, 215);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(705 + i * 16.0f, 215);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(769 + i * 16.0f, 215);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(800 + i * 16.0f, 183);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(1217 + i * 16.0f, 151);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(1409 + i * 16.0f, 183);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(1441 + i * 16.0f, 151);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 8; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(833 + i * 16.0f, 151);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 18; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1121 + i * 16.0f, 215);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 6; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1281 + i * 16.0f, 151);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 4; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1025 + i * 16.0f, 215);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1473 + i * 16.0f, 119);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 1; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1601 + i * 16.0f, 215);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1665 + i * 16.0f, 215);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(1729 + i * 16.0f, 215);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 16; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1793 + i * 16.0f, 215);
		grid->AddObject(brick);
	}
}
void Ground::CreateGroundStage2()
{
	Grid *grid = Grid::GetInstance();

	for (int i = 0; i < 16; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(0 + i * 16.0f, 216);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 10; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(257 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(418 + i * 16.0f, 151);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(577 + i * 16.0f, 120);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1602 + i * 16.0f, 120);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2721 + i * 16.0f, 151);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 2; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(802 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(865 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(929 + i * 16.0f, 151);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1826 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1985 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1058 + i * 16.0f, 151);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1857 + i * 16.0f, 151);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 8; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(961 + i * 16.0f, 216);
		grid->AddObject(brick);


		brick = new CBrick();
		brick->SetPosition(1578 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2946 + i * 16.0f, 216);
		grid->AddObject(brick);
	}

	for (int i = 0; i < 6; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1160 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2050 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2146 + i * 16.0f, 151);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2241 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2402 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2497 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1090 + i * 16.0f, 120);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1218 + i * 16.0f, 120);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 4; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1282 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1379 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1475 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(1890 + i * 16.0f, 120);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2337 + i * 16.0f, 183);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2594 + i * 16.0f, 216);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(2658 + i * 16.0f, 183);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 18; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(1314 + i * 16.0f, 151);
		grid->AddObject(brick);
	}

}
void Ground::CreateGroundStage3()
{
	Grid *grid = Grid::GetInstance();
	for (int i = 0; i < 32; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(0 + i * 16.0f, 226);
		grid->AddObject(brick);
	}
	/*for (int i = 0; i < 1; i++)
	{
		CBrick *brick = new CBrick();
		brick->SetPosition(34 + i * 16.0f, 218);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(34 + i * 16.0f, 212);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(34 + i * 16.0f, 196);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(34 + i * 16.0f, 180);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(34 + i * 16.0f, 164);
		grid->AddObject(brick);

		brick = new CBrick();
		brick->SetPosition(34 + i * 16.0f, 148);
		grid->AddObject(brick);
	}*/
}