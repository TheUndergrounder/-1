#pragma once
#include <string>
#include <fstream>
class Conference {
	int type;
	bool error;
	void SetType(int);
	int GetType();
	bool IsError();
	void SetError(bool);
};
