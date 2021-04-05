#pragma once
#include <memory>
#include <iostream>

template <typename T>
class Heap
{
public:
    Heap(size_t capacity);

    ~Heap()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    virtual void FixHeap(size_t nodeIdx) = 0;
    virtual void Heapify(size_t nodeIdx) = 0;

    void Insert(T&& value) noexcept;

    T PopRoot();

    inline T& RootRef() { return m_data[0]; }
    inline T RootVal() const { return m_data[0]; }
    inline bool Empty() const { return m_size == 0; }
    inline size_t Size() const { return m_size; }
    inline size_t Left(size_t i) const { return (2*i+1); }
    inline size_t Right(size_t i) const { return (2*i+2); }
    inline size_t Parent(size_t i) const { return (i-1)/2; };

protected:
    T* m_data = nullptr;
    size_t m_capacity = 0;
    size_t m_size = 0;

};

template <typename T>
class MinHeap: public Heap<T>
{
public:
    MinHeap(size_t capacity);
private:
    void FixHeap(size_t nodeIdx) override final;

    void Heapify(size_t nodeIdx) override final;

    using Heap<T>::m_data;
    using Heap<T>::m_size;
    using Heap<T>::Parent;
    using Heap<T>::Left;
    using Heap<T>::Right;
};

template <typename T>
class MaxHeap: public Heap<T>
{
public:
    MaxHeap(size_t capacity);
private:
    void FixHeap(size_t nodeIdx) override final;
    void Heapify(size_t nodeIdx) override final;

    using Heap<T>::m_data;
    using Heap<T>::m_size;
    using Heap<T>::Parent;
    using Heap<T>::Left;
    using Heap<T>::Right;
};

