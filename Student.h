#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <Windows.h>
#include <string>


using namespace std; 

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

	bool ValidDate() const {

		bool IsValid = false;

		if (!(month < 0) && !(month > 12))
		{

			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if ((day > 0) && (day <= 31))
				{
					return true;
				}
			}

			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if ((day > 0) && (day <= 30))
				{
					return true;
				}
			}

			if (month == 2)
			{
				if (!(year % 4 == 0)) {
					if ((day > 0) && (day <= 28)) {
						return true;
					}
				}
				else {
					if ((day > 0) && (day <= 29)) {
						return true;

					}
				}
			}
		}

		cout << "Invalid date. Please input correct date.\n";
		return IsValid;
	}

public:
	Date() {
		day;
		month;
		year;
	}

	void setDate(){
		cout << "Введите дату рождения (через пробел)\n>> ";
		cin >> day;
		cin >> month;
		cin >> year;
	}

	unsigned int GetDays() const {
		return this->day;
	};
	unsigned int GetMonths() const {
		return this->month;
	};
	unsigned int GetYears() const {
		return this->year;
	};
	
	void PrintDate() const {
		cout << this->day << '.' << this->month << '.' << this->year << endl;
	}
};

class Name {
private:
	string name;
	string surname;
	string patronymic;

public:
	Name() {
		name = "";
		surname = "";
		patronymic = "";
	}

	void setName() {
		cout << "Введите Имя Фамилию Отчество студента через пробел\n>> ";
		cin >> this->name;
		cin >> this->surname;
		cin >> this->patronymic;
	}

	void PrintName() const {
		cout << this->name << ' ' << this->surname << ' ' << this->patronymic << endl;
	}

	string GetName() const {
		return this->name;
	};
	string GetSurname() const {
		return this->surname;
	};
	string GetPatronym() const {
		return this->patronymic;
	};
};


#endif // !STUDENT_H
