/*
You have a vector with temperature values of some days of the month. 

Your task is to find amount of days in which temperature is higher
for every day (for the last one it is 0).

For example, if you have values 
10  12  13  11  10  7   19  4
then your result will be
1   1   4   3   2   1   0   0

Try to solve it with O(n) complexity, not with O(n*n)
*/

#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::vector<int> temperatures = {10, 12, 13, 11, 10, 7, 19, 4};
    int n = temperatures.size();
    std::vector<int> result (n, 0);

    // stack for temperature values, which are higher then values from their right sights 
    std::stack<std::pair<int, int>> highT;
    highT.push(std::make_pair(temperatures[n-1], n-1));

    for(int i = n-2; i >= 0; --i)
    {
        if(!highT.empty())
        {
            // if on the top of the stack we have an element with higher temperature,
            // it is the closest element which meets our rules
            if(highT.top().first > temperatures[i])
            {
                // result for this day - difference between its number and current
                result[i] = highT.top().second - i;
                // also we should push current value and its number in stack 
                highT.push(std::make_pair(temperatures[i], i));
            }
            else
            {
                // in other case we should pop element from stack and check again
                // we could use 'while' here (but I don't want to)
                highT.pop();
                i++;
            }
        }
        else
        {
            // if stack is empty, we push current value and its number there
            highT.push(std::make_pair(temperatures[i], i));
        }
    }

    for(const auto& r : result)
    {
        std::cout << r << std::endl;
    }
    
}