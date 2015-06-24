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
	void add(const TYPE& item)
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

		size++;
	}

	/**
	* Deletes an item from the list
	*/
	void del(DListNode<TYPE>* item)
	{
		if (item != NULL)
		{
			if (item->prev != NULL)
			{
				item->prev->next = item->next;

				if (item->next != NULL)
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
				if (item->next)
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
		}
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
			if (index != size - 1)
			{
				DListNode<TYPE>*   nodeBeforeInsert = start;
				DListNode<TYPE>*   externalListNode = list.start;

				for (unsigned int i = 0; i < index; i++)
					nodeBeforeInsert = nodeBeforeInsert->next;

				DListNode<TYPE>*   tmp = nodeBeforeInsert->next;

				while (externalListNode != NULL)
				{
					DListNode<TYPE>*   newNode;
					newNode = new DListNode < TYPE >(externalListNode->data);

					nodeBeforeInsert->next = newNode;
					newNode->prev = nodeBeforeInsert;

					nodeBeforeInsert = nodeBeforeInsert->next;
					externalListNode = externalListNode->next;
				}

				tmp->prev = nodeBeforeInsert;
				nodeBeforeInsert->next = tmp;
			}

			else
			{
				DListNode<TYPE>*   externalListNode = list.start;

				for (; externalListNode != NULL; externalListNode = externalListNode->next)
					add(externalListNode->data);
			}
		}

		else
		{
			DListNode<TYPE>*   externalListNode = list.start;

			for (; externalListNode != NULL; externalListNode = externalListNode->next)
				add(externalListNode->data);
		}
	}

	const unsigned int delNodes(const unsigned int index, const unsigned int nodesToDelete)
	{
		unsigned int ret = 0;

		if (start != NULL)
		{
			DListNode<TYPE>*   tmp = start;
			for (unsigned int i = 0; i < index; i++)
				tmp = tmp->next;
			DListNode<TYPE>*  tmp2 = tmp;

			if (index + nodesToDelete < size)
			{
				for (unsigned int i = 0; i < nodesToDelete; i++)
				{
					tmp = tmp->next;
					del(tmp2);
					tmp2 = tmp;
					ret++;
				}
			}

			else
			{
				end = tmp->prev;

				while (tmp != NULL)
				{
					tmp = tmp->next;
					del(tmp2);
					tmp2 = tmp;
					ret++;
				}
			}
		}
		return ret;
	}

};
#endif /*__DList_H__*/