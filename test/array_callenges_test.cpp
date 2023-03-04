/*
MIT License
Copyright (c) 2023 shadai-rafael
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
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