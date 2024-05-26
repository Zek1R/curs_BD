#ifndef MARKS_H
#define MARKS_H

#include <iostream>
#include <Windows.h>
#include <string>
#include <map>

using namespace std;

class Mark {
private:
	string subject;
	char mark;

	bool ValidMark(char m) {
		if ((m == '1') || (m == '2') || (m == '3') || (m == '4') || (m == '5')) {
			return true;
		}
		else {
			cout << "|Ошибка ввода оценки|";
			return false;
		}
	}
public:
	Mark() {
		string subject;
		mark = '-';
	}

	void SetMark() {
		char m;
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

	string GetSubject() const {
		return this->subject;
	}

	char GetMark() const {
		return this->mark;
	}

	void PrintMark() const {
		cout << this->subject << ": " << this->mark << endl;
	}
};


class SemMark {
private:
	map<string, char> sem;
	short int size;

public:
	SemMark() {
		size = 10;
		sem;
		
	}

	void SetSem() {
		for (int i = 0; i < size; i++) {
			Mark mark;
			mark.SetMark();
			sem[mark.GetSubject()] = mark.GetMark();
		}
	}

	void PrintSem() {
		for (const auto& element : sem) {
			cout << element.first << "\t" << element.second << endl;
		}
	}
};


#endif MARKS_H