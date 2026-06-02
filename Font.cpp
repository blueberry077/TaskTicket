// Task Ticket - Ultra-lean and Ultra-simple Win32 desktop application for daily routines.
// Copyright (C) 2026 Marc-Daniel DALEBA
// License: GPLv3
#include "Font.h"

Font::Font() {}
Font::~Font() {
	if (hfont)
		DeleteObject(hfont);
}
int Font::LoadFont(HDC hdc, std::wstring faceName, int Weight, float PointSize)
{
	int nFontSize = -MulDiv(PointSize, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	hfont = CreateFont(
		nFontSize, 0,
		0, 0, Weight * 100,
		FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		FF_DONTCARE, faceName.c_str());
	return 0;
}