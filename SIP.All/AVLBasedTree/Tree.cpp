#include "pch.h"
#include "Tree.h"

template<class K, class V>
Tree<K, V>::Tree()
{
	Root = NULL;
}

template<class K, class V>
Tree<K, V>::~Tree() 
{
	Root = NULL;
}

template<class K, class V>
typename TreeNode<K, V>* Tree<K, V>::deleteTree(TreeNode<K, V>* node)
{
	if (node == NULL)
		return NULL;
	{
		deleteTree(node->Left);
		deleteTree(node->Right);
		delete node;
	}
	return NULL;
}

template<class K, class V>
typename TreeNode<K, V>* Tree<K, V>::newNode(V value, K key)
{
	TreeNode<K, V>* temp = new TreeNode<K, V>;
	temp->Key = key;
	temp->Value = value;
	temp->Left = temp->Right = temp->Prev = temp->Next = temp->Parent = NULL;
	return temp;
}

template<class K, class V>
typename TreeNode<K, V>* Tree<K, V>::recursiveInsert(TreeNode<K, V>* current, TreeNode<K, V>* node)
{

}

template<class K, class V>
void Tree<K, V>::iterativeInsert(TreeNode<K, V>* node)
{
	if (node->Key == NULL)
		node->Key = getMax(Root)->Key;
	if (Root == NULL)
	{
		Root = node;
		return;
	}
	TreeNode<K, V>* current = Root, *parent = NULL;
	while (current != NULL)
	{
		parent = current;
		if (node->Key < current->Key)
		{
			current = current->Left;
		}
		else if (node->Key > current->Key)
		{
			current = current->Right;
		}
	}
	current = node;
	if (current->Key < parent->Key)
		parent->Left = current;
	else
		parent->Right = current;
	current->Parent = parent;
	balanceTree(parent);
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::getMax(TreeNode<K, V>* current)
{
	TreeNode<K, V>* max = NULL;
	while (current != NULL)
	{
		max = current;
		current = current->Right;
	}
	return max;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::getMin(TreeNode<K, V>* current)
{
	TreeNode<K, V>* min = NULL;
	while (current != NULL)
	{
		min = current;
		current = current->Left;
	}
	return min;
}

template<class K, class V>
void Tree<K, V>::balanceTree(TreeNode<K, V>* parent)
{
	int bfactor = balanceFactor(parent);
	if (bfactor > 1)
	{
		parent = (balance_factor(parent->Left) > 0) ?
			RotateL(parent) : RotateLR(parent);
	}
	else if (b factor < -1)
	{
		parent = (balance_factor(parent->Left) > 0) ?
			RotateRL(parent) : RotateR(parent);
	}
}

template<class K, class V>
void Tree<K, V>::Add(V value, K key)
{
	TreeNode<K, V>* node = newNode(value, key);
	iterativeInsert(node);
}

