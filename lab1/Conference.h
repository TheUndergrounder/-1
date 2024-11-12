#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
class Conference {
	int type;
	bool error;
public:
	void SetType(int);
	int GetType();
	bool IsError();
	virtual void save(std::ofstream& fout) = 0;
	virtual void edit() = 0;
	virtual void show(std::ostream& out) = 0;
	void SetError(bool);
	~Conference();
};
