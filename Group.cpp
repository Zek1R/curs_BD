#include "Group.h"

char Group::Comand() {

	string c;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"Введите команду\n\n"
		" 1 - Добавить студента\n"
		" 2 - Изменить студента\n"
		" 3 - Удалить студента\n"
		" 0 - Вернуться к списку групп\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		">> ";
	cin >> c;

	if ((c == "0") || (c == "1") || (c == "2") || (c == "3")) {
		return c[0];
	}
	else {
		cout << "Неправильная команда." << endl;
		Sleep(300);
		cout << "\033[2J\033[1;1H";
	}
}


Group::Group() {
	group_name;
	student;
	students;
	comand;
	student_count = 0;
}


void Group::SetGroup() {	
	cout << "Введите название группы\n\n>> ";
	cin >> this->group_name;
}


string Group::GetNameGroup() const{
	return this->group_name;
}

int Group::GetStudCount() const{
	return this->student_count;
}


void Group::AddStudent() {
	if (student_count <= 35) {
		student.SetStudent(group_name);
		students.push_back(this->student);
		student_count += 1;
		cout << "\033[2J\033[1;1H";
	}
	else {
		cout << "Больше студентов не добавить" << endl;
	}
}


void Group::PrintGroup() const {
	if (this->student_count > 0) {
		cout << "------ Список студентов ------" << endl << endl;
		for (int i = 0; i < this->student_count; i++) {
			std::cout << i+1 << " - ";
			students[i].PrintName();
		}
	}
	else {
		cout << "------ В группе нет ни одного студента ------" << endl << endl;
	}
}


void Group::EditStudent() {
	short int stud_id;
	cout << endl;
	cout << "Введите номер студента\n\n>> ";
	cin >> stud_id;
	stud_id = stud_id - 1;
	if ((stud_id >= 0) && (stud_id < 35) && (stud_id < student_count)) {
		cout << "\033[2J\033[1;1H";
		students[stud_id].StudentCommander();
	}
	else {
		cout << "\nТакого студента не существует";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}


void Group::DeleteStudent() {
	short int stud_id;
	cout << endl;
	cout << "Введите номер студента\n\n>> ";
	cin >> stud_id;
	stud_id = stud_id - 1;
	if ((stud_id >= 0) && (stud_id < 35) && (stud_id < student_count)) {
		students.erase(students.begin() + stud_id);
		student_count = student_count - 1;
		cout << "\033[2J\033[1;1H";
	}
	else {
		cout << "\nТакого студента не существует";
		Sleep(500);
		cout << "\033[2J\033[1;1H";
	}
}

void Group::GroupSetter(string gname) {
	this->group_name = gname;
}

void Group::GroupComander() {
	
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
			GroupWriter(GetNameGroup(), student_count);
			isRun = false;
			break;
		default:
			break;
		}
	}
}


void Group::GroupWriter(string name, int student_count){
	string path = name + ".txt";

	for (int i = 0; i < student_count; i++) {
		students[i].StudentWriter(path);
	}
}

void Group::GroupReader(string name, int student_count) {
	string path = name + ".txt";
	ifstream fin;

	fin.open(path);
	vector<string> buf;
	if (!fin.is_open()) {
		cout << "Ошибка" << endl;
	}
	else {
		string line;
		while (getline(fin, line)) {
			buf.push_back(line);
			line = "";
		}
	}
	fin.close();

	

	if (!sizeof(buf) == 0) {
		for (int i = 0; i < student_count; i++) {
			cout << buf[i] << endl;
		}
	}
}

