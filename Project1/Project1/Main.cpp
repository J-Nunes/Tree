#include "DoubleList.h"
#include "Tree.h"
#include "Stack.h"
#include "DynamicArray.h"

#include<iostream>

using namespace std;

int main(int argc, char** argv)
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
	cout << mylist.count() << endl;

	mylist.insertAfter(1, mylist3);	
	cout << mylist.count() << endl;

	mylist.insertAfter(0, mylist3);

	cout << mylist.count() << endl ;
	cout << mylist.start->data << endl;
	cout << mylist.end->data << endl;

	getchar();

	return 0;
}