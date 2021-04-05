#pragma once

#include <cstddef>

#include "Heap/Heap.h"

template <typename T>
class HeapMedian
{
    public:
        HeapMedian(std::initializer_list<T> list);
        explicit HeapMedian(size_t capacity);

        void Insert(T&& value) noexcept;
        T GetMedian();

    private:
        void CalculateMedian();

        MaxHeap<T> left_heap;
        MinHeap<T> right_heap;
        T m_current_median = 0;
};
