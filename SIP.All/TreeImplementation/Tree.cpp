#include "pch.h"
#include "Tree.h"

Tree::Tree()
{
	this->root = NULL;
	this->treeSize = 0;
}

Tree::~Tree()
{
	freeMemory(this->root);
}

int Tree::size()
{
	return this->treeSize;
}

void Tree::freeMemory(Node *node)
{
	if (node == NULL)
		return;
	freeMemory(node->Left);
	freeMemory(node->Right);
	delete node;
}

void Tree::Insert(int value)
{
	Node *node = new Node(value);
	Node *temp = NULL;
	Node *prev = NULL;

	temp = root;
	while (temp)
	{
		prev = temp;
		if (temp->Value < node->Value)
			temp = temp->Right;
		else
			temp = temp->Left;
	}
	if (prev = NULL)
	{
		root = node;
	}
	else
	{
		if (prev->Value < node->Value)
			prev->Right = node;
		else
			prev->Left = node;
	}
}

void Tree::print(Node *root)
{
	if (root = NULL)
		return;
	print(root->Left);
	std::cout << root->Key << ": " << root->Value << std::endl;
	print(root->Right);
}

void Tree::print()
{
	print(root);
}

