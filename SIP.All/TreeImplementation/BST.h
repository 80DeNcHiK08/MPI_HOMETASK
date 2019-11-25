#pragma once
#include<iostream>

class BST
{
	struct Node {
		Node* Left;
		Node* Right;
		int value;
	};
	Node* root;

	Node* freeSpace(Node* t)
	{
		if (t == NULL)
			return NULL;
		{
			freeSpace(t->Left);
			freeSpace(t->Right);
			delete t;
		}
		return NULL;
	}
	Node* insert(int x, Node* t)
	{
		if (t == NULL)
		{
			t = new Node;
			t->value = x;
			t->Left = t->Right = NULL;
		}
		else if (x < t->value)
			t->Left = insert(x, t->Left);
		else if (x > t->value)
			t->Right = insert(x, t->Right);
		return t;
	}
	Node* findMin(Node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->Left == NULL)
			return t;
		else
			return findMin(t->Left);
	}
	Node* findMax(Node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->Right == NULL)
			return t;
		else
			return findMax(t->Right);
	}
	Node* remove(int x, Node* t)
	{
		Node* temp;
		if (t == NULL)
			return NULL;
		else if (x < t->value)
			t->Left = remove(x, t->Left);
		else if (x > t->value)
			t->Right = remove(x, t->Right);
		else if (t->Left && t->Right)
		{
			temp = findMin(t->Right);
			t->value = temp->value;
			t->Right = remove(t->value, t->Right);
		}
		else
		{
			temp = t;
			if (t->Left == NULL)
				t = t->Right;
			else if (t->Right == NULL)
				t = t->Left;
			delete temp;
		}
		return t;
	}
	Node* find(Node* t, int x)
	{
		if (t == NULL)
			return NULL;
		else if (x < t->value)
			return find(t->Left, x);
		else if (x > t->value)
			return find(t->Right, x);
		else
			return t;
	}
	void inorder(Node* t)
	{
		if (t == NULL)
			return;
		inorder(t->Left);
		std::cout << t->value << " ";
		inorder(t->Right);
	}
public:
	BST();
	~BST();

	void insert(int x);
	void remove(int x);
	void search(int x);

	void display();
};

