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
#include "algoexpertcpp.hpp"
#include <cmath>

/*Find Closest Value In BST
*Write a function that takes in a Binary Search Tree (BST) and a target integer
*value contained in the BST.
*You can assume that there will only be one closest value.
*Each BST node has an integer value, a left child node, and a right child node.
*A node is said to be valid BST node if and only if it satisfies the BST property:
*its value is strictly greater than the values of every node to its left; its value is
*less than or equal to the values of every node to its right; and its children nodes 
*are either valid BST nodes themselves or None/null
*/
int findClosestValueInBst(BST<int>* tree, int target) {
    int closest_value = tree->value;
    int value_candidate = tree->value;
    if(tree->left == nullptr && tree->right == nullptr)
    {
        return closest_value;
    }
    
    if(tree->left == nullptr){
        value_candidate = findClosestValueInBst(tree->right, target);
    }else if(tree->right == nullptr){
        value_candidate = findClosestValueInBst(tree->left, target);
    }else{
        if(abs(tree->left->value - target) > abs(tree->right->value - target)){
            value_candidate = findClosestValueInBst(tree->right, target);
        }else{
            value_candidate = findClosestValueInBst(tree->left, target);
        }
    }

    if(abs(value_candidate - target) < abs(closest_value - target))
    {
        closest_value = value_candidate;
    }

    return closest_value;
}