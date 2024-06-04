#include "Marks.h"


//class Mark
bool Mark::ValidMark(int m) 
{
	if ((m == 1) || (m == 2) || (m == 3) || (m == 4) || (m == 5)) {
		return true;
	}
	else {
		cout << "|Ошибка ввода оценки|\n";
		return false;
	}
}

Mark::Mark() 
{
	subject;
	mark;
}

void Mark::SetMark() 
{
	int m;
	cout << "Введите название предмета\n>> ";
	cin >> this->subject;

	bool v = false;
	while (v != true) {
		cout << "Введите оценку (1-5)\n>> ";
		cin >> m;

		v = ValidMark(m);

		if (v == true) {
			mark = m;
		}
	}
}

string Mark::GetSubject() {
	return this->subject;
}

int Mark::GetMark() const {
	return this->mark;
}

void Mark::PrintMark()  {
	cout << this->subject << ": " << this->mark << endl;
}


//class SetSem
SemMark::SemMark() {
	size = 10;
	sem;

}

void SemMark::SetSem() {
	for (int i = 0; i < size; i++) {
		Mark mark;
		mark.SetMark();
		sem[mark.GetSubject()] = mark.GetMark();
	}
}

void SemMark::PrintSem() {
	for (const auto& element : sem) {
		cout << element.first << "\t" << element.second << endl;
	}
}


Sems::Sems() {
	all_sems;
	precomand = 0;
	comnd = 0;
}

void Sems::SetSems() {
	cout << "Введите номер семестра (1 - 11) >> ";
	cin >> precomand;
	if ((precomand == 0) || (precomand == 1) || (precomand == 2) || (precomand == 3) || (precomand == 4) || (precomand == 5) || (precomand == 6) || (precomand == 7) || (precomand == 8) || (precomand == 9) || (precomand == 10) || (precomand == 11)) {
		comnd = precomand;
	}
	else {
		cout << "Неверная команда\n";
		comnd = -1;
	}

	switch (comnd) {
	case 1:
		all_sems[comnd - 1].SetSem();
		break;
	case 2:
		all_sems[comnd - 1].SetSem();
		break;
	case 3:
		all_sems[comnd - 1].SetSem();
		break;
	case 4:
		all_sems[comnd - 1].SetSem();
		break;
	case 5:
		all_sems[comnd - 1].SetSem();
		break;
	case 6:
		all_sems[comnd - 1].SetSem();
		break;
	case 7:
		all_sems[comnd - 1].SetSem();
		break;
	case 8:
		all_sems[comnd - 1].SetSem();
		break;
	case 9:
		all_sems[comnd - 1].SetSem();
		break;
	case 10:
		all_sems[comnd - 1].SetSem();
		break;
	case 11:
		all_sems[comnd - 1].SetSem();
		break;
	default:
		cout << "Неверный номер семестра\n";
		break;
	}
}

void Sems::PrintSems() {
	cout << "Введите номер семестра который хотите вывести (1 - 11) >> ";
	cin >> comnd;
	if ((comnd == 0) || (comnd == 1) || (comnd == 2) || (comnd == 3) || (comnd == 4) || (comnd == 5) || (comnd == 6) || (comnd == 7) || (comnd == 8) || (comnd == 9) || (comnd == 10) || (comnd == 11)) {
		comnd = comnd;
	}
	else {
		cout << "Неверная команда\n";
		comnd = -1;
	}

	switch (comnd) {
	case 1:
		all_sems[comnd - 1].PrintSem();
		break;
	case 2:
		all_sems[comnd - 1].PrintSem();
		break;
	case 3:
		all_sems[comnd - 1].PrintSem();
		break;
	case 4:
		all_sems[comnd - 1].PrintSem();
		break;
	case 5:
		all_sems[comnd - 1].PrintSem();
		break;
	case 6:
		all_sems[comnd - 1].PrintSem();
		break;
	case 7:
		all_sems[comnd - 1].PrintSem();
		break;
	case 8:
		all_sems[comnd - 1].PrintSem();
		break;
	case 9:
		all_sems[comnd - 1].PrintSem();
		break;
	case 10:
		all_sems[comnd - 1].PrintSem();
		break;
	case 11:
		all_sems[comnd - 1].PrintSem();
		break;
	default:
		cout << "Неверный номер семестра\n";
		break;
	}
}





