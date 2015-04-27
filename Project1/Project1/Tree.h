#ifndef __Tree_H__
#define __Tree_H__

#include "Dlist.h"
#include "Stack.h"

template<class TYPE>
struct TreeNode
{
	TYPE data;
	TreeNode<TYPE>* parent;
	DList<TreeNode<TYPE>*> sons;
	
	void preOrder(DList<TreeNode<TYPE>*>* list)
	{
		list->add(this);

		DListNode<TreeNode*>* tmp = sons.start;

		for (; tmp!=NULL; tmp=tmp->next)
			tmp->data->preOrder(list);
	}

	void postOrder(DList<TreeNode<TYPE>*>* list)
	{
		DListNode<TreeNode*>* tmp = sons.start;

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->postOrder(list);
		
		list->add(this);
	}

	void inOrder(DList<TreeNode<TYPE>*>* list)
	{
		DListNode<TreeNode*>* tmp = sons.start;

		for (unsigned int i = 0;
			i < sons.count() / 2;
			i++, tmp = tmp->next)
			{
				tmp->data->inOrder(list);
			}

		list->add(this);

		for (unsigned int i = sons.count() / 2;
			i < sons.count();
			i++, tmp = tmp->next)
			{
				tmp->data->inOrder(list);
			}
	}
};


template<class TYPE>
class Tree
{
	public:
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

		TreeNode<TYPE>* add(const TYPE& data, const TYPE& parentData)
		{
			TreeNode<TYPE>* newNode = new TreeNode<TYPE>;
			newNode->data = data;
			newNode->parent = findParent(parentData);
			newNode->parent->sons.add(newNode);
			return newNode;
		}
		
		TreeNode<TYPE>* findParent(const TYPE& dataToFind)
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* nodeToReturn = rootNode;

			while (nodeToReturn->data != dataToFind)
			{
				DListNode<TreeNode<TYPE>*>* tmp = nodeToReturn->sons.end;

				while (tmp != NULL)
				{
					s.pushBack(tmp->data);
					tmp = tmp->prev;
				}
				nodeToReturn = s.pop();
			}

			return nodeToReturn;
		}

		void clear()
		{
			DList<TreeNode<TYPE>*> list;
			iterativePreOrder(&list);
			list.clear();
			rootNode = NULL;
		}

		void clear(TreeNode<TYPE>* nodeToDelete)const
		{
			Stack<TreeNode<TYPE>> s;
			TreeNode<TYPE>* tmpNode = nodeToDelete;

			while (tmpNode != NULL)
			{
				DListNode<TreeNode>* tmp = sons.end;

				while (tmp != NULL)
				{
					s.push(tmp->data);
					tmp = tmp->prev;
				}

				delete tmpNode;
				tmpNode = s.pop;
			}
		}

		void recursivePreOrder(DList<TreeNode<TYPE>*>* list)const
		{
			rootNode->preOrder(list);
		}
		
		void recursivePostOrder(DList<TreeNode<TYPE>*>* list)const
		{
			rootNode->postOrder(list);
		}

		void recursiveInOrder(DList<TreeNode<TYPE>*>* list)const
		{
			rootNode->inOrder(list);
		}

		void iterativePreOrder(DList<TreeNode<TYPE>*>* list)const
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* tmpTreeNode = rootNode;

			while (tmpTreeNode != NULL)
			{
				list->add(tmpTreeNode);
				DListNode<TreeNode<TYPE>*>* tmpListNode = tmpTreeNode->sons.end;

				while (tmpListNode != NULL)
				{
					s.pushBack(tmpListNode->data);
					tmpListNode = tmpListNode->prev;
				}
				tmpTreeNode = s.pop();
			}
		}

		void iterativePostOrder(DList<TreeNode<TYPE>*>* list)const
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* tmpTreeNode = rootNode;

			while (tmpTreeNode != NULL)
			{
				if (tmpTreeNode->sons.start != NULL && list->end != tmpTreeNode->sons.end)
				{
					s.pushBack(tmpTreeNode);

					DListNode<TreeNode<TYPE>*>* tmpListNode = tmpTreeNode->sons.end;

					while (tmpListNode != NULL)
					{
						s.pushBack(tmpListNode->data);
						tmpListNode = tmpListNode->prev;
					}
					tmpTreeNode = s.pop();
				}

				else
				{
					list->add(tmpTreeNode);
					tmpTreeNode = s.pop();
				}
			}
			
		}

		void iterativeInOrder(DList<TreeNode<TYPE>*>* list)const
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* tmpNode = rootNode;

			while (tmpNode != NULL)
			{
				if (tmpNode->sons.start != NULL)
				{
					DListNode<TreeNode<TYPE>*>* tmp = tmpNode->sons.start;
					
					if (list->end != tmpNode->sons.start)
					{
						s.pushBack(tmpNode);
						s.pushBack(tmpNode->sons.start->data);
						tmpNode = s.pop();
					}

					else
					{
						if (list->end == tmpNode->sons.end)
						{
							list->add(tmpNode);
							tmpNode = s.pop();
						}

						else
						{
							list->add(tmpNode);
							s.pushBack(tmpNode->sons.end->data);
							tmpNode = s.pop();
						}
					}
				}

				else
				{
					list->add(tmpNode);
					tmpNode = s.pop();
				}
			}
		}
};

#endif 
