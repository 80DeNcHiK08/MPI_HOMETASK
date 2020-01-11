#pragma once
#include <iostream>

template<class K, class V>
struct TreeNode
{
	K Key;
	int Balance;
	TreeNode* Parent, *Left, *Right, *Next, *Prev;
	V Value;
};