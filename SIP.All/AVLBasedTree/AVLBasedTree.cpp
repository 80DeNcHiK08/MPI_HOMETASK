#include "pch.h"
#include "Tree.h"
#include "Tree.cpp"
#include "Student.h"
#include "Group.h"
#include "Faculty.h"

using namespace std;

int main()
{
	Tree<int, Faculty> tree;
	for (int i = 0; i < 15; i++)
	{
		Student st;
		Group g;
		Faculty f;
		tree.Add(f);
	}
}