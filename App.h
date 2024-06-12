#ifndef APP_H
#define APP_H

#include "Group.h"

class App {
private:
	Group group;
	vector<Group> groups;
	int comand;
	int groups_count;
	int ValidComand();
public:
	App();
	void NewGroup();
	void DeleteGroup();
	void ChooseGroup();
	void PrintGroups() const;
	void AppComander();


};

#endif // !APP_H