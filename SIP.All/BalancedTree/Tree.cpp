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
	temp->Left = temp->Right = temp->Prev = temp->Next = NULL;
	return temp;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::newNode(V value)
{
	TreeNode<K, V>* temp = new TreeNode<K, V>;
	temp->Value = value;
	temp->Left = temp->Right = temp->Prev = temp->Next = NULL;
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
		current = balance_tree(current);
	}
	else if (node->Key > current->Key)
	{
		current->Right = recursiveInsert(current->Right, node);
		current = balance_tree(current);
	}
	return current;
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
	return current;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::remove(K key, TreeNode<K, V>* root)
{
	if (root = NULL) { return NULL; }
	else
	{
		if (key < root->Key)
		{
			root->Left = remove(key, root->Left);
			if (balance_factor(root) == -2)
			{
				root = (balance_factor(root->Right) <= 0) ?
					RotateRR(root) :
					RotateRL(root);
			}
		}
		else if (key > root->Key)
		{
			root->Right = remove(key, root->Right);
			if (balance_factor(root) == 2)
			{
				root = (balance_factor(root->Left) >= 0) ?
					RotateLL(root) :
					RotateLR(root);
			}
		}
		else
		{
			if (root->Right != NULL)
			{
				TreeNode<K, V>* parent = root->Right;
				while (parent->Left != NULL)
				{
					parent = parent->Left;
				}
				root->Key = parent->Key;
				root->Right = remove(parent->Key, root->Right);
				if (balance_factor(root) == 2)
				{
					root = (balance_factor(root->Left) >= 0) ?
						RotateLL(root) :
						RotateLR(root);
				}
			}
			else
			{
				return root->Left;
			}
		}
		return root;
	}
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateRR(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Right;
	parent->Right = pivot->Left;
	pivot->Left = parent;
	return pivot;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateLL(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Left;
	parent->Left = pivot->Right;
	pivot->Right = parent;
	return pivot;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateLR(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Left;
	parent->Left = RotateRR(pivot);
	return RotateLL(parent);
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::RotateRL(TreeNode<K, V>* parent)
{
	TreeNode<K, V>* pivot = parent->Right;
	parent->Right = RotateLL(pivot);
	return RotateRR(parent);
}

template<typename K, class V>
K Tree<K, V>::getMaxKey(TreeNode<K, V>* current)
{
	K max = 0;
	while (current != NULL)
	{
		max = current->Key;
		current = current->Right;
	}
	return max;
}

template<typename K, class V>
typename TreeNode<K, V>* Tree<K, V>::searchByKey(TreeNode<K, V>* current, K key)
{
	if (current == NULL)
	{
		return NULL;
	}
	else if (key < current->Key)
	{
		return (key == current->Key) ?
			current :
			searchByKey(current->Left, key);
	}
	else
	{
		return (key == current->Key) ?
			current :
			searchByKey(current->Right, key);
	}
}

//Public Methods

template<typename K, class V>
void Tree<K, V>::Add(K key, V value)
{
	TreeNode<K, V>* newnode = newNode(key, value);
	this->Root = (this->Root == NULL) ? 
		this->Root = newnode : recursiveInsert(this->Root, newnode);
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
		newnode->Key = getMaxKey(this->Root) + 1;
		this->Root = recursiveInsert(this->Root, newnode);
	}
}

template<typename K, class V>
bool Tree<K, V>::Remove(K key)
{
	TreeNode<K, V>* result = Tree<K, V>::remove(key, this->Root);
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
bool Tree<K, V>::Find(K key, V& value)
{
	TreeNode<K, V>* result = searchByKey(this->Root, key);
	value = (result != NULL) ? result->Value : NULL;
	return (value == NULL) ? false : true;
}