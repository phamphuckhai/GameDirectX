#include"TileMap.h"
#include<fstream>
#include"Game.h"
using namespace std;
Map* Map::m_instance = NULL;

Map* Map::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Map();
	return m_instance;
}
Map::Map()
{
	
	
/*	TextureMap->Add(1000, L"TileMap\\Tileset.png", D3DCOLOR_XRGB(0, 0, 255)); \
		TileSet = TextureMap->Get(1000);
	if (TileSet == NULL)
		return*/
}
Map::~Map()
{
	for (int i = 0; i < InHeight; i++)
		delete[] MatrixMap[i];
	delete[] MatrixMap;
}
D3DXVECTOR3 Map::ConvertWorldToViewPort(D3DXVECTOR3 C, D3DXVECTOR3 Source, D3DXVECTOR3 Pos)//
{																		//
																		//Pos tinh tien theo vector (C-Source)
	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);//Khoi tao ma tran don vi cap 4
	mt._41 = -(C.x - Source.x);//Khoi tao tham so x, y de doi` anh
	mt._42 = -(C.y - Source.y);
	D3DXVECTOR4 tmp;
	D3DXVec3Transform(&tmp, &Pos, &mt);//Tinh tien bang cach nhan vector 4 chieu cho ma tran cap 4
	return D3DXVECTOR3(tmp.x, tmp.y, 0);
}
void Map::LoadStage1()
{
	CTextures * TexMap;
	TexMap = CTextures::GetInstance();
	ifstream ReadMap(L"TileMap\\Matrix1.txt");
	ReadMap >> InTile >> InWidth >> InHeight;
	MatrixMap = new int*[InHeight];
	for (int i = 0; i < InHeight; i++)
		MatrixMap[i] = new int[InWidth];
	for (int i = 0; i < InHeight; i++)
		for (int j = 0; j < InWidth; j++)
		{
			ReadMap >> MatrixMap[i][j];
		}
	TexMap->Add(ID_TEX_TILEMAP_1, L"TileMap\\Tileset1.png", D3DCOLOR_XRGB(176, 224, 248));
	TileSet = TexMap->Get(ID_TEX_TILEMAP_1);
}
void Map::LoadStage2()
{
	CTextures * TexMap;
	TexMap = CTextures::GetInstance();
	ifstream ReadMap(L"TileMap\\Matrix2.txt");
	ReadMap >> InTile >> InWidth >> InHeight;
	MatrixMap = new int*[InHeight];
	for (int i = 0; i < InHeight; i++)
		MatrixMap[i] = new int[InWidth];
	for (int i = 0; i < InHeight; i++)
		for (int j = 0; j < InWidth; j++)
		{
			ReadMap >> MatrixMap[i][j];
		}
	TexMap->Add(ID_TEX_TILEMAP_2, L"TileMap\\Tileset2.png", D3DCOLOR_XRGB(176, 224, 248));
	TileSet = TexMap->Get(ID_TEX_TILEMAP_2);
}

void Map::LoadStage3()
{
	CTextures * TexMap;
	TexMap = CTextures::GetInstance();
	ifstream ReadMap(L"TileMap\\Matrix3.txt");
	ReadMap >> InTile >> InWidth >> InHeight;
	MatrixMap = new int*[InHeight];
	for (int i = 0; i < InHeight; i++)
		MatrixMap[i] = new int[InWidth];
	for (int i = 0; i < InHeight; i++)
		for (int j = 0; j < InWidth; j++)
		{
			ReadMap >> MatrixMap[i][j];
		}
	TexMap->Add(ID_TEX_TILEMAP_3, L"TileMap\\Tileset3.png", D3DCOLOR_XRGB(176, 224, 248));
	TileSet = TexMap->Get(ID_TEX_TILEMAP_3);
}

void Map::Render(Camera *C)
{
	
	//Khoi tao tileset
	CGame *render = CGame::GetInstance();
	//Xu li theo luoi bitmap chuan 32x32
	//Chieu ngang va chieu doc viewport
	int Width, Height;
	C->GetSizeViewPort(Width, Height);
	D3DXVECTOR3 CPos = C->ConvertCameraPos();//CHuyen ve toa do goc trai tren
	D3DXVECTOR3 SPos(0, 0, 0), Pos;
	//Chon hang va cot de render tile
	int RowTileStart, RowTileEnd, ColTileStart, ColTileEnd;
	ColTileStart = CPos.x / 32;
	ColTileEnd = ColTileStart + Width / 32;
	RowTileStart = 2;//Chua` cho ve imfomation
	RowTileEnd = InHeight;
	int ID;
	//Xu li Tilset co chieu ngang khong qua 80 tile
	for (int i = RowTileStart; i < RowTileEnd; i++)
		for (int j = ColTileStart; j <= ColTileEnd; j++)
		{
			int Left, Top;
			ID = MatrixMap[i][j];
			if (ID / 80 == 0)
			{
				Top = 0;
				Left = ID;
			}
			else
			{
				Top = ID / 80;
				Left = ID - Top * 80;
			}
			Pos = D3DXVECTOR3(j * 32, i * 32, 0);//Toa do thuc cua Tile
			SPos = ConvertWorldToViewPort(CPos, C->GetViewPort(), Pos);//Doi ve Viewport luu vao SPos
			render->Draw(SPos.x, SPos.y, TileSet, Left * 32, Top * 32, Left * 32 + 32, Top * 32 + 32);
		}

}