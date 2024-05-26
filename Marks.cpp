#include "Marks.h"


//class Mark
bool Mark::ValidMark(char m) 
{
	if ((m == '1') || (m == '2') || (m == '3') || (m == '4') || (m == '5')) {
		return true;
	}
	else {
		cout << "|������ ����� ������|";
		return false;
	}
}

Mark::Mark() 
{
	string subject;
	mark = '-';
}

void Mark::SetMark() 
{
	char m;
	cout << "������� �������� ��������\n>> ";
	cin >> this->subject;

	bool v = false;
	while (v != true) {
		cout << "������� ������ (1-5)\n>> ";
		cin >> m;

		v = ValidMark(m);

		if (v == true) {
			mark = m;
		}
	}
}

string Mark::GetSubject() 
{
	return this->subject;
}

char Mark::GetMark()  {
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




