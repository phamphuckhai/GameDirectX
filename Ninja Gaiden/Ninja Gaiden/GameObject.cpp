#include <d3dx9.h>

#include <algorithm>
#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprites.h"
#include "Textures.h"
#include "TileMap.h"


CGameObject::CGameObject()
{
	IsDie = false;
	x = y = 0;
	vx = vy = 0;
	direction = 1;
}

void CGameObject::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	this->dt = dt;
	dx = vx * dt;
	dy = vy * dt;
}

LPCOLLISIONEVENT CGameObject::SweptAABBEx(LPGAMEOBJECT coO)
{
	float sl, st, sr, sb;		// static object bbox
	float ml, mt, mr, mb;		// moving object bbox
	float t, nx, ny;

	coO->GetBoundingBox(sl, st, sr, sb);

	// neu Static object la doi tuong di chuyen thi lay quang duong cua doi tuong goc - quang duong cua doi tuong di chuyen  
	float svx, svy;
	coO->GetSpeed(svx, svy);

	float sdx = svx * dt;
	float sdy = svy * dt;

	float dx = this->dx - sdx;
	float dy = this->dy - sdy;

	GetBoundingBox(ml, mt, mr, mb);

	CGame::SweptAABB(
		ml, mt, mr, mb,
		dx, dy,
		sl, st, sr, sb,
		t, nx, ny
	);

	CCollisionEvent * e = new CCollisionEvent(t, nx, ny, coO);
	return e;
}

/*
	Calculate potential collisions with the list of colliable objects

	coObjects: the list of colliable objects
	coEvents: list of potential collisions
*/
void CGameObject::CalcPotentialCollisions(
	vector<LPGAMEOBJECT> *coObjects,
	vector<LPCOLLISIONEVENT> &coEvents)
{
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		LPCOLLISIONEVENT e = SweptAABBEx(coObjects->at(i));//Kiem tra va cham tai phan tu thu i

		if (e->t > 0 && e->t <= 1.0f)
			coEvents.push_back(e);//Co va cham thi dat va list coEvents
		else
			delete e;
	}

	std::sort(coEvents.begin(), coEvents.end(), CCollisionEvent::compare); //Sap xem thoi gian va cham tu begin->end theo ham compare. Kiem tra tat ca event va cham voi doi tuong Object
}

void CGameObject::FilterCollision(
	vector<LPCOLLISIONEVENT> &coEvents,
	vector<LPCOLLISIONEVENT> &coEventsResult,
	float &min_tx, float &min_ty,
	float &nx, float &ny)
{
	min_tx = 1.0f; // Thoi gian va cham theo truc x
	min_ty = 1.0f; //Thoi gian va cham theo truc y
	int min_ix = -1; // CoEvent va cham theo truc x gan nhat
	int min_iy = -1; //CoEvent va cham theo truc y gan nhat

	nx = 0.0f;//Phap tuyen va cham
	ny = 0.0f;

	coEventsResult.clear();

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT c = coEvents[i];

		if (c->t < min_tx && c->nx != 0) {
			min_tx = c->t; nx = c->nx; min_ix = i;
		}

		if (c->t < min_ty  && c->ny != 0) {
			min_ty = c->t; ny = c->ny; min_iy = i;
		}
	}
	//CoEventsResult luu lai 2 va cham gan nhat theo truc Ox va Oy
	if (min_ix >= 0) coEventsResult.push_back(coEvents[min_ix]);
	if (min_iy >= 0) coEventsResult.push_back(coEvents[min_iy]);
}


void CGameObject::RenderBoundingBox()
{

	D3DXVECTOR3 p;
	RECT rect;

	LPDIRECT3DTEXTURE9 bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);
	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	p = Map::GetInstance()->ConvertWorldToViewPort(Camera::GetInstance()->ConvertCameraPos(), Camera::GetInstance()->GetViewPort(), D3DXVECTOR3(l, t, 0));
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	CGame::GetInstance()->Draw(p.x, p.y, bbox, rect.left, rect.top, rect.right, rect.bottom, 32);
}


void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	animations.push_back(ani);
}



CGameObject::~CGameObject()
{
}

D3DXVECTOR3 CGameObject::ConverObjectToViewPort()
{
	float l, t, r, b;
	int cam = Camera::GetInstance()->ConvertCameraPos().x;
	D3DXVECTOR3 P;
	//Convert toa do Object ve camera
	P = Map::GetInstance()->ConvertWorldToViewPort(Camera::GetInstance()->ConvertCameraPos(), Camera::GetInstance()->GetViewPort(), D3DXVECTOR3(x, y, 0));
	return P;
}
void CGameObject::ResetObject()
{

}
void CGameObject::Iskill()
{
}
