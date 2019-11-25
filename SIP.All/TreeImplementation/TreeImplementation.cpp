#include "pch.h"
#include "BST.h"

int main()
{
	BST tree;
	tree.insert(20, 234);
	tree.insert(25, 12);
	tree.insert(15, 123);
	tree.insert(10, 353);
	tree.insert(30, 234);
	tree.display();
	tree.remove(20);
	tree.display();
	tree.remove(25);
	tree.search(30);
	tree.display();
	tree.remove(30);
	tree.search(30);
	tree.display();
	return 0;
}