#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "HeapMedian/HeapMedian.h"

TEST_CASE("TC01", "[HashMapValidation]")
{

}

TEST_CASE("TC02", "[HashMedianValidation]")
{
    {
        /** Test edge cases */

        HeapMedian<int> zero = HeapMedian<int>({0});

        REQUIRE(zero.GetMedian() == 0);

        HeapMedian <int> empty = HeapMedian<int>(0);

        REQUIRE(empty.GetMedian() == 0);

        HeapMedian <int> negative = HeapMedian<int>({-1});

        REQUIRE(negative.GetMedian() == -1);

        HeapMedian <int> one_number = HeapMedian<int>({7});

        REQUIRE(one_number.GetMedian() == 7);

        HeapMedian <float> floats = HeapMedian<float>({0.5, 2.5});

        REQUIRE(floats.GetMedian() == 1.5);
    }

    // Test random inputs compared with stl algorithm
    srand (time(NULL));

    for (size_t numOfTests = 0; numOfTests < 10000; numOfTests++)
    {
        size_t input_size = rand()%10000;

        HeapMedian<int> median(input_size);
        std::vector<int> v;

        for (size_t j = 0; j < input_size; j++)
        {
            auto random_number = rand()%input_size;
            median.Insert(random_number);
            v.push_back(random_number);
        }
        //Sort using std algorithm
        std::sort(v.begin(), v.end());

        if (!v.empty())
        {
            if (v.size()%2 == 0)
            {
                REQUIRE((v[v.size()/2]+v[v.size()/2-1])/2 == median.GetMedian());
            }
            else
            {
                REQUIRE(v[v.size()/2] == median.GetMedian());
            }
        }
    }
}
