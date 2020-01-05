#pragma once
#include <iostream>

template<typename K, class V>
struct TreeNode
{
	TreeNode* Left, * Right, * Next, * Prev;
	K Key;
	V Value;
};