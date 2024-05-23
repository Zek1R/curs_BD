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

	bool ValidDate() {

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
	
			cout << "Введите дату рождения через пробел >> ";
			cin >> day;
			cin >> month;
			cin >> year;
	}

	Date(unsigned int d, unsigned int m, unsigned int y){
		cin >> d;
		cin >> m;
		year = y;
		ValidDate();
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
	
	void PrintDate() {
		cout << this->day << '.' << this->month << '.' << this->year << endl;
	}
};



#endif // !STUDENT_H
