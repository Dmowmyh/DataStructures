#pragma once

#include <cstddef>

#include "Heap/Heap.hpp"

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

        Heap<T> left_heap;
        Heap<T> right_heap;
        T m_current_median = 0;
};
