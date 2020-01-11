#include "pch.h"
#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

using namespace std;

int main()
{
	Tree<int, int> tree;
	for (int i = 0; i < 15; i++)
	{
		tree.Add(rand());
	}
}