#pragma once
#include "TreeNode.h"
#include "Tree.h"

template<typename K, class V>
class List
{
private:
	struct ListNode
	{
		TreeNode<K, V>* Data;
		ListNode* Next;
	};
	ListNode* head, * tail;

	void createNode(TreeNode<K, V>* tnode)
	{
		ListNode* temp = new ListNode;
		temp->Data = tnode;
		temp->Next = NULL;
		if (head == NULL)
		{
			head = tail = temp;
			temp = NULL;
		}
		else
		{
			tail->Next = temp;
			tail = temp;
		}
		Count++;
	}
	void replace(TreeNode<K, V>* oldnode, TreeNode<K, V>* newnode)
	{
		ListNode* current = head;
		while (current != NULL)
		{
			if (current->Data == oldnode)
			{
				current->Data = newnode;
			}
			current = current->Next;
		}
	}
	bool getIndex(TreeNode<K, V>* value, int& index)
	{
		ListNode* current = head;
		int result = 0;
		while (current != NULL)
		{
			if (current->Data == value)
			{
				index = result;
				return true;
			}
			current = current->Next;
			result++;
		}
		return false;
	}
	bool getValue(int index, TreeNode<K, V>*& node)
	{
		ListNode* current = head;
		int counter = 0;
		while (current != NULL)
		{
			if (counter == index)
			{
				node = current->Data;
				return true;
			}
			current = current->Next;
			counter++;
		}
		return false;
	}
public:
	int Count = 0;
	List()
	{
		head = NULL;
		tail = NULL;
	}
	~List()
	{

	}
	void AddToEnd(TreeNode<K, V>* tnode)
	{
		createNode(tnode);
	}
	void Replace(TreeNode<K, V>* oldnode, TreeNode<K, V>* newnode)
	{
		replace(oldnode, newnode);
	}
	int GetIndex(TreeNode<K, V>* node)
	{
		int result;
		return (getIndex(node, result) ? result : NULL);
	}
	bool IfNodeByIndexExists(int index)
	{
		TreeNode<K, V>* tmp;
		return getValue(index, tmp);
	}
	TreeNode<K, V>* GetValue(int index)
	{
		TreeNode<K, V>* result;
		return (getValue(index, result) ? result : NULL);
	}
};