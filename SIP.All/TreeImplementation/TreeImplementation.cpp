#include "pch.h"
#include <iostream>
#include "Tree.h"

int main()
{
	Tree tree;
	tree.Insert(15);
	tree.Insert(14);
	tree.Insert(12);
	tree.Insert(5);
	tree.Insert(17);
	tree.Insert(8);
	tree.print();
}