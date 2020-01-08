#pragma once
#include "TreeNode.h"
#include "List.h"

template<typename T>
constexpr bool checkType = std::is_same<T, short>::value || std::is_same<T, long>::value || std::is_same<T, int>::value;

template<class K, class V>
class Tree
{
private:
	TreeNode<K, V>* Root;
	List<V, K> LeftMosts; //List of first node from each level

	//recursive deletion for tree
	TreeNode<K, V>* deleteTree(TreeNode<K, V>* t);
	//initializers for new nodes
	TreeNode<K, V>* newNode(K key, V value);
	TreeNode<K, V>* newNode(V value);
	//node insertion
	TreeNode<K, V>* recursiveInsert(TreeNode<K, V>* current, TreeNode<K, V>* node);
	TreeNode<K, V>* iterativeInsert(TreeNode<K, V>* node);
	//search methods
	TreeNode<K, V>* searchDeep(TreeNode<K, V>* t, K key);
	TreeNode<K, V>* searchWide(K key);
	bool searchDeepValue(TreeNode<K, V>* t, V value);
	bool searchWideValue(V value);
	//remove methods
	TreeNode<K, V>* removeDeep(K key, TreeNode<K, V>* root);
	TreeNode<K, V>* removeWide(V value);
	//balabce methods and helpers
	TreeNode<K, V>* balance_tree(TreeNode<K, V>* current);
	int balance_factor(TreeNode<K, V>* current);
	int getHeight(TreeNode<K, V>* current);
	TreeNode<K, V>* getMax(TreeNode<K, V>* current);
	TreeNode<K, V>* getMin(TreeNode<K, V>* current);
	void connect2Nodes(TreeNode<K, V>* parent);
	void fillLeftMosts();
	TreeNode<K, V>* removeMin(TreeNode<K, V>* current);

	TreeNode<K, V>* RotateRR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLL(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateLR(TreeNode<K, V>* parent);
	TreeNode<K, V>* RotateRL(TreeNode<K, V>* parent);
public:
	Tree();
	Tree(const Tree& othTree);
	~Tree();

	Tree<K, V>& operator=(const Tree<K, V>& obj);

	static_assert(checkType<K>, "Incorrect argument type (must be: int, long, short)");

	void Add(V value);
	void/*bool*/ Add(K key, V value);
	bool Remove(K key);
	bool RemoveWide(V value);
	bool Find(V value, bool searchType);
	bool Find(K key, V& value, bool searchType);
	void PrintAllInfo();
	void LevelOrderPrint();
	int Count = 0;
};