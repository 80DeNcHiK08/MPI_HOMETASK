#include "pch.h"
#include "Tree.h"
#include "List.h"

template<typename K, class V>
Tree<K, V>::Tree()
{
	Root = NULL;
}

template<typename K, class V>
Tree<K, V>::~Tree()
{
	Root = deleteTree(Root);
}

template<typename K, class V>
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

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::newNode(K key, V value)
{
	TreeNode<K, V>* temp = new TreeNode<K, V>;
	temp->Key = key;
	temp->Value = value;
	temp->Left = temp->Right = temp->Prev = temp->Next = temp->Parent = NULL;
	return temp;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::newNode(V value)
{
	TreeNode<K, V>* temp = new TreeNode<K, V>;
	temp->Value = value;
	temp->Left = temp->Right = temp->Prev = temp->Next = temp->Parent = NULL;
	return temp;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::recursiveInsert(TreeNode<K, V>* current, TreeNode<K, V>* node)
{
	if (current == NULL)
	{
		current = node;
		return current;
	}
	else if (node->Key < current->Key)
	{
		current->Left = recursiveInsert(current->Left, node);
		current->Left->Parent = current;
		current = balance_tree(current);
	}
	else if (node->Key > current->Key)
	{
		current->Right = recursiveInsert(current->Right, node);
		current->Right->Parent = current;
		current = balance_tree(current);
	}
	fillLeftMosts();
	connect2Nodes(current);
	Root->Next = Root->Prev = NULL;
	return current;
}

template<typename K, class V>
void Tree<K, V>::connect2Nodes(TreeNode<K, V>* parent)
{
	if (parent != NULL)
	{
		if (parent->Left != NULL && parent->Right != NULL)
		{
			parent->Left->Next = parent->Right;
			parent->Right->Prev = parent->Left;
			if (parent->Right->Next == NULL && parent->Parent != NULL ||
				parent->Right->Prev == NULL && parent->Parent != NULL)
			{
				connect2Nodes(parent->Parent);
			}

		}
	}
}

template<class K, class V>
void Tree<K, V>::fillLeftMosts()
{
	LeftMosts.Clear();
	TreeNode<K, V>* current = Root;
	while (current != NULL)
	{
		/*(current->Left == NULL && current->Right != NULL) ?
			LeftMosts.AddToEnd(current->Right) :
			LeftMosts.AddToEnd(current);*/
		current = current->Left;
	}
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::iterativeInsert(TreeNode<K, V>* node)
{
	TreeNode<K, V>* current = Root;
	int counter = 1;
	while (current != NULL)
	{
		if (node->Key < current->Key)
		{
			if (current->Left == NULL)
			{
				current->Left = node;
				current = balance_tree(current);
				return current;
			}
			else { current = current->Left; }
		}
		else if (node->Key > current->Key)
		{
			if (current->Right == NULL)
			{
				current->Right = node;
				current = balance_tree(current);
				return current;
			}
			else { current = current->Right; }
		}
	}
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::removeDeep(K key, TreeNode<K, V>* node)
{
	if (node == NULL) { return NULL; }
	else if (key < node->Key)
		node->Left = removeDeep(key, node->Left);
	else if(key > node->Key)
		node->Right = removeDeep(key, node->Right);
	else
	{
		TreeNode<K, V>* left = node->Left;
		TreeNode<K, V>* right = node->Right;
		node->Next->Prev = node->Prev->Next = NULL;
		delete node;
		if (right == NULL)
			return left;
		TreeNode<K, V>* min = getMin(right);
		min->Right = removeMin(right);
		min->Left = left;
		return balance_tree(min);
	}
	return balance_tree(node);
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::removeMin(TreeNode<K, V>* current)
{
	if (current->Left == NULL)
		return current->Right;
	current->Left = removeMin(current->Left);
	return balance_tree(current);
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::removeWide(V value)
{
	for (int i = 0; i < LeftMosts.Count; i++)
	{
		TreeNode<K, V>* current = LeftMosts.GetValue(i);
		while (current != NULL)
		{
			if (current->Value == value)
			{

			}
			current = current->Next;
		}
	}
	return NULL;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::searchDeep(TreeNode<K, V>* current, K key)
{
	if (current == NULL)
	{
		return NULL;
	}
	else if (key < current->Key)
	{
		return (key == current->Key) ?
			current :
			searchDeep(current->Left, key);
	}
	else
	{
		return (key == current->Key) ?
			current :
			searchDeep(current->Right, key);
	}
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::searchWide(K key)
{
	for (int i = 0; i < LeftMosts.Count; i++)
	{
		TreeNode<K, V>* current = LeftMosts.GetValue(i);
		while (current != NULL)
		{
			if (current->Key == key)
				return current;
			current = current->Next;
		}
	}
	return NULL;
}

template<typename K, class V>
bool Tree<K, V>::searchDeepValue(TreeNode<K, V>* current, V value)
{
	if (current == NULL) 
		return false;
	if (value == current->Value)
		return true;

	searchDeep(current->Left, value);
	searchDeep(current->Right, value);
}

template<typename K, class V>
bool Tree<K, V>::searchWideValue(V value)
{
	for (int i = 0; i < LeftMosts.Count; i++)
	{
		TreeNode<K, V>* current = LeftMosts.GetValue(i);
		while (current != NULL)
		{
			if (current->Value == value)
				return true;
			current = current->Next;
		}
	}
	return false;
}

template<typename K, class V>
int Tree<K, V>::balance_factor(TreeNode<K, V>* current)
{
	int l = getHeight(current->Left);
	int r = getHeight(current->Right);
	int b_factor = l - r;
	return b_factor;
}

template<typename K, class V>
int Tree<K, V>::getHeight(TreeNode<K, V>* current)
{
	int height = 0;
	if (current != NULL)
	{
		int l = getHeight(current->Left);
		int r = getHeight(current->Right);
		int m = (l > r) ? l : r;
		height = m + 1;
	}
	return height;
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

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::balance_tree(TreeNode<K, V>* current)
{
	int b_factor = Tree<K, V>::balance_factor(current);
	if (b_factor > 1)
	{
		current = (Tree<K, V>::balance_factor(current->Left) > 0) ?
			RotateLL(current) : RotateLR(current);
	}
	else if (b_factor < -1)
	{
		current = (Tree<K, V>::balance_factor(current->Right) > 0) ?
			RotateRL(current) : RotateRR(current);
	}
	connect2Nodes(current);
	current->Parent = NULL;
	return current;
}

//tree rotation methods

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateRR(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Right;
	parent->Right = pivot->Left;
	pivot->Left = parent;
	pivot->Left->Parent = pivot;
	return pivot;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateLL(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Left;
	parent->Left = pivot->Right;
	pivot->Right = parent;
	pivot->Right->Parent = pivot;
	return pivot;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateLR(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Left;
	parent->Left = RotateRR(pivot);
	auto result = RotateLL(parent);
	result->Left->Parent = result;
	return result;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateRL(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Right;
	parent->Right = RotateLL(pivot);
	auto result = RotateRR(parent);
	result->Right->Parent = result;
	return result;
}

//Public Methods

template<typename K, class V>
void Tree<K, V>::Add(K key, V value)
{
	TreeNode<K, V>* newnode = newNode(key, value);
	this->Root = (this->Root == NULL) ?
		this->Root = newnode : recursiveInsert(this->Root, newnode);
	Count++;
}

template<typename K, class V>
void Tree<K, V>::Add(V value)
{
	TreeNode<K, V>* newnode = newNode(value);
	if (this->Root == NULL)
	{
		newnode->Key = 0;
		this->Root = newnode;
	}
	else
	{
		newnode->Key = getMax(this->Root)->Key + 1;
		this->Root = recursiveInsert(this->Root, newnode);
		//this->Root = iterativeInsert(newnode);
	}
	Count++;
}

template<typename K, class V>
bool Tree<K, V>::Remove(K key)
{
	TreeNode<K, V>* result = Tree<K, V>::removeDeep(key, Root);
	if (result != NULL)
	{
		Root = result;
		return true;
	}
	else
	{
		return false;
	}
	Count--;
}

template<typename K, class V>
bool Tree<K, V>::RemoveWide(V value)
{
	TreeNode<K, V>* result = removeWide(value);
	if (result != NULL)
	{
		this->Root = result;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename K, class V>
bool Tree<K, V>::Find(K key, V& value, bool searchType)
{
	TreeNode<K, V>* result = (searchType) ?
		searchDeep(this->Root, key) :
		searchWide(key);
	value = (result != NULL) ? result->Value : NULL;
	return (value == NULL) ? false : true;
}

template<typename K, class V>
bool Tree<K, V>::Find(V value, bool searchType)
{
	TreeNode<K, V>* result = (searchType) ?
		searchDeep(this->Root, value) :
		searchWide(value);
	return result;
}

template<typename K, class V>
void Tree<K, V>::LevelOrderPrint()
{
	int tabcount = LeftMosts.Count;
	TreeNode<K, V>* currentv = Root;
	while (currentv != NULL)
	{
		for (int i = tabcount; i >= 0; i--)
		{
			std::cout << "\t";
		}
		TreeNode<K, V>* currenth = currentv;
		while (currenth != NULL)
		{
			std::cout << currenth->Key << "\t";
			currenth = currenth->Next;
		}
		tabcount--;
		std::cout << std::endl << std::endl;
		currentv = currentv->Left;
	}
}

template<typename K, class V>
void Tree<K, V>::PrintAllInfo() {
	int tabcount = LeftMosts.Count;
	TreeNode<K, V>* currentv = Root;
	while (currentv != NULL)
	{
		for (int i = tabcount; i >= 0; i--)
		{
			std::cout << "\t";
		}
		TreeNode<K, V>* currenth = currentv;
		while (currenth != NULL)
		{
			std::cout << currenth->Value << "\t";
			currenth = currenth->Next;
		}
		tabcount--;
		std::cout << std::endl << std::endl;
		currentv = currentv->Left;
	}
}