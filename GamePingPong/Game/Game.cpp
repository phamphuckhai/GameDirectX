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
LPDIRECT3DSURFACE9 surface;
SPRITE ball, paddle1, paddle2;
LPDIRECT3DTEXTURE9 ball_image;
LPDIRECT3DTEXTURE9 paddle1_image;
LPDIRECT3DTEXTURE9 paddle2_image;
LPDIRECT3DSURFACE9 back;
ID3DXFont *font = NULL;
ID3DXFont *fontS = NULL;
RECT FRect, FRect2, SRect, SRect2;
const char *text, *text2;
int ballspeed = 10, paddlespeed = 20;
int score1 = 0, score2 = 0;
//Player Pl1(250, 350, 50, 70);
//Player Pl2(250, 350, 730, 750);
//Ball ball(290, 310, 390, 410);
long start = GetTickCount();
int tmp;
HRESULT result;
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
	back = LoadSurface(L"background.jpg", NULL);
	if (back == NULL)
		return 0;
	paddle1_image = LoadTexture(L"paddle_1.png", D3DCOLOR_XRGB(255, 0, 255));
	if (paddle1_image == NULL)
		return 0;
	paddle2_image = LoadTexture(L"paddle_2.png", D3DCOLOR_XRGB(255, 0, 255));
	if (paddle2_image == NULL)
		return 0;
	ball_image = LoadTexture(L"ball.png", D3DCOLOR_XRGB(0, 0, 0));
	if (ball_image == NULL)
		return 0;
	//ball
	ball.x = 400;
	ball.y = 200;
	ball.width = 32;
	ball.height = 32;
	ball.movex = ballspeed;
	ball.movey = -ballspeed;
	ball.curframe = 1;
	ball.lastframe = 7;
	ball.animdelay = 3;
	ball.animcount = 0;
	//paddle1
	paddle1.x = 50;
	paddle1.y = 250;
	paddle1.width = 20;
	paddle1.height = 100;
	//paddle2
	paddle2.x = 730;
	paddle2.y = 250;
	paddle2.width = 20;
	paddle2.height = 100;
	result = d3ddev->CreateOffscreenPlainSurface(
		800,
		600,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&surface,
		NULL);
	if (result != D3D_OK)
		return 1;

	result = D3DXCreateFontW(d3ddev, 40, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Ariel", &font);
	if (result != D3D_OK)
		return 1;
	result = D3DXCreateFontW(d3ddev, 72, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Ariel", &fontS);
	if (result != D3D_OK)
		return 1;
	SetRect(&FRect, 0, 0, 200, 200);
	SetRect(&FRect2, SCREEN_WIDTH - 155, 0, SCREEN_WIDTH, 200);
	SetRect(&SRect, 150, 100, 350, 300);
	SetRect(&SRect2, SCREEN_WIDTH - 200, 100, SCREEN_WIDTH - 50, 300);
	text = "PLAYER1";
	text2 = "PLAYER2";
	return 1;
}
int Collision(SPRITE sprite1, SPRITE sprite2)
{
	RECT rect1;
	rect1.left = sprite1.x + 1;
	rect1.top = sprite1.y + 1;
	rect1.right = sprite1.x + sprite1.width - 1;
	rect1.bottom = sprite1.y + sprite1.height - 1;
	RECT rect2;
	rect2.left = sprite2.x + 1;
	rect2.top = sprite2.y + 1;
	rect2.right = sprite2.x + sprite2.width - 1;
	rect2.bottom = sprite2.y + sprite2.height - 1;
	RECT dest;
	return IntersectRect(&dest, &rect1, &rect2);
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
		ball.x += ball.movex;
		ball.y += ball.movey;
		if (ball.x > SCREEN_WIDTH - ball.width)
		{
			/*ball.x -= ball.width;
			ball.movex *= -1;*/
			score1++;
			ball.x = 400;
			ball.y = 200;
			ball.width = 32;
			ball.height = 32;
			ball.movex = ballspeed;
			ball.movey = -ballspeed;
			ball.curframe = 1;
			ball.lastframe = 7;
			ball.animdelay = 3;
			ball.animcount = 0;
		}
		else if (ball.x < 0)
		{
			/*ball.x += ball.width;
			ball.movex *= -1;*/
			score2++;
			ball.x = 400;
			ball.y = 200;
			ball.width = 32;
			ball.height = 32;
			ball.movex = ballspeed;
			ball.movey = -ballspeed;
			ball.curframe = 1;
			ball.lastframe = 7;
			ball.animdelay = 3;
			ball.animcount = 0;
		}
		if (ball.y > SCREEN_HEIGHT - ball.height)
		{
			ball.y -= ball.height;
			ball.movey *= -1;
		}
		else if (ball.y < 0)
		{
			ball.y += ball.height;
			ball.movey *= -1;
		}
		paddle2.y += Mouse_Y();
		/*if (Key_Down(DIK_W))
			paddle2.y -= paddlespeed;
		if (Key_Down(DIK_S))
			paddle2.y += paddlespeed;*/
		if (Key_Down(DIK_UP))
			paddle1.y -= paddlespeed;
		if (Key_Down(DIK_DOWN))
			paddle1.y += paddlespeed;
		if (paddle1.y > SCREEN_HEIGHT - paddle1.height)
			paddle1.y = SCREEN_HEIGHT - paddle1.height;
		else if (paddle1.y < 0)
			paddle1.y = 0;
		if (paddle2.y > SCREEN_HEIGHT - paddle2.height)
			paddle2.y = SCREEN_HEIGHT - paddle2.height;
		else if (paddle2.y < 0)
			paddle2.y = 0;
		if (Collision(paddle1, ball) || Collision(paddle2, ball))
		{
			ball.x -= ball.movex;
			ball.movex = -ball.movex;
		}
	}
	/*a.left = ball.x;
	a.top = ball.y;
	a.right = ball.x + ball.width;
	a.bottom = ball.y + ball.height;
	b.left = paddle1.x;
	b.top = paddle1.y;
	b.right = paddle1.x + paddle1.width;
	b.bottom = paddle1.y + paddle1.height;
	c.left = paddle2.x;
	c.top = paddle2.y;
	c.right = paddle2.x + paddle2.width;
	c.bottom = paddle2.y + paddle2.height;
	rect.top = 0;
	rect.left = 0;
	rect.right = 100;
	rect.bottom = 100;*/
	if (++ball.animcount > ball.animdelay)
	{
		ball.animcount = 0;
		if (++ball.curframe > ball.lastframe)
			ball.curframe = 0;
	}
	//Covert int to char*
	std::string s1 = std::to_string(score1);
	char const *pchar = s1.c_str();
	std::string s2 = std::to_string(score2);
	char const *pchar2 = s2.c_str();
	//Begin screen
	if (d3ddev->BeginScene())
	{
		d3ddev->StretchRect(back, NULL, backbuffer, NULL, D3DTEXF_NONE);
		//Draw text
		font->DrawTextA(NULL, text, -1, &FRect, DT_LEFT, D3DCOLOR_XRGB(255, 0, 255));
		font->DrawTextA(NULL, text2, -1, &FRect2, DT_LEFT, D3DCOLOR_XRGB(255, 0, 255));
		fontS->DrawTextA(NULL, pchar, -1, &SRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
		fontS->DrawTextA(NULL, pchar2, -1, &SRect2, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
		sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);
		//Ball
		D3DXVECTOR3 positionball((float)ball.x, (float)ball.y, 0);
		RECT bll;
		int columns = 2;
		bll.left = (ball.curframe % columns) * ball.width;
		bll.top = (ball.curframe / columns) * ball.height;
		bll.right = bll.left + ball.width;
		bll.bottom = bll.top + ball.height;
		// vẽ sprite
		sprite_handler->Draw(
			ball_image,
			&bll,
			NULL,
			&positionball,
			D3DCOLOR_XRGB(255, 255, 255));
		//Vi tri paddle1
		D3DXVECTOR3 positionPaddle1((float)paddle1.x, (float)paddle1.y, 0);
		//Ve paddle1
		RECT player1;
		player1.left = paddle1.x;
		player1.top = paddle1.y;
		player1.right = paddle1.x + paddle1.width;
		player1.bottom = paddle1.y + paddle1.height;
		sprite_handler->Draw(
			paddle1_image,
			&player1,
			NULL,
			&positionPaddle1,
			D3DCOLOR_XRGB(255, 255, 255));
		//Vi tri paddle2
		D3DXVECTOR3 positionPaddle2((float)paddle2.x, (float)paddle2.y, 0);
		//Ve paddle2
		RECT player2;
		player2.left = paddle2.x;
		player2.top = paddle2.y;
		player2.right = paddle2.x + paddle2.width;
		player2.bottom = paddle2.y + paddle2.height;
		sprite_handler->Draw(
			paddle2_image,
			&player2,
			NULL,
			&positionPaddle2,
			D3DCOLOR_XRGB(255, 255, 255));
		sprite_handler->End();
		/*d3ddev->StretchRect(surface, NULL, backbuffer, &a, D3DTEXF_NONE);
		d3ddev->StretchRect(surface, NULL, backbuffer, &b, D3DTEXF_NONE);
		d3ddev->StretchRect(surface, NULL, backbuffer, &c, D3DTEXF_NONE);*/
		d3ddev->EndScene();
	}
	//game Over
	if (score1 == 10) {
		MessageBox(hwnd, L"PLAYER1 WIN", L"CONGRATULATION", MB_OK);
		PostMessage(hwnd, WM_DESTROY, 0, 0);
	}
	if (score2 == 10) {
		MessageBox(hwnd, L"PLAYER2 WIN", L"CONGRATULATION", MB_OK);
		PostMessage(hwnd, WM_DESTROY, 0, 0);
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

	if (d3d != NULL)
		d3d->Release();
	if (back != NULL)
		back->Release();
	if (font != NULL)
		font->Release();
}
