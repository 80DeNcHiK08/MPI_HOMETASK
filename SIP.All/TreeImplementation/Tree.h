#pragma once
#include <iostream>
#include "List.h"

template<class T, typename Tk>
class Tree
{
private:
	struct TreeNode {
		TreeNode *left, *right, *l_next, *l_prev;
		int level;
		Tk key;
		T value;
	};

	List<T, Tk> leftmosts;
	TreeNode* root;

	TreeNode* deleteTree(TreeNode* t);
	TreeNode* newNode(Tk key, T value, int level);
	TreeNode* remove(Tk key, TreeNode* t);
	TreeNode* insert(Tk key, T value);

	TreeNode* searchByKey(TreeNode* t, int key); //Deep search by key
	TreeNode* searchDeep(TreeNode* t, T value); //Deep search by value
	TreeNode* searchWide(TreeNode* t, T value); //Wide search by value

	//int height(TreeNode* node);
public:
	Tree();
	~Tree();

	void Add(Tk key, T value);
	void Add(T value);
	bool Remove(T value, bool searchtype);
	bool Remove(Tk key);

	bool Find(Tk key, T& value);
	bool Find(T value, bool searchtype);

	//int Count = Count.get();
};