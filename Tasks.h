// Task Ticket - Ultra-lean and Ultra-simple Win32 desktop application for daily routines.
// Copyright (C) 2026 Marc-Daniel DALEBA
// License: GPLv3
#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct SingleTask {
	std::string name;
	bool check = false;
};

class Tasks {
public:
	Tasks();
	~Tasks();
public:
	void IniTasks();
	void LoadTaskFile(std::string _filename);
	void ToggleTaskState(int index);
	void AddTask(std::string name); // task will be append and unchecked
public:
	std::string filename;
	std::vector<SingleTask> mTasks;
	int selected = 0;
};

