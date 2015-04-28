#include "DoubleList.h"
#include "Tree.h"
#include "Stack.h"

#include<iostream>

using namespace std;

int main(int argc, char** argv)
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

	cout << list.count() << endl;

	getchar();

	return 0;
}