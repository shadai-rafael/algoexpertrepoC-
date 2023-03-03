#ifndef ALGOEXPERT_CPP
#define ALGOEXPERT_CPP
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>

/* Array Challenges*/
std::vector<int> twoNumberSum(std::vector<int> array, int targetSum);
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence);

/* Recursion Challenges */
int getNthFib(int n);
std::vector<std::vector<int>> noneRecursivePowerset(std::vector<int> array);
std::vector<std::vector<int>> powerset(std::vector<int> array);

#endif /*ALGOEXPERT_CPP*/