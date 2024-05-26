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

	bool ValidMark(char m);
public:
	Mark();

	void SetMark();
	string GetSubject();
	char GetMark();
	void PrintMark();
};


class SemMark {
private:
	map<string, char> sem;
	short int size;

public:
	SemMark();

	void SetSem();
	void PrintSem();
};


#endif MARKS_H