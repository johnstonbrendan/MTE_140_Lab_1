// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"
#include <iostream>

using namespace std;
// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];
    size_ = 0;
    capacity_ = cap;
}

SequentialList::~SequentialList()
{
    delete[] data_;
}

bool SequentialList::empty() const
{
    return size_ == 0;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::full() const
{
    return capacity_ == size_;
}

void SequentialList::print() const
{
    cout << "[";
    for(int i = 0; i < size_; i++)
    {
        cout << data_[i];
        if(i != size_-1)
            cout << ",";
    }
    cout << "]\n";
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
    return insert(val, 0);
}

bool SequentialList::remove_front()
{
    return remove(0);
}

bool SequentialList::insert_back(DataType val)
{
    return insert(val, size_);
}

bool SequentialList::remove_back()
{
    return remove(size_-1);
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if(size_ >= capacity_ || index > size_)
        return false;
    DataType temp;

    for(int i = index; i <= size_; i++)
    {
        DataType temp = data_[i];
        data_[i] = val;
        val = temp;
    }
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
    if(index >= size_)
        return false;
    for(int i = index; i < size_-1; i++)
    {
        data_[i] = data_[i+1];
    }
    size_--;
    return true;
}

unsigned int SequentialList::search(DataType val) const
{
    for(int i = 0; i < size_; i++)
    {
        if(data_[i] == val)
            return i;
    }
    return size_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if(index >= size_)
        return data_[size_-1];
    return data_[index];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index < size_)
        return false;
    data_[index] = val;
    return true;
}
