#include "flarticipant.h"

flarticipant::flarticipant() {
	try {
		std::cout << "Append of participant ";
		SetType(1);

		std::cout << "Enter FIO: ";
		std::cin.ignore(256, '\n');  // Очистка буфера ввода
		getline(std::cin, FIO);
		if (FIO.empty()) {
			throw std::string("FIO cannot be empty");
		}

		std::cout << "Enter University or Organization: ";
		getline(std::cin, organization);
		if (organization.empty()) {
			throw std::string("Organization cannot be empty");
		}

		std::cout << "Enter your report: \n";
		getline(std::cin, report);
		if (report.empty()) {
			throw std::string("Report cannot be empty");
		}

		std::cout << "Enter your annotation: \n";
		getline(std::cin, annotation);
		if (annotation.empty()) {
			throw std::string("Annotation cannot be empty");
		}

		SetError(false);  // Ошибок нет
	}
	catch (const std::string& err) {
		std::cout << "Error: " << err << std::endl;
		SetError(true);
	}
}


flarticipant::flarticipant(std::ifstream& fin) {
	SetType(1);
	fin.ignore(256, '\n'); 
	getline(fin, FIO);
	//fin.ignore(256, '\n'); getline(fin, organization);
	//fin.ignore(256, '\n'); getline(fin, report);
	//fin.ignore(256, '\n'); getline(fin, annotation);
}

flarticipant::~flarticipant() {
	std::cout << "BAAAAAAAAAAAAAAAAAAM ";
}

void flarticipant::edit() {
	try {
		int c, iTemp; std::string stringTemp;
		std::cout << "Choose attribute to change: \n1. FIO\n2. Organization\n3. Report\n4.Annotation\nYour choice : "; 
		std::cin>> c;
			if (c < 1 || c >4) {
				throw (std::string)"Wrong index! ";
			}
		std::cout << "Original value: "; switch (c) {
		case 1:
			std::cout << FIO;
			std::cout << " ew value: "; std::cin.ignore(256, '\n'); 
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"FIO can not be empty ";

			}
			FIO = stringTemp; break;
		case 2:
			std::cout << organization; std::cout << " ew value: "; std::cin.ignore(256, '\n'); 
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"Organization can not be empty ";
			}
			organization = stringTemp; break;
		case 3:
			std::cout << report; 
			std::cout << " ew value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"Report can not be empty ";
			}
			report = stringTemp; break;
		case 4:
			std::cout << annotation; 
			std::cout << " ew value: ";
			std::cin.ignore(256, '\n'); 
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"Annotation can not be empty ";
			}
			annotation = stringTemp; break;
		default:
			break;
		}
		SetError(false);
	}
	catch (std::string err) {
		std::cout << "Error " + err; SetError(true);
	}
}

void flarticipant::save(std::ofstream &fout) {
	fout << GetType() << std::endl
		<< this->FIO << std::endl
		<< this->organization << std::endl
		<< this->report << std::endl
		<< this->annotation << std::endl;
}

void flarticipant::show(std::ostream & out) {
	out << "flarticipant: " << std::endl
		<< "FIO: " << FIO << std::endl
		<< "Organization " << organization << std::endl
		<< "Report\n" << report << std::endl
		<< "Annotation\n" << annotation << std::endl;
}
