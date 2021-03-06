#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data) // @suppress("Class members should be properly initialized")
{
	value = data;
	next = nullptr;
	prev = nullptr;
}
DoublyLinkedList::DoublyLinkedList()
{
	size_ = 0;
	head_ = nullptr;
	tail_ = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (head_ != tail_)
	{
		Node* temp = head_->next;
		delete head_;
		head_ = temp;
				//above may cause problems
	}
}

bool DoublyLinkedList::empty() const
{
	return (size_ == 0);
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	cout << "Printing List\n";
	if (empty())
	{
		cout << endl << "Nothing to Print" << endl;
	}
	else
	{
		Node* current = head_;
		int index = 0;
		while (current != tail_)
		{
			cout << "Node "<< index << " " << current->value << endl;
			current = current->next;
			index++;
		}
		cout << "Node " << index << " " << tail_ -> value << endl;
		cout << "End of list \n";
	}
}

bool DoublyLinkedList::insert_front(DataType value)
{
	if(full())
		return false;
	Node* front = new Node(value);
	if (size_ == 0)
	{
		front -> prev = nullptr;
		front -> next = nullptr;
		head_ = front;
		tail_ = front;
	}
	else
	{
		Node* temp = head_;
		head_ = front;
		front -> next = temp;
		temp -> prev = front;
		front -> prev = nullptr;
	}
	size_++;
	return true;
}

bool DoublyLinkedList::remove_front()
{
	if (empty())
		return false;
	if (size_ == 1)
	{
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
	}
	else
	{
		Node* temp = head_ -> next;
		delete head_;
		temp -> prev = nullptr;
		head_ = temp;
	}
	size_--;
	return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{//check if  you have to even use delete
		if(full())
			return false;
		Node* back = new Node(value);
		if (size_ == 0)
		{
			back -> next = nullptr;
			back -> prev = nullptr;
			head_ = back;
			tail_ = back;
		}
		else
		{
			Node* temp = tail_;
			tail_ = back;
			back -> prev = temp;
			temp -> next = back;
			back -> next = nullptr;
		}
		size_++;
		return true;
}

bool DoublyLinkedList::remove_back()
{	//check if  you have to even use delete
	if (size_ == 0)
		return false;
	if (size_ == 1)
	{
		delete tail_;
		head_ = nullptr;
		tail_ = nullptr;
	}
	else
	{
		Node* temp = tail_ -> prev;
		delete tail_;
		temp -> next = nullptr;
		tail_ = temp;
	}
	size_--;
	return true;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if  (full() || index > size_)
		return false;
	if(index == 0)
		insert_front(value);
	else if (index == size_)
		insert_back(value);
	else
	{
		Node* to_change = head_;
		for(unsigned int i = 0; i < index; i++)
		{
			to_change = to_change -> next;
		}
		Node* insert = new Node(value);
		insert -> prev = to_change -> prev;
		insert -> next = to_change;
		to_change -> prev -> next = insert;
		to_change -> prev = insert;
	}
	size_++;
	return true;
}
bool DoublyLinkedList::remove(unsigned int index)
{
	if (size_ <= 0 || index >= size_)
		return false;
	if(index == 0)
		remove_front();
	else if (index == size_)
		remove_back();
	Node* to_remove = head_;
	for(unsigned int i = 0; i < index; i++)
	{
		to_remove = to_remove -> next;
	}
	to_remove -> next -> prev = to_remove -> prev;
	to_remove -> prev -> next = to_remove -> next;
	size_--;
	delete to_remove;
	return true;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if (empty())
		return size_;
	int index = 0;
	Node* search = head_;
	for (unsigned int i = 0; i < size_; i++)
	{//start from beginning of the list
		if (search -> value == value)
			return index;
		search = search -> next;
		index ++;
	}
	return size_; // return size if it fails.
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{//what to do if there is nothing in the list and index is -12010 or something
	if (index < 0 || index >= size_)
	{
		if(empty())
			return size_;
		return tail_ -> value; //last value of the list
	}
	Node* select = head_;
	for (unsigned int i = 0; i < index; i++)
	{//start from beginning of the list
		select = select -> next;
	}
	return (select -> value);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if (index < 0 || index >= size_)
		return false;
	Node* select = head_;
	for (unsigned int i = 0; i < index; i++)
	{//start from beginning of the list
		select = select -> next;
	}
	select -> value = value;
	return true;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	if (index < 0 || index >= size_)
			return NULL;
		Node* get_N = head_;
		for (unsigned int i = 0; i < index; i++)
		{//start from beginning of the list
			get_N = get_N -> next;
		}
		return get_N;
}
bool DoublyLinkedList::full() const
{
	return (size_ == CAPACITY);
}
