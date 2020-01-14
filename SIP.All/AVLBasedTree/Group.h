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
	Group();
	Group(std::string gname);
	Group(const Group& othgroup);
	~Group();
	
	Group& operator = (const Group&);
	bool operator == (Group&);
	bool operator != (Group&);
	bool operator >= (Group&);
	bool operator <= (Group&);
	bool operator < (Group&);
	bool operator > (Group&);

	void PrintAllInfo();
};

