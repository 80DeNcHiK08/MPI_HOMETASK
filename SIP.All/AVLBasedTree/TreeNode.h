#pragma once
#include <iostream>

template<class K, class V>
struct TreeNode
{
	K Key;
	TreeNode* Parent, *Left, *Right, *Next, *Prev;
	V Value;
};