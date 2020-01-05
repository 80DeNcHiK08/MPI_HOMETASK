#pragma once
#include "TreeNode.h"
#include "List.h"

template<typename K, class V>
class Tree
{
private:
	List<V, K> LeftMosts;
	TreeNode<K, V>* Root;

	TreeNode<K, V>* deleteTree(TreeNode<K, V>* t);
	TreeNode<K, V>* newNode(K key, V value);
	TreeNode<K, V>* newNode(V value);
	TreeNode<K, V>* remove(K key, TreeNode<K, V>* root);
	TreeNode<K, V>* recursiveInsert(TreeNode<K, V>* current, TreeNode<K, V>* node);
	TreeNode<K, V>* balance_tree(TreeNode<K, V>* current);
	int balance_factor(TreeNode<K, V>* current);
	int getHeight(TreeNode<K, V>* current);
	K getMaxKey(TreeNode<K, V>* current);
	TreeNode<K, V>* RotateRR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLL(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateRL(TreeNode<K, V>* parent);

	TreeNode<K, V>* searchByKey(TreeNode<K, V>* t, K key); //Deep search by key
	TreeNode<K, V>* searchDeep(TreeNode<K, V>* t, V value); //Deep search by value
	TreeNode<K, V>* searchWide(TreeNode<K, V>* t, V value); //Wide search by value
public:
	Tree();
	~Tree();

	void Add(K key, V value);
	void Add(V value);
	bool Remove(V value, bool searchtype);
	bool Remove(K key);

	bool Find(K key, V& value);
	bool Find(V value, bool searchtype);
};