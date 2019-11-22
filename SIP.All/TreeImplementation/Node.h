#pragma once
#include<iostream>

struct Node
{
	int Key;
	int Value; //temporary
	Node *Left, *Right;

	Node() :Value(val), Left(NULL), Right(NULL)
	{

	}
};