#include "pch.h"
#include "Group.h"
#include "Tree.cpp" 

Group::Group() : Tree<int, Student>()
{
	GroupName = NULL;
}

Group::Group(LPCTSTR gname) : Tree<int, Student>() 
{ 
	GroupName = gname; 
}

Group::Group(const Group& othgroup) : Tree<int, Student>(othgroup) 
{ 
	*this = othgroup; 
}

Group::~Group()
{ 
	GroupName = NULL;
};

int Group::compareGroups(const Group first, const Group second)
{
	#ifdef UNICODE
	if (wcscmp(first.GroupName, second.GroupName) > 0)
		return 1;
	else if (wcscmp(first.GroupName, second.GroupName) < 0)
		return -1;
	else
		return 0;
	#else
	if (cscmp(first.GroupName, second.GroupName) > 0)
		return 1;
	else if (cscmp(first.GroupName, second.GroupName) < 0)
		return -1;
	else
		return 0;
	#endif;
}

Group& Group::operator= (const Group& obj) {
	if (this == &obj)
		return *this;
	GroupName = obj.GroupName;
	Tree::operator=(obj);
	return *this;
}

bool Group::operator==(Group& obj)
{
	return compareGroups(*this, obj) == 0 ? true : false;
}

bool Group::operator!=(Group& obj)
{
	return compareGroups(*this, obj) == 0 ? false : true;
}

bool Group::operator>=(Group& obj)
{
	return compareGroups(*this, obj) == -1 ? false : true;
}

bool Group::operator<=(Group& obj)
{
	return compareGroups(*this, obj) == 1 ? false : true;
}

bool Group::operator<(Group& obj)
{
	return compareGroups(*this, obj) == -1 ? true : false;
}

bool Group::operator>(Group& obj)
{
	return compareGroups(*this, obj) == 1 ? true : false;
}

void Group::PrintAllInfo() {
	#ifdef UNICODE
		std::wcout << L"\nGroup Name: " << GroupName;
	#else
		std::cout << "\nGroup Name: " << GroupName;
	#endif // UNICODE
	for (int i = 0; i < LeftMosts.Count(); i++)
	{
		TreeNode<int, Student>* hcurrent = LeftMosts.GetValue(i);
		while (hcurrent != NULL)
		{
			hcurrent->Value.PrintAllInfo();
			hcurrent = hcurrent->Next;
		}
		std::cout << "\n\n";
	}
}