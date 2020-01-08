#pragma once
#include "Tree.h"
#include "Student.h"
#include "Group.h"

class Faculty : public Tree<int, Group>
{
protected:
	string* FacultyName;
	int compareFaculty(Faculty, Faculty);
public:
	Faculty() :Tree<int, Group>() { FacultyName = new string("FacultyName"); }
	Faculty(const Faculty& othMas) :Tree<int, Group>(othMas) { *this = othMas; }
	~Faculty() { delete FacultyName; }
	void PrintAllInfo();
	Faculty& operator= (const Faculty&);
	bool operator==(Faculty&);
	bool operator!=(Faculty&);
	bool operator>=(Faculty&);
	bool operator<=(Faculty&);
	bool operator<(Faculty&);
	bool operator>(Faculty&);
};