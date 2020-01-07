#pragma once
#include "TreeNode.h"

template<typename K, class V>
struct ListNode
{
	TreeNode<K, V>* Data;
	ListNode* Next;
};