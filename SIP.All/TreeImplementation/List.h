#pragma once
#include "TreeNode.h"
#include "Tree.h"

template<typename Tk, class T>
class List
{
private:
	struct ListNode
	{
		TreeNode<Tk, T>* data;
		ListNode *next;
	};
	ListNode* head, *tail;

	void createNode(TreeNode<Tk, T>* tnode)
	{
		ListNode* temp = new ListNode;
		temp->data = tnode;
		temp->next = NULL;
		if (head == NULL)
		{
			head = tail = temp;
			temp = NULL;
		}
		else 
		{
			tail->next = temp;
			tail = temp;
		}
		Count++;
	}
	void replace(TreeNode<Tk, T>* oldnode, TreeNode<Tk, T>* newnode)
	{
		ListNode *current = head;
		while(current != NULL)
		{
			if (current->data == oldnode)
			{
				current->data = newnode;
			}
			current = current->next;
		}
	}
	bool getIndex(TreeNode<Tk, T>* value, int &index)
	{
		ListNode *current = head;
		int result = 0;
		while (current != NULL)
		{
			if (current->data == value)
			{
				index = result;
				return true;
			}
			current = current->next;
			result++;
		}
		return false;
	}
	bool getValue(int index, TreeNode<Tk, T>*&node)
	{
		ListNode *current = head;
		int counter = 0;
		while (current != NULL)
		{
			if (counter == index)
			{
				node = current->data;
				return true;
			}
			current = current->next;
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
	void AddToEnd(TreeNode<Tk, T>* tnode)
	{
		createNode(tnode);
	}
	void Replace(TreeNode<Tk, T>* oldnode, TreeNode<Tk, T>* newnode)
	{
		replace(oldnode, newnode);
	}
	int GetIndex(TreeNode<Tk, T>* node)
	{
		int result;
		return (getIndex(node, result) ? result :  NULL);
	}
	bool IfNodeByIndexExists(int index)
	{
		TreeNode<Tk, T>* tmp;
		return getValue(index, tmp);
	}
	TreeNode<Tk, T>* GetValue(int index)
	{
		TreeNode<Tk, T>* result;
		return (getValue(index, result) ? result : NULL);
	}
};