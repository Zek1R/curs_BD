#include "App.h"

App::App() {
	group;
	groups;
	groups_count = 0;
	comand;
}


int App::ValidComand() {
	string precomand;
	cin >> precomand;

	if (precomand == "0") { return 0; };
	if (precomand == "1") { return 1; };
	if (precomand == "2") { return 2; };
	if (precomand == "3") { return 3; };

	return 9;
}

void App::NewGroup() {
	group.SetGroup();
	groups_count += 1;
	groups.push_back(this->group);
}

void App::ChooseGroup() {
	int group_id;

	cout << "������� ����� ������\n\n>> ";
	cin >> group_id;

	if (group_id <= groups_count && group_id > 0) {
		cout << "\033[2J\033[1;1H";
		groups[group_id - 1].GroupCommander();
	}
	else {
		cout << "����� ������ ���\n";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}


void App::DeleteGroup() {
	short int stud_id;
	cout << "������� ����� ������\n\n>> ";
	cin >> stud_id;
	stud_id = stud_id - 1;
	if ((stud_id >= 0) && (stud_id < 35) && (stud_id < groups_count)) {
		cout << "\033[2J\033[1;1H";
		groups.erase(groups.begin() + stud_id);
		groups_count = groups_count - 1;
	}
	else {
		cout << "����� ������ �� ����������";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}


void App::PrintGroups() const {
	if (this->groups_count > 0) {
		cout << "------ ������ ����� ------" << endl << endl;
		for (int i = 0; i < this->groups_count; i++) {
			std::cout << i + 1 << " - ";
			cout << groups[i].GetName() << endl;
		}
	}
	else {
		cout << "------ �� ������� �� ����� ������ ------" << endl << endl;
	}
	cout << endl;
}


void App::AppComander() {
	bool run = true;
	string precomand;
	while (run) {
		PrintGroups();

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			"������� �������\n\n"
			"(1) - �������� ������\n"
			"(2) - ������� � ������\n"
			"(3) - ������� � ������\n"
			"(0) - �����\n"
			"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
			"\n\n>>  ";
		
		comand = ValidComand();
		cout << endl;

		switch (comand) {
		case 1:
			NewGroup();
			cout << "\033[2J\033[1;1H";
			break;
		case 2:
			ChooseGroup();
			cout << "\033[2J\033[1;1H";
			break;
		case 3:
			DeleteGroup();
			break;
		case 0:
			run = false;
			break;
		default:
			cout << "������������ �������";
			Sleep(500);
			cout << "\033[2J\033[1;1H";
		}
	}
}



