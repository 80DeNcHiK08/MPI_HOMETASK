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
	if (key == NULL)
		temp->Key = 0;
	else
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
	//1st element
	if (Root == NULL)
	{
		Root = node;
		return;
	} 
	//increasing key
	if (node->Key == 0)
		node->Key = getMax(Root)->Key + 1;
	TreeNode<K, V>* current = Root;
	TreeNode<K, V>* parent = Root;
	//search for correct place
	while (current != NULL)
	{
		parent = current;
		current = (node->Key < current->Key) ?
			current->Left :
			current->Right;
	}
	//inserting node
	current = node;
	current->Parent = parent;
	if (current->Key < parent->Key)
		parent->Left = current;
	else if (current->Key > parent->Key)
		parent->Right = current;
	//balancing and rebuilding tree
	/*while (parent->Parent != NULL)
	{
		parent = balanceTree(parent);
		if(parent->Parent != NULL)
			parent = parent->Parent;
	}
	Root = parent;*/
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
typename TreeNode<K, V>* Tree<K, V>::searchDeep(TreeNode<K, V>* current, TreeNode<K, V>* node)
{
	while (current != NULL)
	{
		if (current->Key == node->Key)
			return current;
		current = (node->Key < current->Key) ?
			current = current->Left :
			current = current->Right;
	}
	return current;
}

template<class K, class V>
typename TreeNode<K, V>* Tree<K, V>::balanceTree(TreeNode<K, V>* parent)
{
	int bfactor = balanceFactor(parent);
	if (bfactor > 1)
	{
		parent = (balanceFactor(parent->Left) > 0) ?
			RotateL(parent) : RotateLR(parent);
	}
	else if (bfactor < -1)
	{
		parent = (balanceFactor(parent->Right) > 0) ?
			RotateRL(parent) : RotateR(parent);
	}
	return parent;
}

template<class K, class V>
int Tree<K, V>::balanceFactor(TreeNode<K, V>* parent)
{
	int l = getHeight(parent->Left);
	int r = getHeight(parent->Right);
	int b_factor = l - r;
	return b_factor;
}

template<class K, class V>
int Tree<K, V>::getHeight(TreeNode<K, V>* parent)
{
	int height = 0;
	if (parent != NULL)
	{
		int l = getHeight(parent->Left);
		int r = getHeight(parent->Right);
		int m = (l > r) ? l : r;
		height = m + 1;
	}
	return height;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateR(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Right;
	parent->Right = pivot->Left;
	pivot->Parent = parent->Parent;
	pivot->Left = parent;
	pivot->Left->Parent = pivot;
	return pivot;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateL(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Left;
	parent->Left = pivot->Right;
	pivot->Parent = parent->Parent;
	pivot->Right = parent;
	pivot->Right->Parent = pivot;
	return pivot;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateLR(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Left;
	parent->Left = RotateR(pivot);
	auto result = RotateL(parent);
	result->Left->Parent = result;
	return result;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateRL(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Right;
	parent->Right = RotateL(pivot);
	auto result = RotateR(parent);
	result->Right->Parent = result;
	return result;
}

template<class K, class V>
void Tree<K, V>::Add(V value, K key)
{
	TreeNode<K, V>* node = newNode(value, key);
	iterativeInsert(node);
}

template<class K, class V>
void Tree<K, V>::PrintAllInfo()
{

}