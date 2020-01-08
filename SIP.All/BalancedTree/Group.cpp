#include "pch.h"
#include "Group.h"
#include <string>

int Group::compareGroups(const Group first, const Group second)
{
	return first.GroupName->compare(*second.GroupName) > 0 ? 1 : (second.GroupName->compare(*first.GroupName) > 0 ? -1 : 0);
}

Group& Group::operator= (const Group& obj) {
	if (this == &obj)
		return *this;
	GroupName = new string(*obj.GroupName);
	Tree::operator=(obj);
	return *this;
}

void Group::PrintAllInfo() {
	cout << "\nGroup Name: " << *GroupName;
	Tree<int, Student>::PrintAllInfo();
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