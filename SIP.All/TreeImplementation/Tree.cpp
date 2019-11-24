#include "pch.h"
#include "Tree.h"

template <class T>
Tree<T>::Tree()
{
	root = NULL;
}

template <class T>
Tree<T>::~Tree()
{
	root = FreeMemory(root);
}

template <class T>
void Tree<T>::FreeMemory(Node *node)
{
	if (node != NULL)
	{
		FreeMemory(node->Left);
		FreeMemory(node->Right);
		delete node;
	}
}