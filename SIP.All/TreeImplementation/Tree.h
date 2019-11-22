#pragma once
#include <iostream>

class Tree
{
private:
	struct Node
	{
		int Key;
		int Value; //temporary
		Node *Left, *Right;

		Node(int val) :Value(val), Left(NULL), Right(NULL)
		{

		}
	};
	Node *root;
	void print(Node*);
	void freeMemory(Node*);
	int treeSize;
public:
	Tree();
	~Tree();
	void Insert(int);
	void print();
	int size();
};

