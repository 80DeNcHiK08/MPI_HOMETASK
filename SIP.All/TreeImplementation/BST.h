#pragma once
#include<iostream>

class BST
{
	struct Node {
		Node* Left;
		Node* Right;
		int key;
		int value;
	};
	Node* root;

	Node *newNode(int x, int v)
	{
		Node *temp = new Node;
		temp->key = x;
		temp->value = v;
		temp->Left = temp->Right = NULL;
		return temp;
	}
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
	Node* insert(int key, int value, Node* node)
	{
		if (node == NULL) return newNode(key, value);

		if (key < node->key)
			node->Left = insert(key, value, node->Left);
		else if (key > node->key)
			node->Right = insert(key, value, node->Right);
		return node;
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
		else if (x < t->key)
			t->Left = remove(x, t->Left);
		else if (x > t->key)
			t->Right = remove(x, t->Right);
		else if (t->Left && t->Right)
		{
			temp = findMin(t->Right);
			t->key = temp->key;
			t->Right = remove(t->key, t->Right);
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
		else if (x < t->key)
			return find(t->Left, x);
		else if (x > t->key)
			return find(t->Right, x);
		else
			return t;
	}
	void inorder(Node* t)
	{
		if (t == NULL)
			return;
		inorder(t->Left);
		std::cout << "Key: " << t->key << " " << "Val: " << t->value << " ";
		inorder(t->Right);
	}

	void iterate_in(Node *n);
	void iterate_pre(Node *n);
	void iterate_post(Node *n);
public:
	BST();
	~BST();

	void insert(int x, int v);
	void remove(int x);
	void search(int x);

	void display();
};

