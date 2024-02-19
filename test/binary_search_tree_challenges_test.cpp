/*MIT License
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
#include <gmock/gmock.h>
#include "algoexpertcpp.hpp"

TEST(bst_callenges, Find_Closest_Value_In_BST) 
{
    BST root(10);

    BST l11(5);
    BST l21(2);
    BST l22(5);
    BST l31(1);

    root.left = &l11;
    l11.left = &l21;
    l11.right = &l22;
    l21.left = &l31;

    BST l12(15);
    BST l23(13);
    BST l24(22);
    BST l36(14);

    root.right = &l12;
    l12.left = &l23;
    l12.right = &l24;
    l24.left = &l36;

    int closest_value = findClosestValueInBst(&root, 12);
    EXPECT_TRUE(closest_value == 13);

}