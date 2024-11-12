#include "Program.h"

flrogram::flrogram() {
	try {
		std::cout << "Append of program ";
		SetType(3);
		int hours, minutes;

		std::cout << "Enter day (e.g., Monday): ";
		std::cin.ignore(256, '\n');
		getline(std::cin, day);
		if (day != "Monday" && day != "Tuesday" && day != "Wednesday" && day != "Thursday" &&
			day != "Friday" && day != "Saturday" && day != "Sunday") {
			throw std::string("Invalid day of the week.");
		}

		std::cout << "Enter time (e.g., 10 43): ";
		std::cin >> hours >> minutes;
		if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
			throw std::string("Incorrect time format.");
		}
		time = std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes);

		std::cout << "Enter report name: ";
		std::cin.ignore(256, '\n');
		getline(std::cin, name);
		if (name.empty()) {
			throw std::string("Name cannot be empty.");
		}
		SetError(false);
	}
	catch (const std::string& err) {
		std::cout << "Error: " << err << std::endl;
		SetError(true);
	}
}

flrogram::flrogram(std::ifstream& fin) {
	SetType(3);
	fin.ignore(256, '\n');
	getline(fin, day);
	getline(fin, time);
	getline(fin, name);
}

flrogram::~flrogram() {
	std::cout << "Object destroyed." << std::endl;
}

void flrogram::edit() {
	try {
		int c;
		std::string stringTemp;
		std::cout << "Choose attribute to change:\n1. Day\n2. Time\n3. Name\nYour choice: ";
		std::cin >> c;

		if (c < 1 || c > 3) {
			throw std::string("Invalid choice.");
		}

		std::cout << "Original value: ";
		switch (c) {
		case 1:
			std::cout << day << "\nNew value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp);
			if (stringTemp != "Monday" && stringTemp != "Tuesday" && stringTemp != "Wednesday" &&
				stringTemp != "Thursday" && stringTemp != "Friday" && stringTemp != "Saturday" && stringTemp != "Sunday") {
				throw std::string("Invalid day of the week.");
			}
			day = stringTemp;
			break;
		case 2:
			int hours, minutes;
			std::cout << time << "\nNew value (e.g., 10 45): ";
			std::cin >> hours >> minutes;
			if (hours < 0 || hours >= 24 || minutes < 0 || minutes >= 60) {
				throw std::string("Incorrect time format.");
			}
			time = std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes);
			break;
		case 3:
			std::cout << name << "\nNew value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp);
			if (stringTemp.empty()) {
				throw std::string("Name cannot be empty.");
			}
			name = stringTemp;
			break;
		}
		SetError(false);
	}
	catch (const std::string& err) {
		std::cout << "Error: " << err << std::endl;
		SetError(true);
	}
}

void flrogram::save(std::ofstream& fout) {
	fout << GetType() << std::endl
		<< day << std::endl
		<< time << std::endl
		<< name << std::endl;
}

void flrogram::show(std::ostream& out) {
	out << "Program: " << std::endl
		<< "Day: " << day << std::endl
		<< "Time: " << time << std::endl
		<< "Name: " << name << std::endl;
}
