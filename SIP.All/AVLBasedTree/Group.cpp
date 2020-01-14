#include "pch.h"
#include "Group.h"

int Group::compareGroups(const Group first, const Group second)
{
	return first.GroupName.compare(second.GroupName) > 0 ? 1 : (second.GroupName.compare(first.GroupName) > 0 ? -1 : 0);
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
	std::cout << "\nGroup Name: " << GroupName;
	Tree<int, Student>::PrintAllInfo();
}