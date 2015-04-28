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
			rootNode->sons.start = rootNode->sons.end = NULL;
		}

		TreeNode<TYPE>* add(const TYPE& data)
		{
			TreeNode<TYPE>* newNode = new TreeNode<TYPE>;
			newNode->data = data;
			rootNode->sons.add(newNode);
			newNode->parent = rootNode;
			newNode->sons.start = newNode->sons.end = NULL;
			return newNode;
		}

		TreeNode<TYPE>* add(const TYPE& data, const TYPE& parentData)
		{
			TreeNode<TYPE>* newNode = new TreeNode<TYPE>;
			newNode->data = data;
			newNode->parent = findNode(parentData);
			newNode->parent->sons.add(newNode);
			newNode->sons.start = newNode->sons.end = NULL;
			return newNode;
		}
		
		TreeNode<TYPE>* findNode(const TYPE& dataToFind)
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* nodeToReturn = rootNode;

			while (nodeToReturn->data != dataToFind)
			{
				DListNode<TreeNode<TYPE>*>* tmpListNode = nodeToReturn->sons.end;

				while (tmpListNode != NULL)
				{
					s.pushBack(tmpListNode->data);
					tmpListNode = tmpListNode->prev;
				}
				nodeToReturn = s.pop();
			}

			return nodeToReturn;
		}

		void clear()
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* tmpTreeNode = rootNode;

			while (tmpTreeNode != NULL)
			{
				DListNode<TreeNode<TYPE>*>* tmpListNode = tmpTreeNode->sons.end;

				while (tmpListNode != NULL)
				{
					s.pushBack(tmpListNode->data);
					tmpListNode = tmpListNode->prev;
				}
				delete tmpTreeNode;
				tmpTreeNode = s.pop();
			}
			rootNode = NULL;
		}

		void clear(const TYPE& dataToDelete)
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* tmpTreeNode = findNode(dataToDelete);

			DListNode<TreeNode<TYPE>*>* tmpListNode = tmpTreeNode->sons.end;

			//----Delete nodeToDelete of its parent list of sons
			tmpListNode = tmpTreeNode->parent->sons.start;

			while (tmpListNode->data != tmpTreeNode)
				tmpListNode = tmpListNode->next;

			tmpTreeNode->parent->sons.del(tmpListNode);
			//----

			while (tmpTreeNode != NULL)
			{
				tmpListNode = tmpTreeNode->sons.end;

				while (tmpListNode != NULL)
				{
					s.pushBack(tmpListNode->data);
					tmpListNode = tmpListNode->prev;
				}

				//Reset the list of sons of tmpTreeNode
				tmpTreeNode->sons.start = tmpTreeNode->sons.end = NULL;

				//delete tmpTreeNode
				delete tmpTreeNode;

				tmpTreeNode = s.pop();
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
			bool emptyList = true;

			while (tmpTreeNode != NULL)
			{
				if (emptyList==true)
				{
					if (tmpTreeNode->sons.start != NULL)
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
						emptyList = false;
					}
				}

				else
				{
					if (tmpTreeNode->sons.start != NULL && list->end->data != tmpTreeNode->sons.end->data)
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
		}

		void iterativeInOrder(DList<TreeNode<TYPE>*>* list)const
		{
			Stack<TreeNode<TYPE>*> s;
			TreeNode<TYPE>* tmpTreeNode = rootNode;
			bool emptyList = true;

			while (tmpTreeNode != NULL)
			{
				while (emptyList == true)
				{
					if (tmpTreeNode->sons.start != NULL)
					{
						s.pushBack(tmpTreeNode);
						s.pushBack(tmpTreeNode->sons.start->data);
						tmpTreeNode = s.pop();
					}

					else
					{
						list->add(tmpTreeNode);
						tmpTreeNode = s.pop();
						emptyList = false;
					}
				}

				if (tmpTreeNode->sons.start != NULL)
				{
					DListNode<TreeNode<TYPE>*>* tmpListNode = list->start;

					while (tmpListNode->data != tmpTreeNode->sons.start->data)
					{
						tmpListNode = tmpListNode->next;
						if (tmpListNode == NULL)
							break;
					}

					if (tmpListNode == NULL || tmpListNode->data != tmpTreeNode->sons.start->data)
					{
						s.pushBack(tmpTreeNode);
						s.pushBack(tmpTreeNode->sons.start->data);
						tmpTreeNode = s.pop();
					}

					else
					{
						if (list->end->data == tmpTreeNode->sons.end->data)
						{
							list->add(tmpTreeNode);
							tmpTreeNode = s.pop();
						}

						else
						{
							list->add(tmpTreeNode);
							s.pushBack(tmpTreeNode->sons.end->data);
							tmpTreeNode = s.pop();
						}
					}
				}

				else
				{
					list->add(tmpTreeNode);
					tmpTreeNode = s.pop();
				}
			}
		}
};

#endif 
