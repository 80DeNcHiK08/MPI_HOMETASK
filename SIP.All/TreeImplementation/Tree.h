#pragma once
#include "TreeNode.h"
#include "List.h"

template<typename Tk, class T>
class Tree
{
private:
	List<T, Tk> leftmosts;
	TreeNode<Tk, T>* root;

	TreeNode<Tk, T>* deleteTree(TreeNode<Tk, T>* t);
	TreeNode<Tk, T>* newNode(Tk key, T value, int level);
	TreeNode<Tk, T>* newNode(T value, int level);
	TreeNode<Tk, T>* remove(Tk key, TreeNode<Tk, T>* t);
	TreeNode<Tk, T>* insert(Tk key, T value);
	TreeNode<Tk, T>* insert(T value);

	TreeNode<Tk, T>* searchByKey(TreeNode<Tk, T>* t, int key); //Deep search by key
	TreeNode<Tk, T>* searchDeep(TreeNode<Tk, T>* t, T value); //Deep search by value
	TreeNode<Tk, T>* searchWide(TreeNode<Tk, T>* t, T value); //Wide search by value
public:
	Tree();
	~Tree();

	void Add(Tk key, T value);
	void Add(T value);
	bool Remove(T value, bool searchtype);
	bool Remove(Tk key);

	bool Find(Tk key, T& value);
	bool Find(T value, bool searchtype);

	//int Count = Count.get();
	int Count = 0;
};