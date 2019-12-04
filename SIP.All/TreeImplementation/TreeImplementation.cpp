#include "pch.h"
#include "BST.h"
#include "Tree.h"
#include "Tree.cpp"

int main()
{
	Tree<int> t;
	t.Add(1, 3);
	t.Add(3, 214);
	t.Add(4, 54234);
	t.Add(5, 123);
	t.Add(6, 567);
	t.Add(7, 87);
	t.Add(8, 543);
	t.Add(2, 2);
	if (t.Find(54234, true))
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}

	int res;
	if (t.Find(1, res))
	{
		std::cout << res << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}
	std::system("Pause");
	return 0;
}