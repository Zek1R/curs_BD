#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include "Student.h"


class StudentWindow {
private:
	string precomand;
	char comand;
	Student student;
	string s;
	bool ValidComand(string comnd);

public:
	StudentWindow();
	bool StudentCommander();
};

#endif // !STUDENTWINDOW_H
