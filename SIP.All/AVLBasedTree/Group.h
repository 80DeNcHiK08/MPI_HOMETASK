#pragma once
#include "Tree.h"
#include "Student.h"

class Group : public Tree<int, Student>
{
private:
	int compareGroups(const Group first, const Group second);
protected:
	std::string GroupName;
public:
	Group() : Tree<int, Student>() { GroupName = ""; }
	Group(std::string gname) : Tree<int, Student>() { GroupName = gname; }
	Group(const Group& othgroup) : Tree<int, Student>(othgroup) { *this = othgroup; }
	~Group() { GroupName.clear(); };
	
	Group& operator = (const Group&);
	bool operator == (Group&);
	bool operator != (Group&);
	bool operator >= (Group&);
	bool operator <= (Group&);
	bool operator < (Group&);
	bool operator > (Group&);

	void PrintAllInfo();
};

