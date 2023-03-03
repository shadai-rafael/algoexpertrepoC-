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