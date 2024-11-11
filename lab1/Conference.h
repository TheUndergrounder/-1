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
	void SetError(bool);
};
