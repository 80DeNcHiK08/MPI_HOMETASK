#include "pch.h"
#include "Tree.h"
#include "Tree.cpp"
#include "Student.h"
#include "Group.h"
#include "Faculty.h"
#include <ctime>

using namespace std;

int main()
{
	Tree<int, Faculty> tree1;
	/*for (int i = 0; i < 15; i++)
	{
		Student st;
		Group g;
		Faculty f;
		tree.Add(f);
	}*/
	Tree<int, int> tree;
	
	double duration;
	int counter = 1;
	for (int i = 0; i < 16; i++)
	{
		clock_t start = clock();
		tree.Add(1, rand());
		duration = ((double)clock() - start) / (double)CLOCKS_PER_SEC;
		string s;
		int scase = counter % 10;
		switch (scase)
		{
		case 1: s = "st"; break;
		case 2: s = "nd"; break;
		case 3: s = "rd"; break;
		default: s = "th"; break;
		}
		cout << "Adding " << counter << "'" << s << " element; Time: " << duration << endl;
		counter++;
	}
	tree.PrintAllInfo();
}