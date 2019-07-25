#pragma once

#define WINDOW_CLASS_NAME L"Ninja Gaiden"
#define MAIN_WINDOW_TITLE L"Ninja Gaiden"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 320

#define MAX_FRAME_RATE 90

#define ID_TEX_Ryu 0
#define ID_TEX_ENEMY 1
#define ID_TEX_MISC 2
#define ID_TEX_ENEMY_2 3

#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_BUFFER_SIZE 1024

#define BRICK_BBOX_WIDTH  16
#define BRICK_BBOX_HEIGHT 16
#define ID_TEX_BBOX -100		// Texture bounding box

#define GRAVITY			0.001f

#define RYU_WALKING_SPEED		0.12f //Cho Ryu
#define RYU_JUMP_SPEED_Y		0.35f

#define RYU_STATE_IDLE			0
#define RYU_STATE_WALKING_RIGHT	100
#define RYU_STATE_WALKING_LEFT	200
#define RYU_STATE_JUMP			300
#define RYU_STATE_FIGHTING		400
#define RYU_STATE_HURT			500
#define RYU_STATE_UP			600
#define RYU_STATE_DOWN			700
#define RYU_ANI_IDLE_RIGHT		0
#define RYU_ANI_IDLE_LEFT			1
#define RYU_ANI_WALKING_RIGHT		2
#define RYU_ANI_WALKING_LEFT		3
#define RYU_ANI_JUMP_RIGHT			4
#define RYU_ANI_JUMP_LEFT           5
#define RYU_ANI_WALK_FIGHT_RIGHT	6
#define RYU_ANI_WALK_FIGHT_LEFT		7
#define RYU_ANI_JUMP_FIGHT_RIGHT	8
#define RYU_ANI_JUMP_FIGHT_LEFT		9
#define RYU_ANI_HURT_RIGHT			10
#define RYU_ANI_HURT_LEFT			11 
#define RYU_ANI_CLIMB				12

#define RYU_NORMAL_WIDTH		17
#define RYU_NORMAL_HEIGHT		32
 
#define RYU_UNTOUCHABLE_TIME 3000


#define KATANA_W		20
#define KATANA_H		10

#define MACHINE_GUN_GUY_SPEED 0.09f //Cho Machine Gun Guy

#define ID_Ground 0

#define SWORDMAN_BBOX_W			24
#define SWORDMAN_BBOX_H			40
#define SWORDMAN_SPEED			0.05f
#define SWORDMAN_STATE_WALKING 600

#define PANTHER_BBOX_W		31
#define PANTHER_BBOX_H		16
#define PANTHER_SPEED		0.15f
#define PANTHER_JUMP		0.15f


enum EnumGameState
{
	GAME_STATE_1 = 0,
	GAME_STATE_2 = 1,
	GAME_STATE_3 = 2
};
#define ID_TEX_TILEMAP_1 200
#define ID_TEX_TILEMAP_2 300
#define ID_TEX_TILEMAP_3 400
#define ID_TEX_HP		500
#define ID_TEX_NOHP		600
#define FONT L"font\\FNinja.ttf"


#define Bird_W		16
#define Bird_H		15

#define RUNNER_SPEED	0.15f
#define RUNNER_W	16
#define RUNNER_H	32

#define BOSS_W	38
#define BOSS_H	54
#define BOSS_SPEED 0.25f
#define BOSS_JUMP 0.3f
#define BANSHEE_W 24
#define BANSHEE_H 43
#define BANSHEE_SPEED 0.01f

#define MGG_W 16
#define MGG_H 32
#define MGG_SPEED 0.13f