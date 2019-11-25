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

void BST::insert(int x, int v)
{
	root = insert(x, v, root);
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

void BST::iterate_in(Node *n)
{
	if (!n)
		return;

	iterate_in(n->Left);
	std::cout << n->value; // do something with the value
	iterate_in(n->Right);
}

void BST::iterate_pre(Node *n)
{
	if (!n)
		return;

	std::cout << n->value; // do something with the value
	iterate_pre(n->Left);
	iterate_pre(n->Right);
}

void BST::iterate_post(Node *n)
{
	if (!n)
		return;

	iterate_post(n->Left);
	iterate_post(n->Right);
	std::cout << n->value; // do something with the value
}