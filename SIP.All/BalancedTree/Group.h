#pragma once

#include "Tree.h"
#include "Student.h"


using namespace std;

class Group : public Tree<int, Student>
{
protected:
	string* GroupName;
	int compareGroups(Group, Group);
public:
	Group() :Tree<int, Student>() { GroupName = new string("GroupName"); }
	Group(const Group& othMas) :Tree(othMas) { *this = othMas; }
	~Group() { delete GroupName; };
	void PrintAllInfo();
	Group& operator= (const Group&);
	bool operator==(Group&);
	bool operator!=(Group&);
	bool operator>=(Group&);
	bool operator<=(Group&);
	bool operator<(Group&);
	bool operator>(Group&);
};