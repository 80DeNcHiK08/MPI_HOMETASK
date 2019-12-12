#pragma once
#include <iostream>

template<typename Tk, class T>
struct TreeNode
{
	TreeNode* left, * right, * l_next, * l_prev;
	int level;
	Tk key;
	T value;
};