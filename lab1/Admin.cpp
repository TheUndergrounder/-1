#include "Admin.h"

Administrator::Administrator() {
	try {
		std::cout << "Append of Administrator\n";
		SetType(2);

		std::cout << "Enter FIO: ";
		std::cin.ignore(256, '\n');  // Очистка буфера ввода
		getline(std::cin, FIO);
		if (FIO.empty()) {
			throw std::string("FIO cannot be empty");
		}

		std::cout << "Enter position: ";
		getline(std::cin, position);
		if (position.empty()) {
			throw std::string("Position cannot be empty");
		}

		std::cout << "Enter zone of responsibility: ";
		getline(std::cin, responsibility);
		if (responsibility.empty()) {
			throw std::string("Responsibility cannot be empty");
		}

		SetError(false);  // Ошибок нет
	}
	catch (const std::string& err) {
		std::cout << "Error: " << err << std::endl;
		SetError(true);
	}
}

Administrator::Administrator(std::ifstream &fin) {
	SetType(2);
	fin.ignore(256, '\n'); 
	getline(fin, FIO); 
	fin.ignore(256, '\n');
	getline(fin, position);
	//fin.ignore(256, '\n'); getline(fin, responsibility);
}

Administrator::~Administrator() {
	std::cout << "BAAAAAAAAAAM ";
}

void Administrator::edit() {
	try {
		int c, iTemp; std::string stringTemp;
		std::cout << "Choose attribute to change: \n1. FIO\n2. flosition\n3. Responsibility\nYour choice is : ";

			std::cin >> c;
		if (c < 1 || c>3) {
			throw(std::string)"Wrong index! ";
		}
		std::cout << "Original value: "; switch (c) {
		case 1:
			std::cout << FIO;
			std::cout << " ew value: "; 
			std::cin.ignore(256, '\n'); 
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"FIO can not be empty ";
			}
			FIO = stringTemp; break;
		case 2:
			std::cout << position; 
			std::cout << " ew value: "; 
			std::cin.ignore(256, '\n'); 
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"flosition can not be empty ";
			}
			position = stringTemp; break;
		case 3:
			std::cout << responsibility; 
			std::cout << " ew value: "; 
			std::cin.ignore(256, '\n'); 
			getline(std::cin, stringTemp); 
			if (stringTemp == "") {
				throw(std::string)"Responsebility can not be empty ";
			}
			responsibility = stringTemp; break;
		default:
			break;
		}
		SetError(false);
	}
	catch (std::string err) {
		std::cout << "Error " + err; SetError(true);
	}
}

void Administrator::save(std::ofstream& fout) {
	fout << GetType() << std::endl
		<< this->FIO << std::endl
		<< this->position << std::endl
		<< this->responsibility << std::endl;
}

void Administrator::show(std::ostream& out) {
	out << "Administrator: " << std::endl
		<< "FIO: " << FIO << std::endl
		<< "flosition " << position << std::endl
		<< "Responsebility " << responsibility << std::endl;

}
