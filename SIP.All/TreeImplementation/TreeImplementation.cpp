#include "pch.h"
#include "Tree.h"
#include "Tree.cpp"

int main()
{
	Tree<int, int> t;
	t.Add(1, 4);
	t.Add(3, 7);
	t.Add(7, 3);
	t.Add(2, 7345);
	t.Add(8, 2344);
	t.Add(4, 3432);
	system("Pause");
	return 0;
}