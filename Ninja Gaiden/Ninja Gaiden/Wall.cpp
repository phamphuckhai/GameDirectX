#include"Wall.h"
#include"Brick.h"
Wall* Wall::m_instance = NULL;
Wall* Wall::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Wall();
	return m_instance;
}
Wall::Wall()
{
}

Wall::~Wall()
{
}


void Wall::LoadResource()
{

}

void Wall::Render()
{
	/*RenderBoundingBox();*/
}

void Wall::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	r = x + BRICK_BBOX_WIDTH; //BBox = brick
	b = y + BRICK_BBOX_HEIGHT;
}
void Wall::CreateWallStage2()
{
	Grid *grid = Grid::GetInstance();

	for (int i = 0; i < 1; i++)
	{
		Wall *brick = new Wall();
		brick->SetPosition(1088 + 16 + i * 16.0f, 120);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1088 + 16 + i * 16.0f, 136);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1088 + 16 + i * 16.0f, 152);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1088 + 16 + i * 16.0f, 168);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1088 + 16 + i * 16.0f, 184);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1088 + 16 + i * 16.0f, 300);
		grid->AddObject(brick);
	}
	for (int i = 0; i < 1; i++)
	{
		Wall *brick = new Wall();
		brick->SetPosition(1890+16 + i * 16.0f, 120);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1890 + 16 + i * 16.0f, 136);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1890 + 16 + i * 16.0f, 152);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1890 + 16 + i * 16.0f, 168);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1890 + 16 + i * 16.0f, 184);
		grid->AddObject(brick);

		brick = new Wall();
		brick->SetPosition(1890 + 16 + i * 16.0f, 300);
		grid->AddObject(brick);
	}
}
void Wall::CreateWallStage3()
{
	
}