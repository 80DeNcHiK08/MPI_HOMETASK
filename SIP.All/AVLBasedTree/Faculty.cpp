#include "pch.h"
#include "Faculty.h"
#include "Tree.cpp"

Faculty::Faculty() : Tree<int, Group>() 
{ 
	FacultyName = NULL; 
}

Faculty::Faculty(LPCTSTR fname) : Tree<int, Group>()
{ 
	FacultyName = fname; 
}

Faculty::Faculty(const Faculty& othfac) : Tree<int, Group>(othfac) 
{ 
	*this = othfac; 
}

Faculty::~Faculty() 
{ 
	FacultyName = NULL;
}

int Faculty::compareFaculty(const Faculty first, const Faculty second)
{
	if (tscmp(first.FacultyName, second.FacultyName) > 0)
		return 1;
	else if (tscmp(first.FacultyName, second.FacultyName) < 0)
		return -1;
	else
		return 0;
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
	#ifdef UNICODE
		std::wcout << L"FacultyName: " << FacultyName;
	#else
		std::cout << "FacultyName: " << FacultyName;
	#endif // UNICODE
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