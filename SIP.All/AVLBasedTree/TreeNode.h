#pragma once
#include <iostream>

template<class K, class V>
struct TreeNode
{
	TreeNode* Left, *Right, *Next, *Prev, *Parent;
	K Key;
	V Value;
};