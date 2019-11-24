#pragma once
#include <iostream>
#include "Group.h"
#include "Student.h"

template <class T>
class Tree
{
private:
	struct Node
	{
		int Key;
		T Value;
		struct Node *Left, *Right;
		Node(int key)
		{
			this->Key = key;
			Left = Right = Value = NULL;
		}
	};

	Node *Root;
	void FreeMemory(Node*);
	int treeSize;
public:
	Tree();
	~Tree();

	Node* Insert(T, Node*);
	Node* Remove(bool, T, Node*);

	void Find(bool ,T, Node*, bool);

	void print();
	int size();
};

