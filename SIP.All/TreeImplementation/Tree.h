#pragma once
#include "Queue.h"

template<class T>
class Tree
{
private:
	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		int key;
		T value;
	};

	/*static class Count
	{
	protected:
		int value;
		void set(int val) { value = val; }
	public:
		int get() { return value; }
	};*/

	TreeNode* root;
	TreeNode* deleteTree(TreeNode* t);
	TreeNode* newNode(int key, T value);
	TreeNode* insert(int key, T value, TreeNode* node); //Insert by key
	TreeNode* remove(TreeNode* node); //Remove node, use methods below to get Node to delete

	TreeNode* searchByKey(TreeNode* t, int key); //Deep search by key
	TreeNode* searchDeep(TreeNode* t, T value); //Deep search by value
	TreeNode* searchWide(TreeNode* t, T value); //Wide search by value

	int height(TreeNode* node);
public:
	Tree();
	~Tree();

	void Add(int key, T value);
	void Add(T value);
	bool Remove(T value, bool searchtype);
	bool Remove(int key);

	TreeNode* Find(int key);
	bool Find(T value, bool searchtype);

	//int Count = Count.get();
};