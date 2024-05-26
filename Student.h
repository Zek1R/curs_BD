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
			cout << "������� ���� �������� (����� ������)\n>> ";
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
		cout << this->day << '.' << this->month << '.' << this->year << endl; // ����� �������, ����� ����� ���������
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
		cout << "������� {������� ��� ��������} �������� (����� ������)\n>> ";
		cin >> this->name;
		cin >> this->surname;
		cin >> this->patronymic;
	}

	void PrintName() const {
		cout << this->name << ' ' << this->surname << ' ' << this->patronymic << endl; // ����� �������, ����� ������ ���������
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
		cout << "������� ��� �����������\n>> ";
		cin >> entryYear;
	}

	void SetFaculty() {
		cout << "������� ��������\n>> ";
		cin >> faculty;
	}

	void SetCathedra() {
		cout << "������� ������� (��������: ��-2)\n>> ";
		cin >> cathedra;
	}

	void SetGroup() {
		cout << "������� ������ (��������: ����-01-23)\n>> ";
		cin >> group;
	}

	void SetStudentID() {
		cout << "������� ����� �������� ������\n>> ";
		cin >> studentID;
	}

	void SetSex() {
		cout << "������� ��� (� / �)\n>> ";
		cin >> sex;
	}

	void PrintStudent() const {
		for (int i = 0; i < 80; i++) cout << '-';
		cout << endl;
		studentName.PrintName();
		birthDate.PrintDate();
		cout << "��� ����������� - " << this->entryYear << endl;
		cout << "�������� - " << this->faculty << endl;
		cout << "������� - " << this->cathedra << endl;
		cout << "������ - " << this->group << endl;
		cout << "����� ������� - " << this->studentID << endl;
		cout << "��� - " << this->sex << endl;
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
			cout << "������� �� ���������.";
		}
	}
	
	void SetStudentInfo() {
		char command = ' ';
		bool isRun = true;
		while (isRun) {
			cout << "������� ��� �� ������ ��������\n";
			cout << "|(0) - �����|(1) ��� �����������|(2) ��������|(3) �������|\n|(4) ������|(5) ����� �������� ������|(6) ���|\n>> ";
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
				cout << "�������� �������\n";
				break;
			}
		}
	}
};

#endif // !STUDENT_H
