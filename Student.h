#ifndef STUDENT_H
#define STUDENT_H

#include "Marks.h"


using namespace std; 

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

	bool ValidDate(unsigned int day, unsigned int  month, unsigned int year) {

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

		cout << "!! Invalid date. Please input correct date. !!\n";
		return IsValid;
	}

public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	};

	void SetDate(){
		unsigned int d, m, y;
		bool v = false;

		while (v == false) {
			cout << "Введите дату рождения (через пробел)\n>> ";
			cin >> d;
			cin >> m;
			cin >> y;
			v = ValidDate(d, m, y);
		}

		day = d;
		month = m;
		year = y;
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
		cout << this->day << '.' << this->month << '.' << this->year << endl; // потом удалить, когда будет интерфейс
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

	void SetName() {
		cout << "Введите {Фамилию Имя Отчество} студента (через пробел)\n>> ";
		cin >> this->name;
		cin >> this->surname;
		cin >> this->patronymic;
	}

	void PrintName() const {
		cout << this->name << ' ' << this->surname << ' ' << this->patronymic << endl; // потом удалить, когда сделаю интерфейс
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


class Student {
private:
	Name studentName;
	Date birthDate;
	unsigned int entryYear;
	string faculty;
	string cathedra;
	string group;
	string studentID;
	char sex;
	SemMark semMark;
	bool semInit;

public:
	Student() {
		studentName;
		birthDate;
		entryYear;
		faculty;
		cathedra;
		group;
		studentID;
		sex = ' ';
		semMark;
		semInit = false;

	}

	void SetStudent() {
		studentName.SetName();
		birthDate.SetDate();
		semMark;
	}

	void SetEntryYear() {
		cout << "Введите год поступления\n>> ";
		cin >> entryYear;
	}

	void SetFaculty() {
		cout << "Введите институт\n>> ";
		cin >> faculty;
	}

	void SetCathedra() {
		cout << "Введите кафедру (Например: КБ-2)\n>> ";
		cin >> cathedra;
	}

	void SetGroup() {
		cout << "Введите группу (Например: БИСО-01-23)\n>> ";
		cin >> group;
	}

	void SetStudentID() {
		cout << "Введите номер зачётной книжки\n>> ";
		cin >> studentID;
	}

	void SetSex() {
		cout << "Введите пол (М / Ж)\n>> ";
		cin >> sex;
	}

	void PrintStudent() const {
		for (int i = 0; i < 80; i++) cout << '-';
		cout << endl;
		studentName.PrintName();
		birthDate.PrintDate();
		cout << "Год поступления - " << this->entryYear << endl;
		cout << "Институт - " << this->faculty << endl;
		cout << "Кафедра - " << this->cathedra << endl;
		cout << "Группа - " << this->group << endl;
		cout << "Номер зачётки - " << this->studentID << endl;
		cout << "Пол - " << this->sex << endl;
		for (int i = 0; i < 80; i++) cout << '-';
		cout << endl;
	}

	void SetSemMark() {
		semMark.SetSem();
		semInit = true;

	}

	void PrintMarks() {
		if (semInit == true){
			semMark.PrintSem();
		}
		else {
			cout << "Таблица не заполнена.";
		}
	}
	
	void SetStudentInfo() {
		char command = ' ';
		bool isRun = true;
		while (isRun) {
			cout << "Введите что вы хотите изменить\n";
			cout << "|(0) - Выход|(1) Год поступления|(2) Институт|(3) Кафедру|\n|(4) Группу|(5) Номер зачётной книжки|(6) Пол|\n>> ";
			cin >> command;

			switch (command) {
			case '1':
				SetEntryYear();
				break;
			case '2':
				SetFaculty();
				break;
			case '3':
				SetCathedra();
				break;
			case '4':
				SetGroup();
				break;
			case '5':
				SetStudentID();
				break;
			case '6':
				SetSex();
				break;
			case '0':
				isRun = false;
				break;
			default:
				cout << "Неверная команда\n";
				break;
			}
		}
	}
};

#endif // !STUDENT_H
