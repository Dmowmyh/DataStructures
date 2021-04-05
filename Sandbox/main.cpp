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
    //srand (time(NULL));

    //size_t input_size = 1000000;
    //HeapMedian<int> median(input_size);

    //std::vector<int> temp;
    //for (size_t i = 0; i < input_size; i++)
    //{
        //auto random_number = rand()%input_size;
        //temp.emplace_back(random_number);
    //}

    //{
        //auto start = high_resolution_clock::now();
        //std::vector<int> v;
        //for (auto val: temp)
        //{
            //v.push_back(val);
        //}
        //std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        //auto stop = high_resolution_clock::now();
        //auto duration = duration_cast<milliseconds>(stop - start);
        //std::cout << duration.count() << std::endl;
    //}

    //{
        //auto start = high_resolution_clock::now();
        //for (auto val: temp)
        //{
            //median.Insert(std::forward<int>(val));
        //}
        //auto stop = high_resolution_clock::now();
        //auto duration = duration_cast<milliseconds>(stop - start);
        //std::cout << duration.count() << std::endl;
    //}

    //HeapMedian<float> medianFloats({1.1, 2.5, 3.5, 3.3, 10.1});
    //std::cout << medianFloats.GetMedian() << std::endl;
}

