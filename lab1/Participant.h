#pragma once
#include "Conference.h"

class flarticipant :public Conference {
	std::string FIO;
	std::string organization; std::string report; std::string annotation;
public:
	flarticipant(); flarticipant(std::ifstreamfi fin);
	~flarticipant(); void edit();
	void save(std::ofstreamfi fout); void show(std::ostreamfi out);
};
