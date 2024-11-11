#include "Program.h"

flrogram::flrogram() {
	std::cout << "Append of program "; try {
		SetType(3);
		int hours, minutes;

		std::cout << "Enter day like (Monday): "; 
		std::cin.ignore(256, '\n'); 
		getline(std::cin, day);
		if (day != "Monday" && day != "Tuesday " && day != "Wednesday " && day
			!= "Thursday " && day != "Friday " && day != "Saturday " && day != "Sunday ") {
			throw (std::string)"Day can not be empty ";
		}
		std::cout << "Enter time like (10:43): "; 
		std::cin >> hours >> minutes;
		if ((hours > 24 || hours < 0) || (minutes > 60 || minutes < 0)) {
			throw (std::string)"Incorrect type of time ";
		}
		time = std::to_string(hours) + ": " + std::to_string(minutes); 
		std::cout << "Enter name of report: ";
		std::cin.ignore(256, '\n'); 
		getline(std::cin, name);
		if (name == "") {
			throw (std::string)" ame can not be empty ";
		}
		SetError(false);
	}
	catch (std::string err) {
		std::cout << "Error " + err; SetError(true);
	}
}

flrogram::flrogram(std::ifstream& fin) {
	SetType(3);
	fin.ignore(256, '\n'); 
	getline(fin, day);
	//fin.ignore(256, '\n'); getline(fin, time);
	//fin.ignore(256, '\n'); getline(fin, name);
}


flrogram::~flrogram() {
	std::cout << " BAAAAAAAAAAAAAAAAAAAAM ";
	system("pause");
}


void flrogram::edit() {
	try {
		int c, iTemp; std::string stringTemp;
		std::cout << "Choose attribute to change: \n1. FIO\n2. Organization\n3. Report\n4.Annotation\nYour choice : "; 
		std::cin >> c;
			if (c < 1 || c >3) {
				throw (std::string)"Wrong index! ";
			}
		std::cout << "Original value: "; switch (c) {
		case 1:
			std::cout << day;
			std::cout << " ew value: "; std::cin.ignore(256, '\n'); getline(std::cin, stringTemp);
			if (day != "Monday " && day != "Tuesday " && day != "Wednesday " && day != "Thursday " && day != "Friday "	&& day != "Saturday " && day != "Sunday ") {
				throw (std::string)"Day can not be empty ";

			}
			day = stringTemp; break;
		case 2:
			int hours, minutes; std::cout << time;
			std::cout << " ew value like(10:45): "; std::cin >> hours >> minutes;
			if ((hours > 24 || hours < 0) || (minutes > 60 || minutes < 0))
			{
				throw (std::string)" Incorrect type of time ";
			}
			stringTemp = std::to_string(hours) + ":" +
				std::to_string(minutes);
			time = stringTemp; break;
		case 3:
			std::cout << name; std::cout << " ew value: "; std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp); if (stringTemp == "") {
				throw(std::string)"  ame can not be empty ";
			}
			name = stringTemp; break;


		default:
			break;
		}
		SetError(false);
	}
	catch (std::string err) {
		std::cout << " Error " + err; SetError(true);
	}
}


void flrogram::save(std::ofstream& fout) {
	fout << GetType() << std::endl
		<< this->day << std::endl
		<< this->time << std::endl
		<< this->name << std::endl;
}

void flrogram::show(std::ostream& out) {
	out << "flrogram: " << std::endl
		<< "Day: " << day << std::endl
		<< "Time: " << time << std::endl
		<< " ame: " << name << std::endl;
}
