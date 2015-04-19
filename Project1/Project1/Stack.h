#ifndef __Stack_H__
#define __Stack_H__

#define DYN_ARRAY_BLOCK_SIZE 16

template<class TYPE>
class Stack
{
private:

	TYPE*			data;
	unsigned int	allocatedMemory;
	unsigned int	elementsNumber;

public:
	// Constructors
	Stack() : allocatedMemory(0), elementsNumber(0), data(NULL)
	{
		alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	Stack(unsigned int capacity) : allocatedMemory(0), elementsNumber(0), data(NULL)
	{
		alloc(capacity);
	}

	// Destructor
	~Stack()
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

		data[elementsNumber++] = element;
	}

	TYPE pop()
	{
		TYPE ret = -1;

		if (data != NULL && elementsNumber > 0)
			ret = data[--elementsNumber];

		return ret;
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