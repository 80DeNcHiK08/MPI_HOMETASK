#include "pch.h"
#include "Tree.h"
#include "Tree.cpp"
#include <ctime>

using namespace std;

int main()
{
	Tree<int, int> tree;
	int counter = 1;
	for (int i = 1; i <= 31; i++)
	{
		clock_t start = clock();
		double duration;
		tree.Add(rand());
		duration = ((double)clock() - start) / (double)CLOCKS_PER_SEC;
		counter++;
		cout << "Adding " << counter << " element; Time: " << duration << endl;
	}

	int returned;
	if (tree.Find(456, returned))
	{
		cout << "returned: " << returned << endl;
	}
	else
	{
		cout << "There is no element with such key!" << endl;
	}
 }