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
			return false;
		}
	}
public:
	Mark() {
		subject = "";
		mark = 'c';
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


class TableMark {
private:
	map<string, char> table;
	short int tableSize;

public:
	TableMark() {
		tableSize = 10;
		table;
		for (int i = 0; i < tableSize; i++) {
			Mark mark;
			mark.SetMark();
			table[mark.GetSubject()] = mark.GetMark();
		}
	}

	void PrintTable() {
		for (const auto& element : table) {
			cout << element.first << "\t" << element.second << endl;
		}
	}
};


#endif MARKS_H