#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "HeapMedian/HeapMedian.h"
#include "Heap/Heap.h"

using namespace std::chrono;

int main()
{
    srand (time(NULL));

    size_t input_size = 1000000;
    HeapMedian<int> median(input_size);

    std::vector<int> temp;
    for (size_t i = 0; i < input_size; i++)
    {
        auto random_number = rand()%input_size;
        temp.emplace_back(random_number);
    }

    {
        auto start = high_resolution_clock::now();
        std::vector<int> v;
        for (auto val: temp)
        {
            v.push_back(val);
        }

        //For some reason this algorithm doesn't return the write median when the input is even size
        //But it's pretty fast have to look it up suffers from recalculation
        //std::nth_element();
        std::sort(v.begin(), v.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        std::cout << "std::sort: "<< duration.count() << " ms" << std::endl;
    }

    {
        auto start = high_resolution_clock::now();
        for (auto val: temp)
        {
            median.Insert(std::forward<int>(val));
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        std::cout << "my implementation: " << duration.count() << " ms" << std::endl;
    }
}

