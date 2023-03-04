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
#include <iostream>
#include "algoexpertcpp.hpp"

TEST(recursion_callenges, Fibonacci_Sequence) {
    EXPECT_EQ(0, getNthFib(1));
    EXPECT_EQ(1, getNthFib(2));
    EXPECT_EQ(1, getNthFib(3));
    EXPECT_EQ(2, getNthFib(4));
    EXPECT_EQ(3, getNthFib(5));
    EXPECT_EQ(4181, getNthFib(20));
}

TEST(recursion_callenges, Product_Sum){
    std::vector<std::any> array{-13,8};
    std::vector<std::any> array1{6,array,4};
    std::vector<std::any> array2{7,-1};
    std::vector<std::any> array3{5,2,array2,3,array1};
    EXPECT_EQ(12, productSum(array3));
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