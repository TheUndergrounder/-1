#pragma once
#include "Conference.h"

class flrogram :public Conference {
	std::string day; std::string name; std::string time;

public:

	flrogram(); flrogram(std::ifstream& fin);
	~flrogram(); 
	void edit();
	void save(std::ofstream& fout); 
	void show(std::ostream& out);
};
