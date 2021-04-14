#pragma once
#include <iostream>
#include <algorithm>
#include "Heap.h"

template <typename T>
typename Heap<T>::Predicate Heap<T>::MinPredicate = [](const T& lhs, const T& rhs, bool traverseDirection)
{
    if (traverseDirection)
        return lhs < rhs;
    else
        return lhs > rhs;
};

template <typename T>
typename Heap<T>::Predicate Heap<T>::MaxPredicate = [](const T& lhs, const T& rhs, bool traverseDirection)
{
    if (traverseDirection)
        return lhs > rhs;
    else
        return lhs < rhs;
};

template <typename T>
Heap<T>::Heap(size_t capacity, Heap::Predicate pred): m_data(std::vector<T>()), m_capacity(capacity),
    m_predicate(pred)
{
    m_data.reserve(m_capacity);
}

template <typename T>
void Heap<T>::Insert(T&& value) noexcept
{
    if (Size() != m_capacity)
    {
        m_data.emplace_back(std::forward<T>(value));
        size_t i = Size()-1;
        FixHeap(i);
    }
}

template <typename T>
auto Heap<T>::PopRoot() -> T
{
    if (Size() <= 0)
    {
        return 0;
        //return INVALID NUMBER;
    }
    if (Size() == 1)
    {
        auto root = m_data.front();
        m_data.pop_back();
        return root;
    }

    int root = m_data[0];
    m_data[0] = m_data[Size()-1];
    m_data.pop_back();
    Heapify(0);

    return root;
}

template <typename T>
void Heap<T>::FixHeap(size_t nodeIdx)
{
    while(nodeIdx != 0 && m_predicate(m_data[Parent(nodeIdx)], m_data[nodeIdx], false))
    {
        std::swap(m_data[nodeIdx], m_data[Parent(nodeIdx)]);
        nodeIdx = Parent(nodeIdx);
    }
}

template <typename T>
void Heap<T>::Heapify(size_t nodeIdx)
{
    size_t left = Left(nodeIdx);
    size_t right = Right(nodeIdx);
    size_t valueToChange = nodeIdx;

    if (left < Size() && m_predicate(m_data[left], m_data[nodeIdx], true))
    {
        valueToChange = left;
    }
    if (right < Size() && m_predicate(m_data[right], m_data[valueToChange], true))
    {
        valueToChange = right;
    }
    if (valueToChange != nodeIdx)
    {
        std::swap(m_data[nodeIdx], m_data[valueToChange]);
        Heapify(valueToChange);
    }
}
