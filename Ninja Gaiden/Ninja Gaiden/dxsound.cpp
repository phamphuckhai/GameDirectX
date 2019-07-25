#include"dxsound.h"
DxSound* DxSound::m_instance = NULL;
DxSound* DxSound::GetInstance()
{
	if (m_instance == NULL)
		m_instance = new DxSound();
	return m_instance;
}
DxSound::DxSound()
{
	CSManager = 0;
	CSManager = new CSoundManager();
	HRESULT result;
	result = CSManager->Initialize(CGame::GetInstance()->GetWindowHhandle(), DSSCL_PRIORITY);
	// Set stereo, 22kHz, 16-bit output. 
	result = CSManager->SetPrimaryBufferFormat(2, 22050, 16);
	// Load the wave file into a DirectSound buffer 
	CSound *pSnd = 0;
	CString str = "Stage1.wav";
	LPTSTR lptszStr = str.GetBuffer(0);
	str.ReleaseBuffer();//fail
	/*LPTSTR str = L"Hello";*/
	//const char* c_str = "Stage1.wav";
	//LPSTR str = const_cast<LPSTR>(c_str);//FAIL
	//
	/*LPWSTR str = _T("Stage1");*/
	result = CSManager->Create(&LoadSound, lptszStr, 0, GUID_NULL);
	// Set dwFlags = 0 for one-shot, or set it to DSBPLAY_LOOPING for looping 
	result = LoadSound->Play(0, 0);
}
void DxSound::create(LPTSTR name)
{

}