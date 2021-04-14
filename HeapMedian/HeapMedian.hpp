#pragma once
#include "HeapMedian.h"
#include <cmath>

template <typename T>
HeapMedian<T>::HeapMedian(std::initializer_list<T> list)
    : left_heap(list.size(), Heap<T>::MaxPredicate), right_heap(list.size(), Heap<T>::MinPredicate)
{
    for (auto item: list)
    {
        Insert(std::forward<T>(item));
    }
}

template <typename T>
HeapMedian<T>::HeapMedian(size_t capacity) : left_heap(capacity, Heap<T>::MaxPredicate)
                                           , right_heap(capacity, Heap<T>::MinPredicate)
{

}

template <typename T>
void HeapMedian<T>::Insert(T&& value) noexcept
{
    if (!left_heap.Empty() && !right_heap.Empty())
    {
        if (value < m_current_median)
        {
            left_heap.Insert(std::forward<T>(value));
        }
        else if (value >= m_current_median)
        {
            right_heap.Insert(std::forward<T>(value));
        }
        if (left_heap.Size() > right_heap.Size()
                && (left_heap.Size() - right_heap.Size() > 1))
        {
            T rootValue = left_heap.PopRoot();
            right_heap.Insert(std::forward<T>(rootValue));
        }
        else if (right_heap.Size() > left_heap.Size()
                && (right_heap.Size() - left_heap.Size() > 1))
        {
            T rootValue = right_heap.PopRoot();
            left_heap.Insert(std::forward<T>(rootValue));
        }
    }
    else
    {
        //First two numbers add to left and right heap respectivly
        if (left_heap.Empty())
        {
            left_heap.Insert(std::forward<T>(value));
        }
        else if(right_heap.Empty())
        {
            right_heap.Insert(std::forward<T>(value));
        }
        if (!left_heap.Empty() && !right_heap.Empty())
        {
            if(left_heap.RootVal() > right_heap.RootVal())
            {
                std::swap(right_heap.RootRef(), left_heap.RootRef());
            }
        }
    }
    CalculateMedian();

}

template <typename T>
void HeapMedian<T>::CalculateMedian()
{
    if (left_heap.Size() == right_heap.Size())
    {
        m_current_median =
            (right_heap.RootVal() + left_heap.RootVal()) / 2.0;
    }
    else if (left_heap.Size() > right_heap.Size())
    {
        m_current_median = left_heap.RootVal();
    }
    else
    {
        m_current_median = right_heap.RootVal();
    }
}

template <typename T>
T HeapMedian<T>::GetMedian()
{
    return m_current_median;
}
