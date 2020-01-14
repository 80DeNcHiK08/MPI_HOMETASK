#include "pch.h"
#include "Tree.h"
#include "Student.h"

template<class K, class V>
Tree<K, V>::Tree()
{
	Root = NULL;
}

template<class K, class V>
Tree<K, V>::~Tree() 
{
	Root = deleteTree(Root);
}

template<class K, class V>
typename TreeNode<K, V>* Tree<K, V>::deleteTree(TreeNode<K, V>* node)
{
	if (node == NULL)
		return NULL;
	{
		deleteTree(node->Left);
		deleteTree(node->Right);
		node = NULL;
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
void Tree<K, V>::iterativeInsert(TreeNode<K, V>* node)
{
	//1st element
	if (Root == NULL)
	{
		Root = node;
		fillLeftMosts();
		connectPairs(Root);
		height = LeftMosts.Count();
		count++;
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
	current->Key < parent->Key ?
		parent->Left = current :
		parent->Right = current;

	//balancing and rebuilding tree
	if (parent->Parent != NULL)
	{
		TreeNode<K, V>* balancedNode = parent->Parent;
		while (balancedNode != NULL)
		{
			balancedNode = balanceTree(balancedNode);
			if (balancedNode->Parent == NULL)
			{
				Root = balancedNode;
				break;
			}
			else
			{
				(balancedNode->Key < balancedNode->Parent->Key) ?
					balancedNode->Parent->Left = balancedNode :
					balancedNode->Parent->Right = balancedNode;
				balancedNode = balancedNode->Parent;
			}
		}
	}
	fillLeftMosts();
	connectPairs(Root);
	height = LeftMosts.Count();
	count++;
}

template<typename K, class V>
void Tree<K, V>::iterativeRemove(K key)
{
	//search node to delete
	TreeNode<K, V>* current = searchDeep(Root, key);
	//replace node with min from right route
	TreeNode<K, V>* min = (current->Right == NULL) ?
		min = current->Left:
		getMin(current->Right);
	current->Value = min->Value;
	current->Key = min->Key;
	//deleting node
	TreeNode<K, V>* parent = min->Parent;
	parent->Left = NULL;
	min->Next->Prev = min->Prev->Next = NULL;
	min = NULL;
	//rebalance and rebuild tree
	while (parent != NULL)
	{
		parent = balanceTree(parent);
		if (parent->Parent == NULL)
		{
			Root = parent;
			break;
		}
		else
		{
			(parent->Key < parent->Parent->Key) ?
				parent->Parent->Left = parent :
				parent->Parent->Right = parent;
			parent = parent->Parent;
		}
	}
	connectPairs(Root);
	fillLeftMosts();
	height = LeftMosts.Count();
	count--;
	delete min;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::removeMin(TreeNode<K, V>* current)
{
	if (current->Left == NULL)
		return current->Right;
	current->Left = removeMin(current->Left);
	return balanceTree(current);
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
typename TreeNode<K, V>* Tree<K, V>::searchDeep(TreeNode<K, V>* current, K key , V value)
{
	while (current != NULL)
	{
		if (key != NULL)
		{
			if (current->Key == key)
				return current;
		}
		else if(value != NULL)
		{
			if (current->Value == value)
				return current;
		}
		current = (key < current->Key) ?
			current->Left :
			current->Right;
	}
	return current;
}

template<class K, class V>
typename TreeNode<K, V>* Tree<K, V>::searchWide(K key, V value)
{
	for (int i = 0; i < LeftMosts.Count(); i++)
	{
		TreeNode<K, V>* hcurrent = LeftMosts.GetValue(i);
		while (hcurrent != NULL)
		{
			if (key != NULL)
			{
				if (hcurrent->Key == key)
					return hcurrent;
			}
			else if (value != NULL)
			{
				if (hcurrent->Value == value)
					return hcurrent;
			}
			hcurrent = hcurrent->Next;
		}
	}
	return NULL;
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

template<typename K, class V>
void Tree<K, V>::fillLeftMosts()
{
	LeftMosts.Clear();
	TreeNode<K, V>* current = Root;
	while (current != NULL)
	{
		LeftMosts.AddToEnd(current);
		current = (current->Left != NULL) ?
			current->Left :
			current->Right;
	}
}

template<typename K, class V>
void Tree<K, V>::connectPairs(TreeNode<K, V>* parent)
{
	if (parent == NULL)
		return;
	if (parent->Right != NULL && parent->Left != NULL)
	{
		parent->Left->Next = parent->Right;
		parent->Right->Prev = parent->Left;
	}
	connectPairs(parent->Left);
	connectPairs(parent->Right);
}


template<class K, class V>
void Tree<K, V>::Add(V value, K key)
{
	TreeNode<K, V>* node = newNode(value, key);
	iterativeInsert(node);
}

template<class K, class V>
void Tree<K, V>::Remove(K key)
{
	iterativeRemove(key);
}

template<class K, class V>
bool Tree<K, V>::Find(K key, TreeNode<K, V>* &result, bool searchType)
{
	TreeNode<K, V>* outres = NULL;
	result = (searchType) ?
		searchDeep(Root, key) :
		searchWide(key);
	return (result) ? true : false;
}

template<class K, class V>
bool Tree<K, V>::Find(V value, bool searchType)
{
	TreeNode<K, V>* outres = NULL;
	outres = (searchType) ?
		searchDeep(Root, NULL, value) :
		searchWide(NULL, value);
	return (outres) ? true : false;
}

template<class K, class V>
typename Tree<K, V>& Tree<K, V>::operator= (const Tree<K, V>& obj)
{
	if (this == &obj)
		return *this;
	
	Root = obj.Root;
	return *this;
}

template<class K, class V>
void Tree<K, V>::PrintLevelOrder()
{
	int offset = LeftMosts.Count();
	for (int i = 0; i < LeftMosts.Count(); i++)
	{
		TreeNode<K, V>* hcurrent = LeftMosts.GetValue(i);
		for (int j = 0; j < offset; j++)
			std::cout << "\t ";
		while(hcurrent != NULL)
		{
			std::cout << hcurrent->Key;
			for (int j = 0; j < offset; j++)
				std::cout << "   ";
			hcurrent = hcurrent->Next;
		}
		offset--;
		std::cout << "\n\n";
	}
}