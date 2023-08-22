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
#include <sstream>
#include <stdlib.h>

#define CHAR_TO_INT(X)  (X - '0')

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

/*Sunset Views
*Given an array of buildings and a direction that all of the buildings face, return an array
*of the indices of the buildings that can see the sunset.
*A building can see the sunset if it is strictly taller than all of the buildings that come
*after it in the direction that it faces.
*The input array named buildngs contains positive, non-zero integers representing the heights
*of the buildings. A building at index i thus has an height denoted by buildings[i]. All of the
*buildings face the same direction, and this direction is either east or west, denoted by the   
*input string named direction, which will always be equal to either "EAST" or "WEST". In relation
*to the input array, you can interpret these directions as right for east and left for west.
*Important note: the indices in the output array should be sorted in ascending order.
*Buildings=[3,5,4,4,3,1,3,2]
*Direction="EAST"
*Output=[1,3,6,7]
*/
std::vector<int> sunsetViews(std::vector<int> buildings, std::string direction) {
    std::vector<int> output;
    int index{0}, step{1}, end{static_cast<int>(buildings.size()-1)};
    
    if (direction.compare("EAST") == 0 && buildings.size() > 0){
        index = buildings.size()-1;
        step = -1;
        end = 0;
    }else if(direction.compare("WEST") != 0 || buildings.size() == 0){
        return output;
    }

    output.push_back(index);

    auto getBuildingIndex= [&output](std::string& direction){
        if(direction.compare("WEST") == 0){
            return output.back();
        }else{
            return output.front();
        }        
    };

    auto toInsert = [&output](int index, std::string& direction){
        if(direction.compare("WEST") == 0){
            output.emplace(output.end(), index);
        }else{
            output.emplace(output.begin(), index);
        }        
    };

    auto isTheEnd = [](int index, int end, std::string& direction){
        if(direction.compare("WEST") == 0){
            return index <= end;
        }else{
            return index >= end;
        }
    };
 
    while(isTheEnd(index, end, direction)) {
        if(buildings[index] > buildings[getBuildingIndex(direction)]){
            toInsert(index, direction);
        }
        index += step;        
    }

    return output;
}

/*Best Digits
*Write a function that takes a positive integer represented as a string number and an
*integer numDigits. Remove numDigits from the string so that the number represented by the 
*string is as large as possible afterwards.
*Note that the order of the remaining digit cannot be changed. You can assume numDigits
*will always be less than the length of number and greater than or equal to zero.
*/
std::string bestDigits(std::string number, int numDigits) {
    int window = numDigits, offset = 0;
    std::ostringstream oss;
    
    auto windowCheck = [](const std::string& number, int window, const int offset){
        int counter = 0, gindex = offset;
        int gNbr = CHAR_TO_INT(number[offset]);
        while ( window > counter  &&  offset + counter + 1 < number.size())
        {
            if (gNbr < CHAR_TO_INT(number[counter + offset + 1])){
                gNbr = CHAR_TO_INT(number[counter + offset + 1]);
                gindex = counter + offset + 1;
            }
            counter++;
        }
        return gindex;
    };

    while (offset < number.size())
    {        
        int prevOffset = offset;
        offset = windowCheck(number, window, offset);
        window = window - (offset - prevOffset);
        if(! ((number.size() - oss.str().size()) <= window && window !=0))
            oss << number[offset];
        offset++;
    }
    return oss.str();
}