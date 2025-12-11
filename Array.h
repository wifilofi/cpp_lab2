//
// Created by gfn on 12/11/2025.
//

#ifndef CPP_LAB2_ARRAY_H
#define CPP_LAB2_ARRAY_H

#pragma once

#include <cstdlib>
#include <iostream>
#include <utility>

template<typename T>
class Array final
{
private:
    int capacity_ = 8;
    int size_ = 0;
    T *data_ = nullptr;

    void constructAt(int index, const T &&value)
    {
    }

    void constructAt(int index, const T &value)
    {
    }

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
    Array()
    {
        data_ = static_cast<T *>(std::malloc(sizeof(T) * capacity_));
    }

    Array(int initCapacity)
        : capacity_(initCapacity)
    {
        if (capacity_ < 1)
        {
            capacity_ = 1;
        }

        data_ = static_cast<T *>(std::malloc(sizeof(T) * capacity_));
    }

    Array(const Array &other)
    {
        data_ = static_cast<T *>(std::malloc(sizeof(T) * capacity_));

        for (int i = 0; i < size_; i++)
        {
            constructAt(i, other.data_[i]);
        }
    }

    Array(Array &&other) noexcept
        : capacity_(std::exchange(other.capacity_, 0)),
          size_(std::exchange(other.size_, 0)),
          data_(std::exchange(other.data_, nullptr))
    {
    }

    ~Array()
    {
        if (data_ != nullptr)
        {
            for (int i = 0; i < size_; i++)
            {
                data_[i].~T();
            }
            std::free(data_);
        }
    }

    void swap(Array &first, Array &second) noexcept
    {
        std::swap(first.capacity_, second.capacity_);
        std::swap(first.size_, second.size_);
        std::swap(first.data_, second.data_);
    }

    const T &operator[](int index) const
    {
        return data_[index];
    }

    T &operator[](int index)
    {
        return data_[index];
    }

    int size() const
    {
        return size_;
    }

    int capacity() const
    {
        return capacity_;
    }

    // inset at end
    int insert(const T &value)
    {
        if (size_ >= capacity_)
        {
            reallocate_();
        }

        constructAt(size_, value);
        size_++;
        return size_ - 1;
    }

    // insert by index
    int insert(int index, const T& value)
    {
        if (index < 0 || index > size_) index = size_;

        if (size_ >= capacity_)
        {
            reallocate_();
        }

        for(int i = size_; i > index; i--)
        {
            constructAt(i, std::move(data_[i-1]));
            data_[i-1].~T();
        }

        constructAt(index, value);
        size_++;
        return index;
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
