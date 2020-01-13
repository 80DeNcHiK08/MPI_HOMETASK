#pragma once
#include "Tree.h"
#include "Student.h"
#include "Group.h"

class Faculty : public Tree<int, Group>
{
private:
	int compareFaculty(const Faculty first, const Faculty second);
protected:
	std::string FacultyName;
public:
	Faculty() : Tree<int, Group>() { FacultyName = ""; }
	Faculty(std::string fname) : Tree<int, Group>() { FacultyName = fname; }
	Faculty(const Faculty& othfac) : Tree<int, Group>(othfac) { *this = othfac; }
	~Faculty() { FacultyName.clear(); }

	Faculty& operator = (const Faculty&);
	bool operator == (Faculty&);
	bool operator != (Faculty&);
	bool operator >= (Faculty&);
	bool operator <= (Faculty&);
	bool operator < (Faculty&);
	bool operator > (Faculty&);

	void PrintAllInfo();
};

