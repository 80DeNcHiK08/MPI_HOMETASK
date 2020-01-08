#pragma once
#include "Tree.h"

template<class K, class V>
class List
{
private:
	struct ListNode
	{
		TreeNode<K, V>* Data;
		ListNode* Next;
	};
	ListNode *head, *tail;

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
	void clearlist()
	{
		ListNode* pDel = NULL;
		ListNode* temp = this->head;
		while (temp != NULL)
		{
			pDel = temp;
			temp = temp->Next;
			delete pDel;
			Count--;
		}
		head = tail = NULL;
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
	~List() {}
	void AddToEnd(TreeNode<K, V>* node)
	{
		createNode(node);
	}
	int GetIndex(TreeNode<K, V>* node)
	{
		int result;
		return (getIndex(node, result) ? result : NULL);
	}
	TreeNode<K, V>* GetValue(int index)
	{
		TreeNode<K, V>* result;
		return (getValue(index, result) ? result : NULL);
	}
	void Clear()
	{
		clearlist();
	}
};