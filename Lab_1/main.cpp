#include <iostream>
#include <string>
using namespace std;

#include "Lab1Tests.hpp"
#include "DoublyLinkedList.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    SequentialListTest seq_test;
    DoublyLinkedListTest linked_test;

    bool seq_test1_passed = seq_test.test1();
    bool seq_test2_passed = seq_test.test2();
    bool seq_test3_passed = seq_test.test3();

    bool linked_test1_passed = linked_test.test1();
    bool linked_test2_passed = linked_test.test2();
    bool linked_test3_passed = linked_test.test3();

    cout << "---Sequential List Tests---" << endl;
    cout << "Test1: " << get_status_str(seq_test1_passed) << endl;
    cout << "Test2: " << get_status_str(seq_test2_passed) << endl;
    cout << "Test3: " << get_status_str(seq_test3_passed) << endl;
    cout << endl;
    cout << "---Linked List Tests---" << endl;
    cout << "Test1: " << get_status_str(linked_test1_passed) << endl;
    cout << "Test2: " << get_status_str(linked_test2_passed) << endl;
    cout << "Test3: " << get_status_str(linked_test3_passed) << endl;

    system("pause");
}

//test main is below
//
//int main()
//{
//	int value = 11;
//	DoublyLinkedList linked_test;
//	if (linked_test.size() == 0)
//		cout << "worked size";
//	else
//		cout << "didn't work";
//	if (linked_test.empty())
//		cout << "worked empty";
//	cout << endl;
//	if (!linked_test.full())
//	{
//		cout << "full worked" << endl;
//	}
//	if(linked_test.insert_front(value))
//		cout << "worked";
////	if (linked_test.getNode(0) == NULL)
////	{
////		cout << "Head worked" <<endl;
////	}
//	else
//		cout << "didn't work";
//	system("pause");
//	linked_test.insert_front(1000);
//	linked_test.insert_front(292);
//
//	linked_test.print();
//	linked_test.insert_front(19292);
//	linked_test.insert_back(123);
//
//	linked_test.print();
//	cout <<"\nnow removing";
//	linked_test.remove_front();
//	linked_test.print();
//	cout <<"\n now removing back";
//	linked_test.remove_back();
//	linked_test.print();
//	cout << "inserting in the second  position with 10\n";
//	linked_test.insert(10,1);
//	linked_test.print();
//	cout <<"\n now deleting the second position (the one with 10)\n";
//	linked_test.remove(1);
//	linked_test.print();
//	system("pause");
//	cout <<"\n now inserting a 99 at position 0 and going to return 0 with a search";
//	linked_test.insert(99,0);
//	linked_test.print();
//	system("pause");
//	cout << endl << linked_test.search(99) << " is the index where 99 is\n";
//	linked_test.insert(19090,4);
//	linked_test.print();
//	linked_test.insert(12312,6);
//	linked_test.print();
//	cout << endl << linked_test.search(12312) << " is the index where 12312 is\n";
//	cout << "now trying to output the first value in he list\n";
//	system("pause");
//	cout << linked_test.select(0);
//	linked_test.print();
//	cout << "now gonna try to replace the first value with a 50";
//	system("pause");
//	linked_test.replace(0,50);
//	linked_test.print();
//	cout << "output the previous address, value, and next address of head_\n";
////	cout << "prev: " << linked_test.getNode(0) -> prev <<endl;
////	cout << "value: "<< linked_test.getNode(0) -> value << endl;
////	cout << "next: " << linked_test.getNode(0) -> next << endl;
//	if (linked_test.full())
//	{
//		cout << "The list is full" << endl;
//	}
//	else
//	{
//		cout << "The list is not full" << endl;
//		cout << "The list has a capacity of " << linked_test.CAPACITY << endl;
//	}
//
//	system("pause");
//
//
//}
//

