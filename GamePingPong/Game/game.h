#pragma once
#ifndef _GAME_H
#define _GAME_H
#include <d3d9.h>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include<dinput.h>
#include"dxgraphics.h"
#define APPTITLE L"Ping Pong"
#define FULLSCREEN 0
#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 600
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEY_UP(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?1:0)
int Game_Init(HWND);
void Game_Run(HWND);
void Game_End(HWND);
typedef struct {
	int x, y;
	int width, height;
	int movex, movey;
	int curframe, lastframe;
	int animdelay, animcount;
	int scalex, scaley;
	int rotation, rotaterate;
} SPRITE;
#endif