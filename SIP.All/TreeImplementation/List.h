#pragma once
#include "Tree.h"

template<class T, typename Tk>
class List
{
private:
	struct ListNode
	{
		Tree<T, Tk>::TreeNode* data;
		ListNode *next;
	};
	ListNode* head, *tail;

	void createNode(TreeNode* tnode)
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
	void replace(Tree<T, Tk>::TreeNode* oldnode, Tree<T, Tk>::TreeNode* newnode)
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
	bool getIndex(Tree<T, Tk>::TreeNode* value, int &index)
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
	bool getValue(int index, Tree<T, Tk>::TreeNode &node)
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
	void AddToEnd(Tree<T, Tk>::TreeNode* tnode)
	{
		createNode(tnode);
	}
	void Replace(Tree<T, Tk>::TreeNode* oldnode, Tree<T, Tk>::TreeNode* newnode)
	{
		replace(oldnode, newnode);
	}
	int GetIndex(Tree<T, Tk>::TreeNode* node)
	{
		int result;
		return (getIndex(node, result) ? result :  NULL);
	}
	bool IfNodeByIndexExists(int index)
	{
		Tree<T, Tk>::TreeNode* tmp;
		return getValue(index, tmp);
	}
	TreeNode* GetValue(int index)
	{
		Tree<T, Tk>::TreeNode* result;
		return (getValue(index, result) ? result : NULL);
	}
};