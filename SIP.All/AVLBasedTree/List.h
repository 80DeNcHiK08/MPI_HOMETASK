#pragma once
#include "TreeNode.h"

template<class K, class V>
class List
{
private:
	struct ListNode
	{
		TreeNode<K, V>* Value;
		ListNode* Next;
	};
	ListNode* Head, *Tail;
	void createNode(TreeNode<K, V>* node);
	void clearList();
	bool getValue(int index, TreeNode<K, V>*& outnode);
	bool getIndex(TreeNode<K, V>* node, int& outindex);
	int count = 0;
public:
	List();
	~List();
	void AddToEnd(TreeNode<K, V>* node);
	void Clear();
	TreeNode<K, V>* GetValue(int index);
	int GetIndex(TreeNode<K, V>* node);
	int Count() { return count; }
};

