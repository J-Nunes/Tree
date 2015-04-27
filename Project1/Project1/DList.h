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
		DListNode<TYPE>*   tmp;
		DListNode<TYPE>*  tmp2;
		tmp = start;

		while(tmp != NULL)
		{
			tmp = tmp->next;
			delete tmp2;
			tmp2 = tmp;
		}

		start = end = NULL;
		size = 0;
	}

};
#endif /*__DList_H__*/