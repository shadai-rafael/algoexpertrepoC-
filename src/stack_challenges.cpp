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

/*Min Max Stack Construction
*
*Write Minmaxstack for a Min Max Stack. The class should support:
*Pushing and popping values on and off the stack.
*Peeking at the value at the top of the stack.
*Getting both the minimum and the maximum values in the stack at any given point in time.
*All class methods, when considered independently, should run constant time and with
*constant space.
*/

int getMinData(data* inData){
    int minValue = inData->value;
    while (inData)
    {
        if(minValue > inData->value){
            minValue = inData->value;
        }
        inData = inData->next;
    }
    return minValue;
}

int getMaxData(data* inData){
    int maxValue = inData->value;
    while (inData)
    {
        if(maxValue < inData->value){
            maxValue = inData->value;
        }
        inData = inData->next;
    }
    return maxValue;
}

int MinMaxStack::peek()
{
    if (!innerStack.empty())
    {
        return innerStack.top().value;
    }
    
    return -1;
}

int MinMaxStack::pop() {
    
    if (!innerStack.empty())
    {
        if (innerStack.size() > 1){
            if(max == innerStack.top().value){
                max = getMaxData(innerStack.top().next);

            }else if(min == innerStack.top().value){
                min = getMinData(innerStack.top().next);
            }
        }
        auto dataStack = innerStack.top();
        innerStack.pop();
        return dataStack.value;
    }
    return -1;
}

void MinMaxStack::push(int number) {
    data stackData;
    stackData.value = number;
    if (!innerStack.empty())
    {
        stackData.next = &innerStack.top();
        if(max < stackData.value ){
            max = stackData.value;
        }else if(min > stackData.value){
            min = stackData.value;
        }
    }else{
        min = stackData.value;
        max = stackData.value;
    }
    innerStack.push(stackData);
}

int MinMaxStack::getMin() {
    return min;
}

int MinMaxStack::getMax() {
    return max;
}

/*Balanced Brackets
*Write a function that takes in a string made up of brackets (,),{,},[,] and other
*optional characters. The function should return a boolean representing whether the
*string is balanced with regards to brackets.
*A string is said to be balanced if it has as many opening brackets of a certain type
*as it has closing brackets of that type and if no bracket is unmatched. Note that an
*opening bracket can't match a corresponding closing bracket that comes before it, and
*similarly, a closing bracket can't match a corresponding opening bracket that comes
*after it. Also, brackets can't overlap each other as in [(]).
*/
bool balancedBrackets(std::string str) {
    std::stack<char> balancedStack;
    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {       
        if(*it == '(' || *it == '[' || *it == '{'){
            balancedStack.push(*it);
        }else if(*it == ')' || *it == ']' || *it == '}'){
            if(balancedStack.empty()){
                return false;
            }else if (balancedStack.top() == '(' && *it != ')'){
                return false;
            }else if(balancedStack.top() == '[' && *it != ']'){
                return false;
            }else if(balancedStack.top() == '{' && *it != '}'){
                return false;
            }else{
                balancedStack.pop();
            }
        }else{
            continue;
        }        
    }
    if(!balancedStack.empty())
        return false;

    return true;
}