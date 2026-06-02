// Task Ticket - Ultra-lean and Ultra-simple Win32 desktop application for daily routines.
// Copyright (C) 2026 Marc-Daniel DALEBA
// License: GPLv3

#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <string>

class Font {
public:
	Font();
	~Font();
public:
	int LoadFont(HDC hdc, std::wstring faceName, int Weight, float PointSize);
public:
	HFONT hfont;
};

