#include <gtest/gtest.h>
#include <numeric>
#include <iostream>
#include "algoexpertcpp.hpp"

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