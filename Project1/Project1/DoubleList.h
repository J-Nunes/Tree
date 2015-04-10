#include <iostream>
#ifndef __DoubleList_H__
#define __DoubleList_H__


template<class TYPE>
struct doubleNode
{
	TYPE value;
	doubleNode<TYPE>* next;
	doubleNode<TYPE>* previous;
};


template<class TYPE>
class DoubleList
{
private:
	doubleNode<TYPE>* start;

public:

	DoubleList()
	{
		start = NULL;
	}

	~DoubleList()
	{
		delAll();
	}


	void add(TYPE value)
	{
		doubleNode<TYPE>* newNode = new doubleNode<TYPE>;
		newNode->value = value;
		newNode->next = NULL;
		newNode->previous = NULL;

		if (start == NULL)
		{
			start = newNode;
		}

		else
		{
			doubleNode<TYPE>* tmp = start;

			while (tmp->next != NULL)
			{

				tmp = tmp->next;
				tmp->next = newNode;
			}
			tmp->next = newNode;
			newNode->previous = tmp;
		}
	}

	doubleNode<TYPE>* getNode(unsigned int position) const
	{
		if (start != NULL && position < count())
		{
			doubleNode<TYPE>* tmp = start;

			for (unsigned int i = 0; i < position; i++)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		return NULL;
	}

	bool del(doubleNode<TYPE>* nodeToDelete)
	{
		if (nodeToDelete != NULL && start != NULL)
		{
			if (nodeToDelete != start)
			{
				doubleNode<TYPE>* tmp = start;


				while (tmp->next != nodeToDelete)
				{
					tmp = tmp->next;
					if (tmp->next == NULL)
					{
						return false;
					}
				}

				tmp->next = nodeToDelete->next;
				doubleNode<TYPE>* tmp2 = nodeToDelete;
				tmp2 = tmp2->next;
				tmp2->previous = tmp;
				delete nodeToDelete;
				return true;
			}
			else
			{
				start = start->next;
				delete nodeToDelete;
				return true;
			}
		}
	}

	unsigned int count() const
	{
		unsigned int counter = 0;
		doubleNode* tmp = start;

		if (start != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				counter++;
			}
		}
		return counter;
	}

	bool delAll()
	{
		if (start != NULL)
		{
			doubleNode<TYPE>* tmp = start;

			while (tmp->next != NULL)
			{
				doubleNode<TYPE>* tmp2 = tmp;
				tmp = tmp->next;
				delete tmp2;
			}
			delete tmp;
			start = NULL;
			return true;
		}

		else{
			return false;
		}
	}
};

#endif