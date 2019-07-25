#include"camera.h"
Camera* Camera::m_instance = NULL;
Camera* Camera::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new Camera();
	return m_instance;
}
Camera::Camera()
{
	VPWidth = SCREEN_WIDTH;
	VPHeight = SCREEN_HEIGHT;
	VPos = D3DXVECTOR3(0, 0, 0);//Toa do khung nhin`
	CPos = D3DXVECTOR3((int)VPWidth / 2, (int)VPHeight / 2, 0);//Toa do camera (giua man hinh)
}
Camera::~Camera()
{

}
void Camera::SetCPos(int x, int y)
{

}
void Camera::Update(int x)
{
	
	CPos.x = x;
}
void Camera::GetSizeViewPort(int &x, int &y)
{
	x = VPWidth;
	y = VPHeight;
}
D3DXVECTOR3 Camera::GetCamera()
{
	return CPos;
}
D3DXVECTOR3 Camera::ConvertCameraPos()//Chuyen doi Camerapos o giua man hinh sang goc trai tren
{
	D3DXVECTOR3 CovertC;
	CovertC.x = CPos.x - SCREEN_WIDTH / 2;//Chuyen doi Camera position ve goc trai tren
	CovertC.y = CPos.y - SCREEN_HEIGHT / 2;//
	return CovertC;
}
D3DXVECTOR3 Camera::ConvertViewport()
{
	D3DXVECTOR3 CovertV;
	CovertV.x = (VPos.x + VPWidth) / 2;
	CovertV.y = (VPos.y + VPHeight) / 2;
	return CovertV;
}
D3DXVECTOR3 Camera::GetViewPort()
{
	return VPos;
}
void Camera::CameraReset()
{
	VPos = D3DXVECTOR3(0, 0, 0);//Toa do khung nhin`
	CPos = D3DXVECTOR3((int)VPWidth / 2, (int)VPHeight / 2, 0);//Toa do camera (giua man hinh)
}