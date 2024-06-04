#include "Student.h"

// class Date

bool Date::ValidDate(unsigned int day, unsigned int  month, unsigned int year) {

	if ((month > 0) && (month <= 12)) {

		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if ((day > 0) && (day <= 31)) {
				return true;
			}
		}

		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if ((day > 0) && (day <= 30)) {
				return true;
			}
		}

		if (month == 2) {
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
	else { return false; }
}

Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}

bool Date::SetDate() {
	unsigned int d, m, y;
	bool v = false;


	while (v == false) {
		cout << "������� ���� �������� (����� ������)\n\n>> ";
		cin >> d;
		if ((d <= 0) || (d > 31)) {
			cin.clear();
			cin.clear();
			cin.clear();
			cout << "\nInvalid date\n" << endl;
			return false;
			break;
		}
		cin >> m;
		if ((m <= 0) || (m > 12)) {
			cin.clear();
			cin.clear();
			cin.clear();
			cout << "\nInvalid date\n" << endl;
			return false;
			break;
		}
		cin >> y;
		if ((y <= 1500) || (y > 3000)) {
			cin.clear();
			cin.clear();
			cin.clear();
			cout << "\nInvalid date\n" << endl;
			return false;
			break;
		}

		
		if (!ValidDate(d, m, y)) {
			cout << "\nInvalid date\n" << endl;
		}
		else { v = true; }
		
		if (v == true) {
			this->day = d;
			this->month = m;
			this->year = y;
			return true;
			break;
		}
	}

}

unsigned int Date::GetDays() const {
	return this->day;
};
unsigned int Date::GetMonths() const {
	return this->month;
};
unsigned int Date::GetYears() const {
	return this->year;
};

void Date::PrintDate() const {
	cout << this->day << '.' << this->month << '.' << this->year << endl;
}




// class Name

Name::Name() {
	name = "";
	surname = "";
	patronymic = "";
}

void Name::SetName() {
	cin.clear(); 
	cin.clear();
	cin.clear();
	
	cout << "������� ������� ��� �������� ��������\n\n! ������ '������ ���� ��������' (����� ������)\n\n>> ";
	cin >> this->name;
	cin >> this->surname;
	cin >> this->patronymic;
}

string Name::GetName() const {
	return this->name;
};

string Name::GetSurname() const {
	return this->surname;
};
	
string Name::GetPatronym() const {
	return this->patronymic;
};

void Name::PrintName() const {
	cout << this->name << ' ' << this->surname << ' ' << this->patronymic << endl;
}




// class Student

Student::Student() {
	studentName;
	birthDate;
	entryYear = 0;
	faculty;
	cathedra;
	group;
	studentID;
	sex = '\b';
	studInit = false;
	sems;
	semInit = false;
	comand = ' ';
	}

void Student::SetStudent() {
	studentName.SetName();
	cout << endl;
	bool d_valid = false;
	while (d_valid != true) { d_valid = birthDate.SetDate(); }
	studInit = true;
}

void Student::SetEntryYear() {
	cout << "������� ��� �����������\n>> ";
	cin >> this->entryYear;
}

void Student::SetFaculty() {
	cout << "������� ��������\n>> ";
	cin >> this->faculty;
}

void Student::SetCathedra() {
	cout << "������� ������� (��������: ��-2)\n>> ";
	cin >> this->cathedra;
}

void Student::SetGroup() {
	cout << "������� ������ (��������: ����-01-23)\n>> ";
	cin >> this->group;
}

void Student::SetStudentID() {
	cout << "������� ����� �������� ������\n>> ";
	cin >> this->studentID;
}

void Student::SetSex() {
	cout << "������� ��� (� / �)\n>> ";
	cin >> this->sex;
	}

void Student::PrintName() const{
	studentName.PrintName();
}

void Student::PrintStudent() const {
	if (this->studInit) {
		cout << "��� - ";
		studentName.PrintName();
		cout << "���� �������� - ";
		birthDate.PrintDate();
		cout << "��� ����������� - " << this->entryYear << endl;
		cout << "�������� - " << this->faculty << endl;
		cout << "������� - " << this->cathedra << endl;
		cout << "������ - " << this->group << endl;
		cout << "����� ������� - " << this->studentID << endl;
		cout << "��� - " << this->sex << endl;
		cout << endl;
		for (int i = 0; i < 30; i++) { cout << "-"; }
		cout << endl;

	}
}

void Student::SetMarks() {
	if (studInit) {
		sems.SetSems();
		semInit = true;
	}
}

void Student::PrintMarks() {
	if (this->semInit == true) {
		sems.PrintSems();
	}
	else {
		cout << "������� �� ���������.";
	}
}

void Student::SetStudentInfo() {
	char command = ' ';
	bool isRun = true;
	while (isRun) {
		cout << "\033[2J\033[1;1H";
		PrintStudent();
		cout << "������� ��� �� ������ ��������\n";
		cout << "|(1) ��� �����������       |\n|(2) ��������              |\n|(3) �������               |\n|(4) ������                |\n|(5) ����� �������� ������ |\n|(6) ���                   |\n|(0) �����                 |\n\n>> ";
		
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

bool Student::ValidComand(string comnd) {

	if ((comnd == "0") || (comnd == "1") || (comnd == "2") || (comnd == "3") || (comnd == "4") || (comnd == "5")) {
		return true;
	}
	else {
		cout << comnd << " ������������ �������!\n";
		Sleep(1000);
		return false;
	}
}

void Student::StudentCommander() {
	
	bool run = true;

	while (run) {

		cout << "\033[2J\033[1;1H";
		PrintStudent();
		cout << "������� �������\n\n";
		cout << "| 1 - ����           |\n| 2 - ������ ������  |\n| 3 - ������� ������ |\n| 0 - �����          |\n\n>> ";
		string precomand;
		cin >> precomand;
		if (ValidComand(precomand)) {

			comand = precomand[0];
		}

		switch (comand) {
		case '1':
			cout << "\033[2J\033[1;1H";
			SetStudentInfo();
			cout << "���������� ���������";
			break;
		case '2':
			cout << "\033[2J\033[1;1H";
			SetMarks();
			break;
		case '3':
			cout << "\033[2J\033[1;1H";
			PrintMarks();
			cout << "������� ����� ������, ����� ���������� >> ";
			cin >> s;
			cin.clear();
			s = "";
			break;
		case '0':
			run = false;
			break;
		default:
			break;
		}
	}
}