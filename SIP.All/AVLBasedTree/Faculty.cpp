#include "pch.h"
#include "Faculty.h"
#include "Tree.cpp"

Faculty::Faculty() : Tree<int, Group>() 
{ 
	FacultyName = ""; 
}

Faculty::Faculty(std::string fname) : Tree<int, Group>() 
{ 
	FacultyName = fname; 
}

Faculty::Faculty(const Faculty& othfac) : Tree<int, Group>(othfac) 
{ 
	*this = othfac; 
}

Faculty::~Faculty() 
{ 
	FacultyName.clear(); Tree::~Tree(); 
}

int Faculty::compareFaculty(const Faculty first, const Faculty second)
{
	return first.FacultyName.compare(second.FacultyName) > 0 ? 
		1 : 
		(second.FacultyName.compare(first.FacultyName) > 0 ? -1 : 0);
}

Faculty& Faculty::operator = (const Faculty& obj) {
	if (this == &obj)
		return *this;
	FacultyName = obj.FacultyName;
	Tree::operator = (obj);
	return *this;
}

bool Faculty::operator == (Faculty& obj)
{
	return compareFaculty(*this, obj) == 0 ? true : false;
}

bool Faculty::operator != (Faculty& obj)
{
	return compareFaculty(*this, obj) == 0 ? false : true;
}

bool Faculty::operator >= (Faculty& obj)
{
	return compareFaculty(*this, obj) == -1 ? false : true;
}

bool Faculty::operator <= (Faculty& obj)
{
	return compareFaculty(*this, obj) == 1 ? false : true;
}

bool Faculty::operator < (Faculty& obj)
{
	return compareFaculty(*this, obj) == -1 ? true : false;
}

bool Faculty::operator > (Faculty& obj)
{
	return compareFaculty(*this, obj) == 1 ? true : false;
}

void Faculty::PrintAllInfo() {
	std::cout << "FacultyName: " << FacultyName;
	for (int i = 0; i < LeftMosts.Count(); i++)
	{
		TreeNode<int, Group>* hcurrent = LeftMosts.GetValue(i);
		while (hcurrent != NULL)
		{
			hcurrent->Value.PrintAllInfo();
			hcurrent = hcurrent->Next;
		}
		std::cout << "\n";
	}
}