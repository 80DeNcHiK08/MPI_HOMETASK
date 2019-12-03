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
Tree<T>::TreeNode* Tree<T>::newNode(int key, T value)
{
	TreeNode *temp = new TreeNode;
	temp->key = key;
	temp->value = value;
	temp->left = temp->right = NULL;
	return temp;
}

template<class T>
Tree<T>::TreeNode* Tree<T>::insert(int key, T value, TreeNode* node)
{
	if (node == NULL) 
	{
		return newNode(key, value);
	}

	if (key < node->key)
	{
		node->left = insert(key, value, node->left);
	}
	else if (key > node->key)
	{
		node->right = insert(key, value, node->right);
	}
	return node;
}

template<class T>
Tree<T>::TreeNode* Tree<T>::deleteTree(TreeNode* t)
{
	if (t == NULL)
		return NULL;
	{
		freeSpace(t->left);
		freeSpace(t->right);
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
Tree<T>::TreeNode* Tree<T>::searchByKey(TreeNode* t, int key)
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

//searchDeep
//searchWide
//remove

template<typename T>
void Tree<T>::Add(int key, T value)
{
	this.root = Tree<T>::insert(key, value);
}

template<class T>
bool Tree<T>::TryRemove(int key)
{
	return true;
	//this.root = remove(t)
}

template<class T>
Tree<T>::TreeNode* Tree<T>::Find(int key)
{
	return searchByKey(this.root, key);
}