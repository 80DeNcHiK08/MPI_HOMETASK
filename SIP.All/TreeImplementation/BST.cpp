#include "pch.h"
#include "BST.h"

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	root = freeSpace(root);
}

void BST::insert(int x)
{
	root = insert(x, root);
}

void BST::remove(int x)
{
	root = remove(x, root);
}

void BST::search(int x)
{
	if (find(root, x) == NULL)
		std::cout << "NO\n";
	else
		std::cout << "YES\n";
}
void BST::display()
{
	BST::inorder(root);
	std::cout << std::endl;
}