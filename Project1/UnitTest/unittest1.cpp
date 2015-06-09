#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Project1\Tree.h"
#include "..\Project1\Stack.h"
#include "..\Project1\DList.h"
#include "..\Project1\ArrayQueue.h"
#include "../Project1/DynamicArray.h"


#include<assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Fibonachi)
		{
			int checker = 13;
			
			unsigned int pos = 6;

			int tmp = 0, ret = 1;
			for (unsigned int i = 0; i < pos; i++)
			{
				ret += tmp;
				tmp = ret - tmp;
			}

			Assert::AreEqual(ret, checker);
		}
		
		TEST_METHOD(ArrayQueuePush)
		{
			unsigned int checker = 2;

			ArrayQueue<int> q;
			q.pushBack(1);
			q.pushBack(2);

			Assert::AreEqual(q.count(), checker);
		}

		TEST_METHOD(ArrayQueuePeek)
		{
			int checker = 1;
			unsigned int count_checker = 4;

			ArrayQueue<int> q;
			q.pushBack(1);
			q.pushBack(2);
			q.pushBack(3);
			q.pushBack(4);

			Assert::AreEqual(q.peek(), checker);
			Assert::AreEqual(q.count(), count_checker);
		}

		TEST_METHOD(ArrayQueuePop)
		{
			int checker = 1;
			unsigned int count_checker = 3;

			ArrayQueue<int> q;
			q.pushBack(1);
			q.pushBack(2);
			q.pushBack(3);
			q.pushBack(4);

			Assert::AreEqual(q.pop(), checker);
			Assert::AreEqual(q.count(), count_checker);
		}
		
		TEST_METHOD(TestAddAtRootNode)
		{
			unsigned int checker = 2;

			Tree<int> tree(0);
			tree.add(1);
			tree.add(2);

			Assert::AreEqual(tree.rootNode->sons.count(), checker);
		}

		TEST_METHOD(TestGeneralAdd)
		{
			unsigned int checker = 2;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);

			Assert::AreEqual(tree.findNode(4)->sons.count(), checker);
		}

		TEST_METHOD(TestGlobalClear)
		{
			unsigned int checker = 0;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);

			tree.clear();

			DList<TreeNode<int>*> list;
			tree.iterativePreOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestPartialClear)
		{
			unsigned int checker = 6;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);

			tree.clear(4);

			DList<TreeNode<int>*> list;
			tree.iterativePreOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestRecursivePreOrder)
		{
			unsigned int checker = 9;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);


			DList<TreeNode<int>*> list;
			tree.recursivePreOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestRecursivePostOrder)
		{
			unsigned int checker = 9;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);


			DList<TreeNode<int>*> list;
			tree.recursivePostOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestRecursiveInOrder)
		{
			unsigned int checker = 9;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);


			DList<TreeNode<int>*> list;
			tree.recursiveInOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestIterativePreOrder)
		{
			unsigned int checker = 9;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);


			DList<TreeNode<int>*> list;
			tree.iterativePreOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestIterativePostOrder)
		{
			unsigned int checker = 9;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);


			DList<TreeNode<int>*> list;
			tree.iterativePostOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TestIterativeInOrder)
		{
			unsigned int checker = 9;

			Tree<int> tree(6);
			tree.add(2, 6);
			tree.add(7, 6);
			tree.add(1, 2);
			tree.add(4, 2);
			tree.add(3, 4);
			tree.add(5, 4);
			tree.add(8, 7);
			tree.add(9, 8);


			DList<TreeNode<int>*> list;
			tree.iterativeInOrder(&list);

			Assert::AreEqual(list.count(), checker);
		}

		TEST_METHOD(TreeCalcAddition)
		{
			int checker = 55;

			Tree<int> tree(1);
			tree.add(2, 1);
			tree.add(3, 1);
			tree.add(4, 1);
			tree.add(5, 2);
			tree.add(6, 2);
			tree.add(7, 2);
			tree.add(8, 4);
			tree.add(9, 4);
			tree.add(10, 9);
			Assert::AreEqual((int)tree.recursiveCalcAddition(), checker);
			Assert::AreEqual((int)tree.iterativeCalcAddition(), checker);
		}


		TEST_METHOD(DynArray_Operator_concat)
		{
			DynamicArray<int> array(5);

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(4);
			array.pushBack(5);
			array.pushBack(8);

			DynamicArray<int> array2;

			array2.pushBack(991);
			array2.pushBack(992);
			array2.pushBack(993);

			array += array2;

			Assert::AreEqual((int)array.getElementsNumber(), 8);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 991);
			Assert::AreEqual((int)array[6], 992);
			Assert::AreEqual((int)array[7], 993);
		}

		TEST_METHOD(ListInsert)
		{
			DList<int> mylist;

			DList<int> mylist2;
			mylist2.add(1);
			mylist2.add(2);
			mylist2.add(3);

			DList<int> mylist3;
			mylist3.add(4);
			mylist3.add(5);
			mylist3.add(6);

			mylist.insertAfter(0, mylist2);

			Assert::AreEqual(mylist.getNode(0), 1);
			Assert::AreEqual(mylist.getNode(1), 2);
			Assert::AreEqual(mylist.getNode(2), 3);

			mylist.insertAfter(1, mylist3);

			Assert::AreEqual(mylist.getNode(0), 1);
			Assert::AreEqual(mylist.getNode(1), 2);
			Assert::AreEqual(mylist.getNode(2), 4);
			Assert::AreEqual(mylist.getNode(3), 5);
			Assert::AreEqual(mylist.getNode(4), 6);
			Assert::AreEqual(mylist.getNode(5), 3);

			mylist.insertAfter(0, mylist3);

			Assert::AreEqual(mylist.getNode(0), 1);
			Assert::AreEqual(mylist.getNode(1), 4);
			Assert::AreEqual(mylist.getNode(2), 5);
			Assert::AreEqual(mylist.getNode(3), 6);
			Assert::AreEqual(mylist.getNode(4), 2);
			Assert::AreEqual(mylist.getNode(5), 4);
			Assert::AreEqual(mylist.getNode(6), 5);
			Assert::AreEqual(mylist.getNode(7), 6);
			Assert::AreEqual(mylist.getNode(8), 3);

			Assert::IsTrue(1 == mylist.start->data);
			Assert::IsTrue(3 == mylist.end->data);
		}
	};
}