#include "algoexpertcpp.hpp"


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