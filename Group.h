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
	string GetNameGroup() const;
	int GetStudCount() const;

	void AddStudent();
	void PrintGroup() const;
	void EditStudent();
	void DeleteStudent();
	void GroupComander();
	void GroupSetter(string gname);
	void GroupWriter(string name, int student_count);
	void GroupReader(string name, int student_count);
};

struct gr {
	string name;
	int st_cnt;
};

#endif // !GROUP_H