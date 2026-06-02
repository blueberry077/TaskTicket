// Task Ticket - Ultra-lean and Ultra-simple Win32 desktop application for daily routines.
// Copyright (C) 2026 Marc-Daniel DALEBA
// License: GPLv3
#include "Tasks.h"

Tasks::Tasks() {}
Tasks::~Tasks() {}

void Tasks::IniTasks()
{
	std::stable_sort(mTasks.begin(), mTasks.end(), [](const SingleTask& a, const SingleTask& b) {
		return a.check < b.check;
		});
}
void Tasks::LoadTaskFile(std::string _filename)
{
	filename = _filename;
	std::fstream file;
	file.open(filename, std::ios::in);
	if (file.is_open()) {
		mTasks.clear();

		std::string sa;
		while (std::getline(file, sa)) {
			AddTask(sa);
		}
		file.close();
	}
}
void Tasks::ToggleTaskState(int index)
{
	if (index >= mTasks.size())
		return;
	mTasks[index].check ^= 1;
	IniTasks();
}

void Tasks::AddTask(std::string name)
{
	SingleTask task;
	task.name = name;
	task.check = false;
	mTasks.push_back(task);
}