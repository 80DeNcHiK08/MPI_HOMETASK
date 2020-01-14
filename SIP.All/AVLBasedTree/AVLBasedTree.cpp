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
	for (int i = 0; i < 33; i++)
	{
		clock_t start = clock();
		tree.Add(1);
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
	//tree.Remove(7);
	tree.PrintLevelOrder();
	Student stud1 = Student("Name1",
							"LastName1",
							"MidName1",
							9199,
							14.3);
	Student stud2 = Student("Name2",
							"LastName2",
							"MidName2",
							11368,
							11.2);
	Faculty ftree = Faculty("FFEKS");
	Group gtree = Group("KS-16-1");
	gtree.Add(stud1);
	gtree.Add(stud2);
	ftree.Add(gtree);
	if(stud1 != stud2)
		ftree.PrintAllInfo();
}