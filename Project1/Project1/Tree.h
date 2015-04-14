#ifndef __Tree_H__
#define __Tree_H__

#include "Doublelist.h"

template<class TYPE>
struct TreeNode
{
	TYPE data;
	TreeNode<TYPE>* parent;
	DoubleList<TreeNode*> sons;
	
	//--------PRE ORDER--------
		void visitAll(DoubleList<TYPE>* list);
		{
			list.Add(data);
			for (unsigned int i = 0; i < sons.count(); i++)
				visitAll(list);
		}
};


template<class TYPE>
class Tree
{
	private:
		TreeNode<TYPE>* rootNode;

	public:

		Tree(const TYPE& rootData)
		{
			rootNode = new TreeNode<TYPE>;
			rootNode->data = rootData;
			rootNode->parent = NULL;
		}

		TreeNode<TYPE>* add(const TYPE& data)
		{
			TreeNode<TYPE>* newNode = new TreeNode<TYPE>;
			newNode->data = data;
			rootNode->sons.add(newNode);
			newNode->parent = rootNode;
			return newNode;
		}

		TreeNode<TYPE>* add(const TYPE& data, TreeNode<TYPE>* parentNode)
		{
			TreeNode<TYPE>* newNode = new TreeNode<TYPE>;
			newNode->data = data;
			parentNode.sons.add(newNode);
			newNode->parent = parentNode;
			return newNode;
		}

		//--------PRE ORDER--------
		void visitAllNodes(DoubleList<TYPE>* list)const;
		{
		rootNode.visitAll(list);
		}
		
};

#endif // !__Tree_H__
