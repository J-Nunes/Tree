#ifndef __Tree_H__
#define __Tree_H__

#include "Doublelist.h"

template<class TYPE>
struct TreeNode
{
	TYPE data;
	TreeNode<TYPE>* father;
	DoubleList<TYPE>* sons;
};


template<class TYPE>
class Tree
{
	private:
		TreeNode<TYPE>* rootNode;

	public:

		Tree(TYPE rootData)
		{
			rootNode = NULL;
			rootNode->data = rootData;
		}

		void add(TYPE data)
		{
			Tree<TYPE>* newNode = new Tree<TYPE>;
			newNode->data = data;
			rootNode.sons.add(newNode);
			newNode->father = rootNode;
		}
};

#endif // !__Tree_H__
