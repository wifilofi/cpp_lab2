//
// Created by gfn on 12/11/2025.
//

#ifndef CPP_LAB2_ARRAY_H
#define CPP_LAB2_ARRAY_H

template<typename T>
class Array
{
private:
    int capacity_ = 8;
    int size_ = 0;
    T* data_ = nullptr;

    void reallocate_(int new_capacity)
    {

    }

    void shift_right_(int from, int count = 1)
    {

    }

    void shift_left_(int from, int count = 1)
    {
        
    }

public:
    int size() const { return size_; }
    int capacity() const { return capacity_; }

    // inset at end
    int insert(const T &value)
    {
    }

    // insert by index
    int insert(int index, const T &value)
    {
    }

    // remove by index
    void remove(int index)
    {
    }

    class Iterator
    {
    };

    class ConstIterator
    {
    };

    Iterator iterator() { return Iterator(*this, 0); }
    ConstIterator const_iterator() { return ConstIterator(*this, 0); }

    Iterator reverseIterator() { return Iterator(*this, -1); }
    ConstIterator reverseIterator() const { return ConstIterator(*this, -1); }

};


#endif //CPP_LAB2_ARRAY_H
