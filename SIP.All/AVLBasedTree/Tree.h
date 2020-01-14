#pragma once
#include "TreeNode.h"
#include "List.h"
#include "List.cpp"

template<class K, class V>
class Tree
{
private:
	List<K, V> LeftMosts;
	TreeNode<K, V>* Root;
	
	
	//TreeNode<K, V>* recursiveInsert(TreeNode<K, V>* current, TreeNode<K, V>* node);
	void iterativeInsert(TreeNode<K, V>* node);
	TreeNode<K, V>* newNode(V value, K key = NULL);
	TreeNode<K, V>* deleteTree(TreeNode<K, V>* node);

	//TreeNode<K, V>* recursiveRemove(K key, TreeNode<K, V>* current);
	void iterativeRemove(K key);

	TreeNode<K, V>* searchDeep(TreeNode<K, V>* current, K key = NULL, V value = NULL);
	TreeNode<K, V>* searchWide(K key = NULL, V value = NULL);

	TreeNode<K, V>* getMin(TreeNode<K, V>* parent);
	TreeNode<K, V>* getMax(TreeNode<K, V>* parent);
	TreeNode<K, V>* removeMin(TreeNode<K, V>* current);
	int getHeight(TreeNode<K, V>* parent);
	TreeNode<K, V>* balanceTree(TreeNode<K, V>* parent);
	int balanceFactor(TreeNode<K, V>* parent);
	void fillLeftMosts();
	void connectPair(TreeNode<K, V>* pivot);
	void connectPairs(TreeNode<K, V>* pivot);
	TreeNode<K, V>* RotateR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateL(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateRL(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLR(TreeNode<K, V>* parent);
	int count = 0;
	int height = LeftMosts.Count();
public:
	Tree();
	~Tree();
	
	void Add(V value, K key = NULL);
	void Remove(K key);
	bool Find(K key, TreeNode<K, V>* &result, bool searchType);
	bool Find(V value, bool searchType);
	Tree<K, V>& operator = (const Tree<K, V>& othtree);
	int Height() { return height; }
	int Count() { return count; }
	void PrintAllInfo();
};

