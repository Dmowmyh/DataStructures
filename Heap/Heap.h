#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
class Heap
{
public:
    //TODO Fix remove traverse direction flag
    using Predicate = std::function<bool(const T& lhs, const T& rhs, bool traverseDirection)>;
    static Predicate MinPredicate;
    static Predicate MaxPredicate;

    Heap(size_t capacity, Predicate pred = MinPredicate);

    void FixHeap(size_t nodeIdx);
    void Heapify(size_t nodeIdx);

    void Insert(T&& value) noexcept;

    T PopRoot();

    inline T& RootRef() { return m_data[0]; }
    inline T RootVal() const { return m_data[0]; }
    inline bool Empty() const { return m_data.empty(); }
    inline size_t Size() const { return m_data.size(); }
    inline size_t Left(size_t i) const { return (2*i+1); }
    inline size_t Right(size_t i) const { return (2*i+2); }
    inline size_t Parent(size_t i) const { return (i-1)/2; };

protected:
    std::vector<T> m_data = {};
    size_t m_capacity = 0;
    Predicate m_predicate;

};
