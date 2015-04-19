#ifndef __Tree_H__
#define __Tree_H__

#include "Dlist.h"
#include "Stack.h"

template<class TYPE>
struct TreeNode
{
	TYPE data;
	TreeNode<TYPE>* parent;
	DList<TreeNode*> sons;
	
	void preOrder(DList<TYPE>* list);
	{
		list.add(data);

		DListNode<TreeNode*>* tmp = sons.start;

		for (; tmp!=NULL; tmp=tmp->next)
			tmp->value->preOrder(list);
	}

	void postOrder(DList<TYPE>* list);
	{
		DListNode<TreeNode*>* tmp = sons.start;

		for (; tmp != NULL; tmp = tmp->next)
			tmp->value->postOrder(list);
		
		list.add(data);
	}

	void inOrder(DList<TYPE>* list);
	{
		DListNode<TreeNode*>* tmp = sons.start;

		for (; tmp != NULL; tmp = tmp->next)
		{
			if (tmp != sons.start)
			list.add(data);

			tmp->value->inOrder(list);
		}

		list.add(data);
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

		void recursivePreOrder(DList<TYPE>* list)const;
		{
			rootNode.preOrder(list);
		}
		
		void recursivePostOrder(DList<TYPE>* list)const;
		{
			rootNode.postOrder(list);
		}

		void recursiveInOrder(DList<TYPE>* list)const;
		{
			rootNode.inOrder(list);
		}

		void iterativePreOrder(DList<TYPE>* list)const;
		{
			Stack<TreeNode> s;
			TreeNode<TYPE>* tmpNode = rootNode;

			while (tmpNode != NULL)
			{
				list.add(tmpNode);
				DListNode<TreeNode>* tmp = sons.end;

				while (tmp != NULL)
				{
					s.push(tmp->data);
					tmp = tmp->prev;
				}
				tmpNode = s.pop;
			}
		}

		void iterativePostOrder(DList<TYPE>* list)const;
		{
			Stack<TreeNode> s;
			TreeNode<TYPE>* tmpNode = rootNode;

			while (tmpNode != NULL)
			{
				if (tmpNode->sons.start != NULL && list->end != tmpNode->sons.end)
				{
						s.push(tmpNode);

						DListNode<TreeNode>* tmp = sons.end;

						while (tmp != NULL)
						{
							s.push(tmp->data);
							tmp = tmp->prev;
						}
						tmpNode = s.pop;
				}

				else
				{
					list.add(tmpNode);
					tmpNode = s.pop;
				}
			}
			
		}

		void iterativeInOrder(DList<TYPE>* list)const;
		{
			Stack<TreeNode> s;
			TreeNode<TYPE>* tmpNode = rootNode;

			while (tmpNode != NULL)
			{
				if (tmpNode->sons.start != NULL)
				{
					if (list->end != tmpNode->sons.start)
					{
						s.push(tmpNode);
						s.push(tmp->sons.start);
						tmpNode = s.pop;
					}

					else
					{
						if (list->end == tmpNode->sons.end)
						{
							list.add(tmpNode);
							tmpNode = s.pop;
						}

						else
						{
							list.add(tmpNode);
							s.push(tmp->sons.end);
							tmpNode = s.pop;
						}
					}
				}

				else
				{
					list.add(tmpNode);
					tmpNode = s.pop;
				}
			}
		}
};

#endif // !__Tree_H__
