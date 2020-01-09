#include "pch.h"
#include "List.h"

template<class K, class V>
List<K, V>::List()
{
	Head = NULL;
}

template<class K, class V>
List<K, V>::~List()
{
}

template<class K, class V>
void List<K, V>::createNode(TreeNode<K, V>* node)
{
	ListNode* temp = new ListNode;
	temp->Value = node;
	temp->Next = NULL;
	if (Head == NULL) { Head = Tail = temp; }
	else
	{
		Tail->Next = temp;
		Tail = temp;
	}
	Count++;
}

template<class K, class V>
void List<K, V>::clearList()
{
	ListNode *pdel = NULL, 
			 *temp = Head;
	while (temp != NULL)
	{
		pdel = temp;
		temp = temp->Next;
		delete pdel;
		Count--;
	}
	Head = Tail = NULL;
}

template<class K, class V>
bool List<K, V>::getIndex(TreeNode<K, V>* value, int& index)
{
	ListNode* current = Head;
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

template<class K, class V>
bool List<K, V>::getValue(int index, TreeNode<K, V>& node)
{
	ListNode* current = Head;
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

template<class K, class V>
void List<K, V>::AddToEnd(TreeNode<K, V>* node)
{
	createNode(node);
}

template<class K, class V>
bool List<K, V>::TryGetIndex(TreeNode<K, V>* node, int& outindex)
{
	int result;
	if (getIndex(node, result))
	{
		outindex = result;
		return true;
	}
	else
	{
		outindex = NULL;
		return false;
	}
}

template<class K, class V>
bool List<K, V>::TryGetValue(int index, TreeNode<K, V>& outnode)
{
	TreeNode<K, V>* result;
	if (getValue(index, result))
	{
		outnode = result;
		return true;
	}
	else
	{
		outnode = NULL;
		return false;
	}
}