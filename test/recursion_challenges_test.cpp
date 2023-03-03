#include <gtest/gtest.h>
#include <numeric>
#include <iostream>
#include "algoexpertcpp.hpp"



TEST(recursion_callenges, fibonacci_sequence) {
    EXPECT_EQ(0, getNthFib(1));
    EXPECT_EQ(1, getNthFib(2));
    EXPECT_EQ(1, getNthFib(3));
    EXPECT_EQ(2, getNthFib(4));
    EXPECT_EQ(3, getNthFib(5));
    EXPECT_EQ(4181, getNthFib(20));
}

TEST(recursion_callenges, powerset) {
    std::vector<int> array{1,2};
    std::vector<std::vector<int>> expected{{},{1},{2},{1,2}};
    std::vector<std::vector<int>> result = powerset(array);
    EXPECT_EQ(expected.size(), result.size());
    for (int i = 0; i < expected.size(); i++)
    {
        for(int j = 0; j < expected[i].size();j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }    
}