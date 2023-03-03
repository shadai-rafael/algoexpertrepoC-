#include <gtest/gtest.h>
#include <numeric>
#include "algoexpertcpp.hpp"


TEST(array_callenges, Two_Number_Sum) {
    std::vector<int> array {3,5,-4,8,11,1,-1,6};
    int targetSum = 10;
    std::vector<int> result = twoNumberSum(array, targetSum);
    auto sum = [](int num1, int num2){return num1 + num2;};
    EXPECT_EQ(targetSum, std::accumulate(result.begin(), result.end(), 0, sum));
}

TEST(array_callenges, Validate_Subsequence) {
    std::vector<int> array{5,1,22,25,6,-1,8,10};
    std::vector<int> sequence{1,6,-1,10};
    EXPECT_TRUE(isValidSubsequence(array, sequence));
}