#include "pch.h"
#include "BST.h"
#include "Tree.h"

int main()
{
	Tree<int> t;
	t.Add(1, 3);
	t.Add(3, 4);
	t.Add(5, 3);
	if (t.Find(4))
	{
		std::cout << "yes";
	}
	return 0;
}