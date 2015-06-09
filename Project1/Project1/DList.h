#ifndef __DList_H__
#define __DList_H__

#define NULL 0

/**
* Contains items from double linked list
*/
template<class TYPE>
struct DListNode
{
	TYPE                 data;
	DListNode<TYPE>*   next;
	DListNode<TYPE>*   prev;

	inline DListNode(const TYPE& _data)
	{
		data = _data;
		next = prev = NULL;
	}

	~DListNode()
	{}
};

/**
* Manages a double linked list
*/
template<class TYPE>
class DList
{

public:

	DListNode<TYPE>*   start;
	DListNode<TYPE>*   end;

private:

	unsigned int  size;

public:

	/**
	* Constructor
	*/
	inline DList()
	{
		start = end = NULL;
		size = 0;
	}

	/**
	* Destructor
	*/
	~DList()
	{
		clear();
	}

	/**
	* Get Size
	*/
	unsigned int count()
	{
		return size;
	}

	/**
	* Add new item
	*/
	unsigned int add(const TYPE& item)
	{
		DListNode<TYPE>*   newNode;
		newNode = new DListNode < TYPE >(item);

		if(start == NULL)
		{
			start = end = newNode;
		}
		else
		{
			newNode->prev = end;
			end->next = newNode;
			end = newNode;
		}

		return(++size);
	}

	/**
	* Deletes an item from the list
	*/
	bool del(DListNode<TYPE>* item)
	{
		if(item == NULL)
		{
			return (false);
		}

		// Now reconstruct the list
		if(item->prev != NULL)
		{
			item->prev->next = item->next;

			if(item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}
		}
		else
		{
			if(item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
		}

		delete item;
		--size;
		return(true);
	}

	/**
	* Destroy and free all mem
	*/
	void clear()
	{
		DListNode<TYPE>*   tmp = start;
		DListNode<TYPE>*  tmp2 = tmp;

		while(tmp != NULL)
		{
			tmp = tmp->next;
			delete tmp2;
			tmp2 = tmp;
		}

		start = end = NULL;
		size = 0;
	}

	TYPE getNode(const unsigned int index)
	{
		DListNode<TYPE>*   ret = start;

		for (unsigned int i = 0; i < index; i++)
			ret = ret->next;

		return ret->data;
	}

	void concatenate(const DList<TYPE>* list)
	{
		if (list->start != NULL)
		{
			DListNode<TYPE>*   tmp = list->start;
			while (tmp != NULL)
				add(tmp->data);
		}
	}

	void insertAfter(const unsigned int index, const DList<TYPE>& list)
	{
		if (start != NULL)
		{
			DListNode<TYPE>*   tmpFirstList = start;
			DListNode<TYPE>*   tmpSecondList = list.start;

			for (unsigned int i = 0; i < index; i++)
				tmpFirstList = tmpFirstList->next;

			for (unsigned int i = 0; i < tmpSecondList.count(); i++)
			{
				tmpFirstList->next->prev = tmpSecondList;
				tmpFirstList->next = tmpSecondList;

				tmpSecondList = tmpSecondList->next;
				tmpFirstList = tmpFirstList->next;
				size++;

				if (i == list.size)
					end = tmpSecondList;
			}
		}

		else
		{
			DListNode<TYPE>*   tmpFirstList = start;
			DListNode<TYPE>*   tmpSecondList = list.start;

			while (tmpSecondList != NULL)
			{
				if (tmpSecondList == list.start)
					start = tmpSecondList;

				tmpFirstList = tmpSecondList;
				tmpSecondList = tmpSecondList->next;
				tmpFirstList = tmpFirstList->next;
				size++;

				if (size == list.size)
					end = tmpSecondList;
			}
		}
	}

};
#endif /*__DList_H__*/