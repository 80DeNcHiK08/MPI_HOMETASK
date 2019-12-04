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
	TreeNode* remove(int key, TreeNode* t);
	TreeNode* insert(int key, T value, TreeNode* node);

	TreeNode* searchByKey(TreeNode* t, int key); //Deep search by key
	TreeNode* searchDeep(TreeNode* t, T value); //Deep search by value
	TreeNode* searchWide(TreeNode* t, T value); //Wide search by value

	int height(TreeNode* node);
	TreeNode* findMax(TreeNode* t);
public:
	Tree();
	~Tree();

	void Add(int key, T value);
	void Add(T value);
	bool Remove(T value, bool searchtype);
	bool Remove(int key);

	bool Find(int key, T& value);
	bool Find(T value, bool searchtype);

	//int Count = Count.get();
};