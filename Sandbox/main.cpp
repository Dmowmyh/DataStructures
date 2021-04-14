#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "HeapMedian/HeapMedian.h"
#include "Heap/Heap.h"
#include "CacheLRU/Cache.h"

using namespace std::chrono;

int main()
{
    Cache cache(5);
    cache.Get("Request_1", "Response_1");
    cache.Get("Request_2", "Response_2");
    cache.Get("Request_3", "Response_3");
    cache.Get("Request_4", "Response_4");

    cache.Print();
}

