#include "StudentWindow.h"

StudentWindow::StudentWindow() {
	precomand = " ";
	comand = ' ';
	student;
}


bool StudentWindow::ValidComand(string comnd) {

	if ((comnd == "0") || (comnd == "1") || (comnd == "2") || (comnd == "3")) {
		return true;
	}
	else {
		cout << comnd << " ������������ �������!\n";
		Sleep(1000);
		return false;
	}
}

bool StudentWindow::StudentCommander() {
	cout << "\033[2J\033[1;1H";
	cout << "������� �������\n|1 - �������|2 - ����|3 - �����|0 - �����|\n>> ";
	cin >> precomand;
	if (ValidComand(precomand)) {
		
		comand = precomand[0];
	}

	cout << "--------------------------------------------------------------------\n";
	switch(comand) {
	case '1':
		student.SetStudent();
		break;
	case '2':
		student.SetStudentInfo();
		break;
	case '3':
		student.PrintStudent();
		
		break;
	case '0':
		return false;
		break;
	}
}