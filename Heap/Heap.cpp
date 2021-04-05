#include <iostream>
#include <algorithm>
#include "Heap.h"

template class MaxHeap<int>;
template class MaxHeap<float>;
template class MinHeap<int>;
template class MinHeap<float>;
template class Heap<int>;
template class Heap<float>;

template <typename T>
Heap<T>::Heap(size_t capacity): m_data(std::vector<T>()), m_capacity(capacity)
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
MinHeap<T>::MinHeap(size_t capacity) : Heap<T>(capacity)
{

}

template <typename T>
void MinHeap<T>::FixHeap(size_t nodeIdx)
{
    while(nodeIdx != 0 && m_data[Parent(nodeIdx)] > m_data[nodeIdx])
    {
        std::swap(m_data[nodeIdx], m_data[Parent(nodeIdx)]);
        nodeIdx = Parent(nodeIdx);
    }
}

template <typename T>
void MinHeap<T>::Heapify(size_t nodeIdx)
{
    size_t left = Left(nodeIdx);
    size_t right = Right(nodeIdx);
    size_t smallest = nodeIdx;

    if (left < Size() && m_data[left] < m_data[nodeIdx])
    {
        smallest = left;
    }
    if (right < Size() && m_data[right] < m_data[smallest])
    {
        smallest = right;
    }
    if (smallest != nodeIdx)
    {
        std::swap(m_data[nodeIdx], m_data[smallest]);
        Heapify(smallest);
    }
}

template <typename T>
MaxHeap<T>::MaxHeap(size_t capacity) : Heap<T>(capacity)
{
}

template <typename T>
void MaxHeap<T>::FixHeap(size_t nodeIdx)
{
    while(nodeIdx != 0 && m_data[Parent(nodeIdx)] < m_data[nodeIdx])
    {
        auto parentIdx = Parent(nodeIdx);
        std::swap(m_data[nodeIdx], m_data[parentIdx]);
        nodeIdx = parentIdx;
    }
}

template <typename T>
void MaxHeap<T>::Heapify(size_t nodeIdx)
{
    size_t left = Left(nodeIdx);
    size_t right = Right(nodeIdx);
    size_t largest = nodeIdx;

    if (left < Size() && m_data[left] > m_data[nodeIdx])
    {
        largest = left;
    }
    if (right < Size() && m_data[right] > m_data[largest])
    {
        largest = right;
    }
    if (largest != nodeIdx)
    {
        std::swap(m_data[nodeIdx], m_data[largest]);
        Heapify(largest);
    }
}
