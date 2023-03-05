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

/*Fibonacci sequence
 * The Fibonacci sequence is defined as follows: The first number of the sequence is 0,
 * the second number is 1, and the nth number is the sum of the nth(nth-1) and nth(nth-2)
 * numbers. Write a function that takes the integer n and returns the nth Fibonacci number
 */

int calculateNthFib(int n, std::map<int, int> fibMap){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    auto fibIt = fibMap.find(n);
    if(fibIt != fibMap.end()){
        return fibIt->second;
    }else{
        return calculateNthFib(n-1,fibMap)+calculateNthFib(n-2,fibMap);
    }
}

int getNthFib(int n) {
    std::map<int, int> map;
    return calculateNthFib(n,map);
}

/*Product Sum
 *Write a function that takes in a "special" and returns its product sum.
 *A special array is a non-empty array that contain either integers or other special
 *arrays. The product sum of a "special" array is the sum of its elements, where "special"
 *arrays inside it are summed themselves and multiplied it by their level of depth.
 *The depth of a "special" array is how far nested it is. For instance the depth of []
 *is 1; the depth of the inner array [[]] is 2; the depth of the innermost array in [[[]]] is
 *3.
 */

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)

int productSumHelper(std::vector<std::any> array, int level){
    int sum = 0;
    
    for(auto& element: array){
        if(element.type() == typeid(int)){
            sum += static_cast<int>(std::any_cast<int>(element));
        }else if(element.type()==typeid(std::vector<std::any>)){
            sum += productSumHelper(static_cast<std::vector<std::any>>(
                    std::any_cast<std::vector<std::any>>(element)),level+1);
        }else{
            return 0;
        }
    }
    return level*sum;
}

int productSum(std::vector<std::any> array) {
  return productSumHelper(array,1);
}

/*Permutation
 *Write a function that takes in an array of unique integers and returns an array
 *of all permutations of those integers in no particular order.
 */

std::vector<std::vector<int>> getPermutations(std::vector<int> array) {
    std::vector<std::vector<int>> result{};
    if (array.size() == 0){
        return result;
    }else if(array.size() == 1){
        result.push_back(array);
        return result;
    }

    for (auto i= array.begin(); i != array.end() ; i++)
    {        
        auto holder = *i;
        array.erase(i);
        auto tempResult = getPermutations(array);
        for(auto el: tempResult){
            el.insert(el.begin(), holder);
            result.insert(result.begin(), el);
        }
        array.insert(i,holder);
    }
    
    return result;
}

/*Powerset
*Write a function that takes in an array of unique integers and returns its powerset.
*The powerset P(X) of a set X is the set of all the subsets of X. For example the powerset
*of [1,2] is [], [1], [2], [1,2]
*/
std::vector<std::vector<int>> noneRecursivePowerset(std::vector<int> array) {
    std::vector<std::vector<int>> powerset{{}};
    int size_powerset = powerset.size();
    for (size_t i = 0; i < static_cast<size_t>(array.size()); i++)
    {
        for (size_t j = 0; j < size_powerset ; j++)
        {
            std::vector<int>temp(powerset[j]);
            temp.emplace_back(array[i]);
            powerset.emplace_back(temp);
        }
        size_powerset = powerset.size();
    }
    
    return powerset;
}

std::vector<std::vector<int>> powerset(std::vector<int> array) {
    if(array.empty()){        
        return std::vector<std::vector<int>>{{}};
    }
    int tempElement = array.back();
    array.pop_back();
    std::vector<std::vector<int>> result = powerset(array);
    auto lastSize = result.size();
    for(int i = 0; i < lastSize ;i++)
    {
        std::vector<int> vect(result[i]);
        vect.emplace_back(tempElement);
        result.emplace_back(vect);
    }
    return result;
}