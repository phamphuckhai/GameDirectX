#include <d3d9.h>
#include<d3dx9.h>
#include<time.h>
#include<tchar.h>
#define APPTITLE _T("Load_Bitmap")
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEY_UP(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);
ATOM MyRegisterClass(HINSTANCE);
int Game_Init(HWND);
void Game_Run(HWND);
void Game_End(HWND);
LPDIRECT3D9 d3d = NULL;
LPDIRECT3DDEVICE9 d3ddev = NULL;
LPDIRECT3DSURFACE9 backbuffer = NULL;
LPDIRECT3DSURFACE9 surface = NULL;
LPDIRECT3DSURFACE9 back = NULL;

LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Game_End(hWnd);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APPTITLE;
	wc.hIconSm = NULL;
	return RegisterClassEx(&wc);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	MyRegisterClass(hInstance);
	HWND hWnd;
	hWnd = CreateWindow(
		APPTITLE,
		APPTITLE,
		WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	if (!Game_Init(hWnd))
		return 0;

	int done = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				done = 1;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			Game_Run(hWnd);
	}
	return msg.wParam;

}
int Game_Init(HWND hwnd)
{
	HRESULT result;
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d == NULL)
	{
		MessageBox(hwnd, _T("Error initializing Direct3D"), _T("Error"), MB_OK);
		return 0;
	}
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.hDeviceWindow = hwnd;
	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);
	if (d3ddev == NULL) {
		MessageBox(hwnd, _T("Error creating Direct3D device"), _T("Error"), MB_OK);
		return 0;
	}
	srand((unsigned int)time(NULL));
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
	result = d3ddev->CreateOffscreenPlainSurface(
		800,
		600,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&surface,
		NULL);
	if (!result)
		return 1;
	return 1;
}
int left = 0;
int right = 100;
int top = 0;
int bottom = 50;
int speed = 2;
void Game_Run(HWND hwnd)
{
	RECT rect;
	if (d3ddev == NULL)
		return;
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	if (d3ddev->BeginScene())
	{

		d3ddev->ColorFill(surface, NULL, D3DCOLOR_XRGB(rand() % 255, rand() % 255, rand() % 255));
		rect.left = left;
		rect.right = right;
		rect.top = top;
		rect.bottom = bottom;
		d3ddev->StretchRect(surface, NULL, backbuffer, &rect, D3DTEXF_NONE);
		d3ddev->EndScene();
		if (top == 0 && right < SCREEN_WIDTH)
		{
			left += speed;
			right += speed;
		}
		if (bottom < SCREEN_HEIGHT && right == SCREEN_WIDTH)
		{
			top += speed;
			bottom += speed;
		}

		if (bottom == SCREEN_HEIGHT && left > 0)
		{
			left -= speed;
			right -= speed;
		}

		if (left == 0 && top > 0)
		{
			top -= speed;
			bottom -= speed;
		}
		
	}
	d3ddev->Present(NULL, NULL, NULL, NULL);


	if (KEY_DOWN(VK_ESCAPE))
		PostMessage(hwnd, WM_DESTROY, 0, 0);



}
void Game_End(HWND hwnd)
{
	surface->Release();
	if (d3d != NULL)
		d3d->Release();
}