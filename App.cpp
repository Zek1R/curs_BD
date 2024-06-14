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

	cout << "Введите номер группы\n\n>> ";
	cin >> group_id;

	if (group_id <= groups_count && group_id > 0) {
		cout << "\033[2J\033[1;1H";
		groups[group_id - 1].GroupComander();
	}
	else {
		cout << "Такой группы нет\n";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}


void App::DeleteGroup() {
	short int stud_id;
	cout << "Введите номер группы\n\n>> ";
	cin >> stud_id;
	stud_id = stud_id - 1;
	if ((stud_id >= 0) && (stud_id < 35) && (stud_id < groups_count)) {
		cout << "\033[2J\033[1;1H";
		groups.erase(groups.begin() + stud_id);
		groups_count = groups_count - 1;
	}
	else {
		cout << "Такой группы не существует";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}


void App::PrintGroups() const {
	if (this->groups_count > 0) {
		cout << "------ Список групп ------" << endl << endl;
		for (int i = 0; i < this->groups_count; i++) {
			std::cout << i + 1 << " - ";
			cout << groups[i].GetNameGroup() << endl;
		}
	}
	else {
		cout << "------ Не создано ни одной группы ------" << endl << endl;
	}
	cout << endl;
}


void App::AppComander() {

	bool run = true;
	string precomand;
	while (run) {
		PrintGroups();

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			"Введите команду\n\n"
			" 1 - добавить группу\n"
			" 2 - перейти к группе\n"
			" 3 - удалить к группе\n"
			" 0 - Выход\n"
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
			GroupsWriter();
			run = false;
			break;
		default:
			cout << "Неправильная команда";
			Sleep(500);
			cout << "\033[2J\033[1;1H";
		}
	}
}


void App::GroupsWriter() {
	ofstream groups_out;
	groups_out.open("GROUPS.txt");
	if (!groups_out.is_open()) {
		cout << "Ошибка ";
	}
	else {
		groups_out << this->groups_count << endl;
		for (int i = 0; i < groups_count; i++) {
			gr buf_group;

			buf_group.name = groups[i].GetNameGroup();
			buf_group.st_cnt = groups[i].GetStudCount();

			groups_out << buf_group.name << " " << buf_group.st_cnt << endl;
		}
	}
	groups_out.close();
}


void App::GroupsReader() {
	ifstream groups_in;

	groups_in.open("GROUPS.txt");
	if (!groups_in.is_open()) {
		cout << "Ошибка\n";
	}
	else {
		vector<gr> buf_groups;
		string line;
		getline(groups_in, line, '\n');
		istringstream iss(line, istringstream::in);
		int gr_cnt = 0;
		iss >> gr_cnt;

		int i = 0;
		while (getline(groups_in, line, '\n')) {
			gr buf_gr;

			buf_gr.name = line;

			istringstream iss(line, istringstream::in);

			int val;
			iss >> val;
			buf_gr.st_cnt = val;

			buf_groups.push_back(buf_gr);
			i++;
		}

		this->groups_count = gr_cnt;
		
		for (int i = 0; i < groups_count; i++) {
			
			
			
		}
	}
	groups_in.close();


}