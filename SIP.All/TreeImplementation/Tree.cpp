#include "pch.h"
#include "Tree.h"

template<class T>
Tree<T>::Tree()
{
	root = NULL;
}

template<class T>
Tree<T>::~Tree()
{
	root = deleteTree(root);
}

template<class T>
typename Tree<T>::TreeNode *Tree<T>::newNode(int key, T value)
{
	TreeNode *temp = new TreeNode;
	temp->key = key;
	temp->value = value;
	temp->left = temp->right = NULL;
	return temp;
}

template<class T>
typename Tree<T>::TreeNode* Tree<T>::deleteTree(TreeNode* t)
{
	if (t == NULL)
		return NULL;
	{
		deleteTree(t->left);
		deleteTree(t->right);
		delete t;
	}
	return NULL;
}

template<class T>
int Tree<T>::height(TreeNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return(lheight + 1);
		else
			return(rheight + 1);
	}
}

template<typename T>
typename Tree<T>::TreeNode* Tree<T>::searchByKey(TreeNode* t, int key)
{
	if (t == NULL)
	{
		return NULL;
	}
	else if(key < t->key)
	{
		return searchDeep(t->left, key);
	}
	else if (key > t->key)
	{
		return searchDeep(t->right, key);
	}
	else
	{
		return t;
	}
}

template<class T>
typename Tree<T>::TreeNode* Tree<T>::findMax(TreeNode* t)
{
	if (t == NULL)
		return NULL;
	else if (t->Right == NULL)
		return t;
	else
		return findMax(t->Right);
}

//searchDeep
template<class T>
typename Tree<T>::TreeNode* Tree<T>::searchDeep(TreeNode* t, T value)
{
	if (t == NULL)
	{
		return NULL;
	}
	if (t->value == value)
	{
		return t;
	}
	searchDeep(t->left, value);
	searchDeep(t->right, value);
}

template<class T>
typename Tree<T>::TreeNode* Tree<T>::searchWide(TreeNode* t, T value)
{
	Queue<TreeNode> storage;
	storage.addtoQueue(t);

	TreeNode *tmp;
	while (!storage.IsEmtpy())
	{
		tmp = storage.delQueue();
		if (tmp->value == value)
		{
			return tmp;
		}

		if (tmp->left != NULL)
		{
			storage.addtoQueue(tmp->left);
		}
		if (tmp->right != NULL)
		{
			storage.addtoQueue(tmp->right);
		}
	}
	return NULL;
}

template<typename T>
typename Tree<T>::TreeNode* Tree<T>::insert(int key, T value, TreeNode* node)
{
	TreeNode* newnode = newNode(key, value);
	TreeNode* x = root;
	TreeNode* y = NULL;
	while (x != NULL)
	{
		y = x;
		if (key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	if (y == NULL)
	{
		y = newnode;
	}
	else if (key < y->key)
	{
		y->left = newnode;
	}
	else
	{
		y->right = newnode;
	}
	return y;
}

template<typename T>
void Tree<T>::Add(int key, T value)
{
	if (root == NULL)
	{
		root = insert(key, value, root);
	} 
	else
	{
		insert(key, value, root);
	}
}

template<class T>
bool Tree<T>::Remove(int key)
{
	TreeNode* tmp;
	searchByKey();
}

template<class T>
bool Tree<T>::Remove(T value, bool searchType)
{
	if (searchType)
	{

	}
	else
	{

	}
}

template<class T>
bool Tree<T>::Find(int key, T& value)
{
	if (searchByKey(root, key) != NULL)
	{
		value = searchByKey(root, key)->value;
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool Tree<T>::Find(T value, bool searchtype)
{
	if (searchtype)
	{
		if (searchDeep(root, value) != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (searchWide(root, value) != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}