#include<d3d9.h>
#include<d3dx9.h>
#include<time.h>
#include<dinput.h>
#include"game.h"
#include"dxgraphics.h"
#include"dxinput.h"
#include<tchar.h>
#include<sstream>
#include<string>
LPD3DXSPRITE sprite_handler;
LPDIRECT3DTEXTURE9 Player_image;
LPDIRECT3DSURFACE9 surface;
LPDIRECT3DSURFACE9 back;
bool leap = TRUE;
int HightLeap = 0;
SPRITE Player;
long start = GetTickCount();
int tmp;
HRESULT result;
RECT tmp1;
int Game_Init(HWND hwnd) {
	srand((unsigned)time(NULL));
	if (!Init_Mouse(hwnd))
	{
		MessageBox(hwnd, L"Error initializing the mouse", L"Error", MB_OK);
		return 0;
	}
	if (!Init_Keyboard(hwnd))
	{
		MessageBox(hwnd, L"Error initializing the keyboard", L"Error", MB_OK);
		return 0;
	}
	result = D3DXCreateSprite(d3ddev, &sprite_handler);
	if (result != D3D_OK)
		return 0;
	back = LoadSurface(L"bground.png", NULL);
	Player_image = LoadTexture(L"sflower.png", D3DCOLOR_XRGB(0, 0, 255));
	if (Player_image == NULL)
		return 0;
	if (back == NULL)
		return 0;
	result = d3ddev->CreateOffscreenPlainSurface(
		800,
		600,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&surface,
		NULL);
	if (result != D3D_OK)
		return 1;

	//SET player
	Player.x = 0;
	Player.y = 300;
	Player.height = 238;
	Player.width = 210;
	//RECT tmp
	tmp1.left = 0;
	tmp1.top = 0;
	tmp1.right = tmp1.left+ 1200;
	tmp1.bottom = tmp1.top + 600;
	return 1;
}

void Game_Run(HWND hwnd)
{
	if (d3ddev == NULL)
		return;
	Poll_Mouse();
	Poll_Keyboard();
	if (GetTickCount() - start >= 30)
	{

		start = GetTickCount();
		if (Key_Down(DIK_RIGHT))
		{
			Player.x += 30;
			if (Player.x > SCREEN_WIDTH / 2 && tmp1.right < 4800)
			{
				Player.x -= 30;
				tmp1.left += 30;
				tmp1.right = tmp1.left + 1200;
			}
			if (tmp1.right > 4800)
			{
				tmp1.left -= 30;
				tmp1.right = tmp1.left + 1200;
			}
			if ((Player.x+ Player.height) > SCREEN_WIDTH)
			{
				Player.x = SCREEN_WIDTH - Player.height;
			}

		}

		if (Key_Down(DIK_LEFT))
		{
			Player.x -= 30;
			if (Player.x < SCREEN_WIDTH / 2 && tmp1.left>0) {
				Player.x += 30;
				tmp1.left -= 30;
				tmp1.right = tmp1.left + 1200;
			}
			if (Player.x < 0)
				Player.x = 0;
			if (tmp1.left < 0)
				tmp1.left = 0;
		}
		if (Key_Down(DIK_UP)) {

		}
		
	
	}
	//Begin screen
	if (d3ddev->BeginScene())
	{
		d3ddev->StretchRect(back, &tmp1, backbuffer, NULL, D3DTEXF_NONE);
		sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);
		D3DXVECTOR3 positionplayer((float)Player.x, (float)Player.y, 0);
		sprite_handler->Draw(
			Player_image,
			NULL,
			NULL,
			&positionplayer,
			D3DCOLOR_XRGB(255, 255, 255));
		sprite_handler->End();
		d3ddev->EndScene();
	}
	d3ddev->Present(NULL, NULL, NULL, NULL);
	if (Mouse_Button(0))
		PostMessage(hwnd, WM_DESTROY, 0, 0);
	if (Key_Down(DIK_ESCAPE))
		PostMessage(hwnd, WM_DESTROY, 0, 0);
}
void Game_End(HWND hwnd)
{
	if (surface != NULL)
		surface->Release();

	if (d3ddev != NULL)
		d3ddev->Release();

}
