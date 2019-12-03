#pragma once
#include <iostream>

template<class T>
class Queue
{
private:
	struct QueueNode
	{
		T *trans;
		QueueNode *next;
	};
	QueueNode *head;
public:
	Queue()
	{
		head = NULL;
	}

	bool IsEmty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void addtoQueue(T *tmp)
	{
		QueueNode *qn = new QueueNode;
		qn->trans = tmp;

		if (head == NULL)
		{
			head = qn;
			qn->next = NULL;
		}
		else
		{
			QueueNode *tmp_c = head;

			while (tmp_c->next != NULL)
			{
				tmp_c = tmp_c->next;
			}

			tmp_c->next = qn;
			qn->next = NULL;
		}
	}

	T *delQueue()
	{
		QueueNode *cur = head->next;
		T *tmp_c = head->trans;

		if (head != NULL)
		{
			delete head;
			head = cur;
			return tmp_c;
		}
		else
		{
			return NULL;
		}
	}
};

