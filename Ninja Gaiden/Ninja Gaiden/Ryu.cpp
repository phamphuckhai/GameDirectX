#include "Ryu.h"
#include"Textures.h"
#include"Sprites.h"
#include"Camera.h"
#include"TileMap.h"
using namespace std;
Ryu* Ryu::m_instance = NULL;
Ryu* Ryu::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Ryu();
	return m_instance;
}
Ryu::Ryu() : CGameObject::CGameObject()
{
	score = 0;
	hp = 16;
	IsClimb = false;
	IsDie = false;
	Katana *katana = Katana::GetInstance();
	katana->SetObj(this);
	LoadResource();
	level = 1;
	untouchable = 0;
	IsJump = false;
	IsFighting = false;
	IsHurt = false;
	countmisc = 0;
}

void Ryu::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (hp == 0)
		IsDie == true;
	CGameObject::Update(dt);
	//Va cham game world
	if (direction < 0 && x < 0) x = 0;
	if (direction > 0 && x > Map::GetInstance()->GetInWidth() * 32 - 32) x = Map::GetInstance()->GetInWidth() * 32 - 23;
	//Vy = 0 khi IsOnGround
	if (vy == 0 && IsJump == true)
	{
		IsJump = false;
	}
	if (IsFighting == true)
	{//Delay 1 ti

		if (GetTickCount() - TimeFighting > 300)
			IsFighting = false;
		//
	}
	if (IsHurt == true)
	{//Delay 1 ti
		if (GetTickCount() - TimeHurt > 1000)
			IsHurt = false;
		//
	}
	//fall down
	if (IsClimb == false)
		vy += GRAVITY * dt;


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	if (IsFighting == true && IsHurt == false) {
		for (UINT i = 0; i < coObjects->size(); i++)
		{/*
			Katana *katana = Katana::GetInstance();
			LPGAMEOBJECT e = coObjects->at(i);
			if (dynamic_cast<SwordMan *>(e))
			{
				LPCOLLISIONEVENT Co = e->SweptAABBEx(katana);
				if (Co->t > 0 && Co->t <= 1.0f)
					DeadEffect::GetInstance()->AppearDeadEffect(e);


			}*///Ko dung dc sweept AABB
			Katana *katana = Katana::GetInstance();
			LPGAMEOBJECT e = coObjects->at(i);
			if (dynamic_cast<SwordMan *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}
			else if (dynamic_cast<Panther *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}
			else if (dynamic_cast<Bird *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}
			else if (dynamic_cast<Runner *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}
			else if (dynamic_cast<Boss *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}
			else if (dynamic_cast<Banshee *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}
			/*else if (dynamic_cast<Artillery *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}*/
			/*else if (dynamic_cast<MachineGunGuy *>(e))
			{
				if (katana->IsCollision(e)) {
					e->Iskill();
					score += 100;
				}
			}*/
		}
	}
	
	// turn off collision when die 
	if (IsDie == false)
		CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount() - untouchable_start > RYU_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		//Xu ly va cham gan nhat truoc voi nx, ny la phap tuyen 
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			
				

			LPCOLLISIONEVENT e = coEventsResult[i];
			if (dynamic_cast<CBrick *>(e->obj))
			{
				/*x += min_tx * dx + nx * 0.4f;*/
				x += dx;
				
				CBrick *brick = dynamic_cast<CBrick *>(e->obj);

				// xu ly va cham voi block
				/*if (nx != 0)vx = 0;*/ //Gay tinh trang sprite ryu bi giat
				if (ny < 0)
				{
					y += min_ty * dy + ny * 0.4f;
					if (vy >= 0) //Dieu kien giup cho Ryu_Hurt ko bi mat di vy
						vy = 0;
				}
				else if (ny > 0)
				{
					y += dy;
				}
				IsClimb = false;
			}
			else if (dynamic_cast<Wall *>(e->obj))
			{
				Wall *wall = dynamic_cast<Wall *>(e->obj);
				x += min_tx * dx + nx * 0.4f;
				if (nx != 0)
				{
					vx = 0;
					vy = 0;
					IsClimb = true;

				}
			}
			else if (dynamic_cast<Bird *>(e->obj))
			{
				x += dx;
				y += dy;
			}
			else/* if (dynamic_cast<SwordMan *>(e->obj))*/
			{


				if (nx != 0 || ny != 0)
				{

					if (untouchable == 0)
					{
						if (e->nx < 0)
							direction = 1;
						else if (e->nx > 0)
							direction = -1;

						SetState(RYU_STATE_HURT);
						hp--;

						//-hp
					}
				}
				IsClimb = false;

			}



		}
	}

	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	if (x > (512 / 2) && x < Map::GetInstance()->GetInWidth() * 32 - 256)//***
		Camera::GetInstance()->Update(x);
}

void Ryu::Render()
{
	//DOi Ryu ve trong khung Camera
	D3DXVECTOR3 PosRyuAfterConvert;
	PosRyuAfterConvert = CGameObject::ConverObjectToViewPort();
	//
	int ani;
	if (IsClimb == true)
	{
		ani = RYU_ANI_CLIMB;
	}
	else if (IsHurt == true)
	{
		if (direction > 0)
			ani = RYU_ANI_HURT_RIGHT;
		else
		{
			ani = RYU_ANI_HURT_LEFT;
		}
	}
	else if (IsFighting == true && IsJump == true)
	{
		if (direction > 0)
			ani = RYU_ANI_JUMP_FIGHT_RIGHT;
		else
			ani = RYU_ANI_JUMP_FIGHT_LEFT;
	}
	else if (IsFighting == true)
	{
		if (direction > 0)
			ani = RYU_ANI_WALK_FIGHT_RIGHT;
		else
			ani = RYU_ANI_WALK_FIGHT_LEFT;
	}
	else if (IsJump == false) {//is On ground
		if (vx == 0)
		{
			if (direction > 0) ani = RYU_ANI_IDLE_RIGHT;
			else ani = RYU_ANI_IDLE_LEFT;
		}
		else if (vx > 0)
			ani = RYU_ANI_WALKING_RIGHT;
		else ani = RYU_ANI_WALKING_LEFT;
	}
	else if (IsJump == true)
	{
		if (direction == 1)
			ani = RYU_ANI_JUMP_RIGHT;
		else
			ani = RYU_ANI_JUMP_LEFT;
	}
	int alpha = 255;
	if (untouchable) alpha = 128;
	animations[ani]->Render(PosRyuAfterConvert.x, PosRyuAfterConvert.y, countmisc, alpha);
	countmisc++;
	/*RenderBoundingBox();*/
	Katana::GetInstance()->Render();
}

void Ryu::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case RYU_STATE_WALKING_RIGHT:
		if (IsClimb == false) {
			if (IsFighting == false && IsHurt == false) {
				vx = RYU_WALKING_SPEED;
				direction = 1;
			}
		}
		else {
			y -= 1;
			if (y < 115)
				y = 115;//Climb max
		}
		break;
	case RYU_STATE_WALKING_LEFT:
		if (IsClimb == false) {
			if (IsFighting == false && IsHurt == false) {
				vx = -RYU_WALKING_SPEED;
				direction = -1;
			}
		}
		else {
			y += 1;
			if (y > 177)
				y = 177;
		}
		break;
	case RYU_STATE_JUMP:
		if (IsClimb == false) {
			if (IsJump == false) {
				IsJump = true;
				vy = -RYU_JUMP_SPEED_Y;
			}
		}
		else
		{
			vy = -RYU_JUMP_SPEED_Y;
			direction = -direction;
			vx = direction * RYU_WALKING_SPEED;
			IsClimb = false;
			IsJump = true;
		}
	case RYU_STATE_IDLE:
		if (IsHurt == FALSE)
			vx = 0;
		break;
	case RYU_STATE_FIGHTING:
		IsFighting = true;
		if (IsJump == false) vx = 0;
		TimeFighting = GetTickCount();
		break;
	case RYU_STATE_HURT:
		StartUntouchable();
		TimeHurt = GetTickCount();
		IsHurt = true;
		vy = -RYU_JUMP_SPEED_Y * 0.8f;
		if (direction > 0)
			vx = -RYU_WALKING_SPEED / 2;
		else
			vx = RYU_WALKING_SPEED / 2;
		break;

	}
}
void Ryu::LoadResource()
{
	CTextures * textures = CTextures::GetInstance();

	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;

	textures->Add(ID_TEX_BBOX, L"BoundingBox\\bbox.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_Ryu, L"Ryu\\Ryu.png", D3DCOLOR_XRGB(176, 224, 248));
	LPDIRECT3DTEXTURE9 texRuy = textures->Get(ID_TEX_Ryu);

	sprites->Add(20001, 197, 40, 224, 72, texRuy);//idle right  17x32
	sprites->Add(20002, 234, 40, 266, 71, texRuy);//move right  22x31
	sprites->Add(20003, 275, 40, 307, 71, texRuy);
	sprites->Add(20004, 315, 40, 347, 71, texRuy);

	sprites->Add(20011, 147, 40, 184, 72, texRuy);//idle left 17x32
	sprites->Add(20012, 107, 40, 147, 71, texRuy);//Move left  22x31
	sprites->Add(20013, 66, 40, 106, 71, texRuy);
	sprites->Add(20014, 26, 40, 66, 71, texRuy);

	sprites->Add(20021, 207, 80, 224, 111, texRuy);//Jump right 17x31
	sprites->Add(20022, 237, 80, 264, 111, texRuy);
	sprites->Add(20023, 267, 84, 293, 108, texRuy);
	sprites->Add(20024, 295, 88, 325, 104, texRuy);
	sprites->Add(20025, 327, 84, 353, 108, texRuy);
	sprites->Add(20026, 355, 88, 385, 104, texRuy);

	/*sprites->Add(20031, 167, 80, 184, 111, texRuy);*///Jump left
	sprites->Add(20032, 104, 80, 144, 111, texRuy);
	sprites->Add(20033, 430, 102, 470, 126, texRuy);
	sprites->Add(20034, 433, 141, 473, 157, texRuy);
	sprites->Add(20035, 431, 172, 471, 196, texRuy);
	sprites->Add(20036, 434, 209, 474, 225, texRuy);

	sprites->Add(20041, 207, 241, 225, 271, texRuy);//walk Fighting right 17x31
	sprites->Add(20042, 226, 241, 269, 271, texRuy); //
	sprites->Add(20043, 272, 241, 306, 271, texRuy);
	sprites->Add(20044, 312, 241, 348, 270, texRuy);

	sprites->Add(20051, 167, 240, 184, 271, texRuy);//Walk Fight left
	sprites->Add(20052, 116, 241, 156, 270, texRuy); //40x29
	sprites->Add(20053, 70, 241, 110, 270, texRuy); //29x29
	sprites->Add(20054, 43, 241, 69, 270, texRuy);

	sprites->Add(20061, 226, 320, 274, 351, texRuy);//Jump Fight right 38x31
	sprites->Add(20062, 272, 320, 309, 351, texRuy); //27x31

	sprites->Add(20071, 115, 320, 155, 351, texRuy);//Jump Fight left 38x31
	sprites->Add(20072, 69, 320, 109, 351, texRuy); //27x31

	sprites->Add(40000, 168, 201, 183, 232, texRuy);//Climb
	sprites->Add(40001, 128, 201, 143, 232, texRuy); 
	sprites->Add(40002, 88, 201, 103, 232, texRuy); 
	sprites->Add(40003, 45, 201, 66, 232, texRuy);
	sprites->Add(40004, 0, 20, 30, 2731, texRuy);
	//Note: ani left lay goc phai chuan (- 40) . ani right lay goc trai -10 => de khong bi giat hinh vs Ryu
	ani = new CAnimation(100);
	ani->Add(20001);
	animations->Add(100, ani);

	ani = new CAnimation(100);
	ani->Add(20011);
	animations->Add(101, ani);

	ani = new CAnimation(100);
	ani->Add(20002);
	ani->Add(20003);
	ani->Add(20004);
	animations->Add(200, ani);

	ani = new CAnimation(100);
	ani->Add(20012);
	ani->Add(20013);
	ani->Add(20014);
	animations->Add(201, ani);

	ani = new CAnimation(100);
	/*	ani->Add(20021);*/
	/*ani->Add(20022);*/
	ani->Add(20023);
	ani->Add(20024);
	ani->Add(20025);
	ani->Add(20026);
	animations->Add(300, ani);

	ani = new CAnimation(100);
	/*ani->Add(20031);*/
	/*ani->Add(20032);*/
	ani->Add(20033);
	ani->Add(20034);
	ani->Add(20035);
	ani->Add(20036);
	animations->Add(301, ani);

	ani = new CAnimation(100);
	/*ani->Add(20041);*/
	ani->Add(20042);
	ani->Add(20043);
	/*ani->Add(20044);*/
	animations->Add(800, ani);

	ani = new CAnimation(100);
	/*ani->Add(20051);*/
	ani->Add(20052);
	ani->Add(20053);
	/*ani->Add(20054);*/
	animations->Add(900, ani);

	ani = new CAnimation(100);
	ani->Add(20061);
	ani->Add(20062);
	animations->Add(901, ani);

	ani = new CAnimation(100);
	ani->Add(20071);
	ani->Add(20072);
	animations->Add(902, ani);

	ani = new CAnimation(100);//Ryu hurt right
	ani->Add(20023);
	animations->Add(903, ani);

	ani = new CAnimation(100);//Ryu hurt left
	ani->Add(20033);
	animations->Add(904, ani);
	
	ani = new CAnimation(100);//climb
	ani->Add(40000);
	ani->Add(40001);
	ani->Add(40002);
	ani->Add(40003);
	/*ani->Add(40004);*/
	animations->Add(109, ani);

	AddAnimation(100);		// idle right vector[0]
	AddAnimation(101);		// idle left vector[1]
	AddAnimation(200);		// walk right vector[2]
	AddAnimation(201);		// walk left vector[3]
	AddAnimation(300);		//Jump right vector[4]	
	AddAnimation(301);      //Jump left vector[5]
	AddAnimation(800);		//walk Fighting right vector[6]
	AddAnimation(900);		//walk Fighting left vector[7]
	AddAnimation(901);		//Jump Fighting right vector [8]
	AddAnimation(902);		//jump Fighitng left vector [9]
	AddAnimation(903);		//Hurt right vector[10]
	AddAnimation(904);		//Hurt left vector[11]
	AddAnimation(109);		//Climb vector[12]
	SetPosition(30.0f, 120.0f);
}
void Ryu::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (IsClimb == true)
	{
		left = x;
		top = y;
		right = left + RYU_NORMAL_WIDTH + 1;
		bottom = top + RYU_NORMAL_HEIGHT + 1;
	}
	else if (direction > 0) {
		left = x + 10;
		top = y;
		right = left + RYU_NORMAL_WIDTH + 1;
		bottom = top + RYU_NORMAL_HEIGHT + 1;
	}
	else
	{
		left = x + 20;
		top = y;
		right = left + RYU_NORMAL_WIDTH + 1;
		bottom = top + RYU_NORMAL_HEIGHT + 1;
	}
}
Ryu::~Ryu()
{
}
void Ryu::ResetObject()
{
	hp = 16;
	SetPosition(0.0f, 0.0f);
	Camera::GetInstance()->CameraReset();
}
void Ryu::ReturnGround()//Tro lai mat dat khi co bug 
{
	SetPosition(x, 0.0f);
}
int Ryu::GetHp()
{
	return hp;
}