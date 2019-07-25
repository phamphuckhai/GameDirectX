#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<dinput.h>
#include"Global.h"
class Camera
{
private:
	static Camera* m_instance;
	int VPWidth; //ViewPort Width
	int VPHeight;//ViewPort Height
	D3DVECTOR VPos;//ViewPort position
	D3DVECTOR CPos;//Camera Position (diem chinh giua viewpos)
	Camera();
public:
	static Camera* GetInstance();
	~Camera();
	void SetCPos(int x, int y);
	void Update(int x);
	void GetSizeViewPort(int &x, int &y);
	void CameraReset();
	D3DXVECTOR3 GetCamera();
	D3DXVECTOR3 ConvertCameraPos();
	D3DXVECTOR3 GetViewPort();
	D3DXVECTOR3 ConvertViewport();
};