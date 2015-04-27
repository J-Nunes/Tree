#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Project1\Tree.h"
#include "..\Project1\Stack.h"
#include "..\Project1\DList.h"

#include<assert.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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
			Tree<int> tree(0);
			tree.add(1,0);
			tree.add(2,0);
			tree.add(3,1);
			tree.add(4,1);

			Assert::AreEqual(tree.findParent(1)->sons.count(), checker);
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
	};
}