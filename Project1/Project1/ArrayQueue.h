#ifndef __ArrayQueue_H__
#define __ArrayQueue_H__

#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class ArrayQueue
{
private:

	TYPE*			data;
	unsigned int	allocatedMemory;
	unsigned int	elementsNumber;

public:
	// Constructors
	ArrayQueue() : allocatedMemory(0), elementsNumber(0), data(NULL)
	{
		alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	ArrayQueue(unsigned int capacity) : allocatedMemory(0), elementsNumber(0), data(NULL)
	{
		alloc(capacity);
	}

	// Destructor
	~ArrayQueue()
	{
		delete[] data;
	}

	//Getters
	unsigned int getCapacity() const
	{
		return allocatedMemory;
	}

	unsigned int count() const
	{
		return elementsNumber;
	}

	//Push & Pop
	void pushBack(const TYPE& element)
	{
		if (elementsNumber >= allocatedMemory)
		{
			alloc(allocatedMemory + DYN_ARRAY_BLOCK_SIZE);
		}

		for (unsigned int i = elementsNumber; i > 0; i--)
			data[i] = data[i - 1];
		data[0] = element;
		elementsNumber++;
	}

	TYPE pop()
	{

		if (data != NULL && elementsNumber > 0)
		{
			unsigned int i = elementsNumber - 1;
			TYPE ret = data[i];
			elementsNumber--;
			return ret;
		}

		else
			return NULL;
	}

	TYPE peek()
	{

		if (data != NULL && elementsNumber > 0)
		{
			unsigned int i = elementsNumber - 1;
			TYPE ret = data[i];
			return ret;
		}

		else
			return NULL;
	}

private:

	void alloc(unsigned int mem)
	{
		TYPE* tmp = data;

		allocatedMemory = mem;
		data = new TYPE[allocatedMemory];

		if (elementsNumber > allocatedMemory)
			elementsNumber = allocatedMemory;

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < elementsNumber; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}

};
#endif