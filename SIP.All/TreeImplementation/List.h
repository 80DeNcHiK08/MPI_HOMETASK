#pragma once

template<typename Tk>
class List
{
	struct ListNode
	{
		Tk data;
		ListNode *next, prev;
	};
	ListNode* head, tail;

public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
	~List()
	{

	}
};