#ifndef MARKS_H
#define MARKS_H

#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Mark {
private:
	string subject;
	int mark;

	bool ValidMark(int m);

public:
	Mark();

	void SetMark();
	string GetSubject();
	int GetMark() const ;
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


class Sems {
private:
	SemMark all_sems[11];
	int precomand;
	int comnd;
public:
	Sems();

	void SetSems();

	//void GetSems();

	//void Print_sem();
	
	void PrintSems();

};

#endif MARKS_H