#pragma once
#include "Conference.h"

class flarticipant :public Conference {
	std::string FIO;
	std::string organization; std::string report; std::string annotation;
public:
	flarticipant(); flarticipant(std::ifstream& fin);
	~flarticipant(); void edit();
	void save(std::ofstream& fout); 
	void show(std::ostream& out);
};
