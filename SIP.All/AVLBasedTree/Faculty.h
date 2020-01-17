#pragma once
#include "Tree.h"
//#include "Student.h"
#include "Group.h"

class Faculty : public Tree<int, Group>
{
private:
	int compareFaculty(const Faculty first, const Faculty second);
protected:
	LPCTSTR FacultyName;
public:
	Faculty();
	Faculty(LPCTSTR fname);
	Faculty(const Faculty& othfac);
	~Faculty();

	Faculty& operator = (const Faculty&);
	bool operator == (Faculty&);
	bool operator != (Faculty&);
	bool operator >= (Faculty&);
	bool operator <= (Faculty&);
	bool operator < (Faculty&);
	bool operator > (Faculty&);

	void PrintAllInfo();
};

