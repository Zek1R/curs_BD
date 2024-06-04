#include "Group.h"

char Group::Comand() {
	string c;
	cout << "������� �������\n";
	cout << "--------------------------" << endl;
	cout << "(1) �������� ��������\n(2) �������� ��������\n(3) ������� ��������\n(0) - �����\n\n>> ";
	cin >> c;
	if ((c == "0") || (c == "1") || (c == "2") || (c == "3")) {
		return c[0];
	}
	else {
		cout << "������������ �������." << endl;
		cin.clear();
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}

Group::Group() {
	student;
	students;
	comand;
	student_count = 0;
}

void Group::AddStudent() {
	if (this->student_count <= 35) {
		cout << "\033[2J\033[1;1H";
		student.SetStudent();
		students.push_back(this->student);
		this->student_count = this->student_count + 1;
	}
	else {
		cout << "������ ��������� �� ��������" << endl;
	}
}

void Group::PrintGroup() const {
	if (this->student_count > 0) {
		cout << "------ ������ ��������� ------" << endl << endl;
		for (int i = 0; i < this->student_count; i++) {
			std::cout << i+1 << " - ";
			students[i].PrintName();
		}
	}
	else {
		cout << "------ � ������ ��� �� ������ �������� ------" << endl << endl;
	}
}

void Group::EditStudent() {
	short int stud_id;
	cout << "\033[2J\033[1;1H";
	cout << "������� ����� ��������\n\n>> ";
	cin >> stud_id;
	stud_id = stud_id - 1;
	if ((stud_id >= 0) && (stud_id < 35) && (stud_id < student_count)) {
		cout << "\033[2J\033[1;1H";
		students[stud_id].StudentCommander();
	}
	else {
		cout << "\n������ �������� �� ����������";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}

void Group::DeleteStudent() {
	short int stud_id;
	cout << "\033[2J\033[1;1H";
	cout << "������� ����� ��������\n\n>> ";
	cin >> stud_id;
	stud_id = stud_id - 1;
	if ((stud_id >= 0) && (stud_id < 35) && (stud_id < student_count)) {
		cout << "\033[2J\033[1;1H";
		students.erase(students.begin() + stud_id);
		student_count = student_count - 1;
	}
	else {
		cout << "\n������ �������� �� ����������";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}



void Group::GroupCommander() {
	
	char comand = ' ';
	bool isRun = true;

	while (isRun) {
		PrintGroup();
		cout << endl;
		comand = Comand();
		
		switch (comand) {
		case '1':
			AddStudent();
			cout << "\033[2J\033[1;1H";
			break;
		case '2':
			EditStudent();
			cout << "\033[2J\033[1;1H";
			break;
		case '3':
			DeleteStudent();
			cout << "\033[2J\033[1;1H";
			break;
		case '0':
			isRun = false;
			break;
		default:
			break;
		}
	}
}



