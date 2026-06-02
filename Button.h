// Task Ticket - Ultra-lean and Ultra-simple Win32 desktop application for daily routines.
// Copyright (C) 2026 Marc-Daniel DALEBA
// License: GPLv3
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <cmath>
#include <functional>

#include "App.h"
#include "Color.h"

// circle buttons for the close and minimize

class Button {
public:
	Button();
	~Button();
public:
	void Create(App* _parent, int _x, int _y, int _rad, Color _color);
	void Update();
public:
	int x = 0, y = 0; // button center
	int radius = 0;
	Color color;
	std::function<void()> callback = nullptr;
	App* parent = nullptr;
};
