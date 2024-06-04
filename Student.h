#ifndef STUDENT_H
#define STUDENT_H

#include "Marks.h"


using namespace std; 

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

	bool ValidDate(unsigned int day, unsigned int  month, unsigned int year);

public:
	Date();

	bool SetDate();

	unsigned int GetDays() const;
	unsigned int GetMonths() const;
	unsigned int GetYears() const;
	
	void PrintDate() const;
};

class Name {
private:
	string name;
	string surname;
	string patronymic;

public:
	Name();

	void SetName();

	string GetName() const;
	
	string GetSurname() const;
	
	string GetPatronym() const;
	
	void PrintName() const;
};


class Student {
private:
	Name studentName;
	Date birthDate;
	unsigned int entryYear;
	string faculty;
	string cathedra;
	string group;
	string studentID;
	char sex;
	bool studInit;
	Sems sems;
	bool semInit;
	char comand;
	string s;

	bool ValidComand(string comnd);

public:
	Student();

	void SetStudent();

	void SetEntryYear();

	void SetFaculty();

	void SetCathedra();

	void SetGroup();

	void SetStudentID();

	void SetSex();

	void PrintName() const;

	void PrintStudent() const;

	void SetMarks();

	void PrintMarks();
	
	void SetStudentInfo();
	
	void StudentCommander();
};


#endif // !STUDENT_H
