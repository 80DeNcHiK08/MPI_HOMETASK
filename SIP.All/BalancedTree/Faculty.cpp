#include "Faculty.h"
#include <string>

int Faculty::compareFaculty(const Faculty first, const Faculty second)
{
	return first.FacultyName->compare(*second.FacultyName) > 0 ? 1 : (second.FacultyName->compare(*first.FacultyName) > 0 ? -1 : 0);
}

Faculty& Faculty::operator= (const Faculty& obj) {
	if (this == &obj)
		return *this;
	FacultyName = new string(*obj.FacultyName);
	Tree::operator=(obj);
	return *this;
}

bool Faculty::operator==(Faculty& obj)
{
	return compareFaculty(*this, obj) == 0 ? true : false;
}

bool Faculty::operator!=(Faculty& obj)
{
	return compareFaculty(*this, obj) == 0 ? false : true;
}

bool Faculty::operator>=(Faculty& obj)
{
	return compareFaculty(*this, obj) == -1 ? false : true;
}

bool Faculty::operator<=(Faculty& obj)
{
	return compareFaculty(*this, obj) == 1 ? false : true;
}

bool Faculty::operator<(Faculty& obj)
{
	return compareFaculty(*this, obj) == -1 ? true : false;
}

bool Faculty::operator>(Faculty& obj)
{
	return compareFaculty(*this, obj) == 1 ? true : false;
}

void Faculty::PrintAllInfo() {
	cout << "FacultyName: " << *FacultyName;
	Tree<int, Group>::PrintAllInfo();
}