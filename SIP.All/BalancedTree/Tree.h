#pragma once
#include "TreeNode.h"
#include "List.h"

template<typename T>
constexpr bool checkType =
std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, int>::value;


template<class K, class V>
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
	TreeNode<K, V>* iterativeInsert(TreeNode<K, V>* current, TreeNode<K, V>* node);

	TreeNode<K, V>* balance_tree(TreeNode<K, V>* current);
	int balance_factor(TreeNode<K, V>* current);
	int getHeight(TreeNode<K, V>* current);
	K getMaxKey(TreeNode<K, V>* current);
	
	TreeNode<K, V>* RotateRR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLL(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateRL(TreeNode<K, V>* parent);

	TreeNode<K, V>* searchByKey(TreeNode<K, V>* t, K key);
	
	TreeNode<K, V>* searchDeep(TreeNode<K, V>* t, V value);
	TreeNode<K, V>* searchWide(TreeNode<K, V>* t, V value);
public:
	static_assert(checkType<K>, "Incorrect argument type (must be: int, long, short)");

	Tree();
	~Tree();

	void Add(K key, V value);
	void Add(V value);
	bool Remove(V value, bool searchtype);
	bool Find(V value, bool searchtype);
	bool Remove(K key);
	bool Find(K key, V& value);
};