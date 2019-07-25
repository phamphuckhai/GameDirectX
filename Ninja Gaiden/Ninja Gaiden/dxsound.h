#pragma once
// dxaudio.h - DirectSound framework header file
#ifndef _DXAUDIO_H
#define _DXAUDIO_H
#include "dsutil.h"
#include "Game.h"
#include"Global.h"
#include<cstring>
#include<stdio.h>
#include<iostream>
#include <string>
#include<string.h>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <atlstr.h>
#include <winnt.h>
typedef LPWSTR PTSTR, LPTSTR;
//primary DirectSound object
class DxSound {
	static DxSound* m_instance;
	DxSound();
public:
	static DxSound* GetInstance();
	CSoundManager *CSManager;
	CSound* LoadSound;
	void create(LPTSTR name);
};
#endif