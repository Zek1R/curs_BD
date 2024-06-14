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

	void SetDay(int d) { this->day = d; }
	void SetMonth(int m) { this->month = m; };
	void SetYear(int y) { this->year = y; };

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
	
	void FSetName(string n) { this->name = n; };
	void FSetSurname(string s) { this->surname = s; };
	void FSetPatronymic(string p) { this->patronymic = p; };
	
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

	void SetStudent(string g);
	void SetEntryYear();
	void SetFaculty();
	void SetCathedra();
	void SetGroup();
	void SetStudentID();
	void SetSex();

	unsigned int GetEntryYear() const { return this->entryYear; };
	string GetFaculty() const { return this->faculty; };
	string GetCathedra() const { return this->cathedra; };
	string GetGroup() const { return this->group; };
	string GetStudentID() const { return this->studentID; };
	char GetSex() const { return this->sex; };

	void PrintName() const;

	void PrintStudent() const;

	void SetMarks();

	void PrintMarks();
	
	void SetStudentInfo();
	
	void StudentCommander();

	
	void StudentWriter(string path);
	// void StudentReader(st buf_student);
};


struct st
{
	Name studentName;
	Date birthDate;
	unsigned int entryYear;
	string faculty;
	string cathedra;
	string group;
	string studentID;
	char sex;
};

#endif // !STUDENT_H
