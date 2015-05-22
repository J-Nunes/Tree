#ifndef __ListStack_H__
#define __ListStack_H__

#include "Dlist.h"
#include "Stack.h"

//#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class ListStack
{
private:

	DList<TYPE> stackList;

public:
	// Constructors
	ListStack()
	{}

	// Destructor
	~ListStack()
	{}


	//Push & Pop
	void pushBack(const TYPE& element)
	{
		add(element);
	}

	TYPE* pop()
	{
		if (stackList.start != NULL)
		{
			TYPE* ret;
			DListNode<TYPE>* tmp = stackList.end;
			ret = tmp->data;
			if (stackList.del(tmp))
				return ret;
			else
				return NULL;
		}

		else
			return NULL;
	}

	TYPE* peek()
	{
		if (stackList.start != NULL)
		{
			TYPE* ret;
			DListNode<TYPE>* tmp = stackList.end;
			ret = tmp->data;
			return ret;
		}

		else
			return NULL;
	}

	unsigned int count()
	{
		return stackList.count();
	}

};
#endif