#ifndef GROUP_H
#define GROUP_H

#include "Student.h"

class Group {
private:
	string group_name;
	Student student;
	vector<Student> students;
	string comand;
	int student_count;

	char Comand();

public:
	Group();
	void SetGroup();
	string GetName() const;
	void AddStudent();
	void PrintGroup() const;
	void EditStudent();
	void DeleteStudent();
	void GroupCommander();

};

#endif // !GROUP_H
