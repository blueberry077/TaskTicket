// Task Ticket - Ultra-lean and Ultra-simple Win32 desktop application for daily routines.
// Copyright (C) 2026 Marc-Daniel DALEBA
// License: GPLv3
#include "Button.h"

Button::Button() {}
Button::~Button() {}

void Button::Create(App* _parent, int _x, int _y, int _rad, Color _color)
{
	parent = _parent;
	x = _x;
	y = _y;
	radius = _rad;
	color = _color;
}

void Button::Update()
{
	if (!parent)
		return;

	POINT ms;
	GetCursorPos(&ms);
	ScreenToClient(parent->hwnd, &ms);

	int dx = ms.x - x;
	int dy = ms.y - y;
	if (dx * dx + dy * dy <= radius * radius) {
		if (callback && parent->mouse_down)
			callback();
	}
}