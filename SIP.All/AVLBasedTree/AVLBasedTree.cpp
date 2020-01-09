#include "pch.h"
#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

using namespace std;

int main()
{
	Tree<int, int> tree;
	tree.Add(4, 1);
	tree.Add(4, 3);
	tree.Add(4, 2);
	tree.Add(4, 7);
	tree.Add(4, 6);
}