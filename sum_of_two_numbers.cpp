/*
You are given a sorted array of different integers and one more integer S. 

Your need to find two numbers [a, b] inside the array, for which a + b = S.
If there is no such [a, b] return pair [0, 0]. 
Order in the result doesn't matter. 
*/

#include <iostream>
#include <set>

std::pair<int, int> simpleApproach(const int* array, const int size, const int S)
{
    // complexity: O(n*n)
    // memory: O(1)

    // here we check all possible pairs

    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(array[i] + array[j] == S)
            {
                return std::make_pair(array[i], array[j]);
            }
        }
    }
    return std::make_pair(0, 0);
} 

std::pair<int, int> setApproach(const int* array, const int size, const int S)
{
    // complexity: O(n*log n)
    // memory: O(n)

    // here we check numbers one by one
    // for each checked one we calculate the second possible number in the result 
    // for example for S = 10 and first = 4 second = 6

    // if second number is already in set, we return the result
    // if no, we add current number to set

    // find() for sets takes O(log n), checking every number in the array - O(n)

    std::set<int> numbers;

    for(int i = 0; i < size; ++i)
    {
        int t = S - array[i];
        auto it = numbers.find(t);
        if(it != numbers.end()) 
        {
            return std::make_pair(array[i], *it);
        }
        else
        {
            numbers.emplace(array[i]);
        }
    }
    return std::make_pair(0, 0);
}

int binarySearch(const int* array, const int size, const int x)
{
    int l = 0, r = size - 1;
    while(l <= r)
    {
        int current = (l + r) / 2; 
        if(array[current] == x) return current;
        if(array[current] < x) l = current + 1;
        else r = current - 1;
    }
    return -1; 
}

std::pair<int, int> binarySearchApproach(const int* array, const int size, const int S)
{
    // complexity: O(n*log n)
    // memory: O(1)

    // here we check numbers one by one
    // logic is like in previous one: we calculate potential second number and search it
    // but here we don't use set to avoid additianal memory usage
    // and we use binary search in the initial array

    // binary search complexity is O(log n), checking every number in the array - O(n)

    for(int i = 0; i < size; ++i)
    {
        int t = S - array[i];
        int number = binarySearch(array, size, t);
        if(number != -1 && array[number] != array[i])
        {
            return std::make_pair(array[i], array[number]);
        }
    }
    return std::make_pair(0, 0);
}

std::pair<int, int> smartApproach(const int* array, const int size, const int S)
{
    // complexity: O(n)
    // memory: O(1)

    // here we check numbers one by one
    // but we are going from the both sides of array

    int l = 0, r = size - 1;

    while(l != r)
    {
        int t = array[l] + array[r];
        if(t == S)  return std::make_pair(array[l], array[r]);
        if(t < S)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return std::make_pair(0, 0);
}

int main()
{
    int array[] = {-5, -3, -2, 0, 4, 6, 7, 11, 14, 16};
    int size = 10;

    // sum which can be found
    int S = 8;
    // sum which can't be found
    // int S = 55 

    std::pair<int, int> result{0, 0};

    result = simpleApproach(array, size, S);
    std::cout << result.first << "\t" << result.second << std::endl;

    result = setApproach(array, size, S);
    std::cout << result.first << "\t" << result.second << std::endl;

    result = binarySearchApproach(array, size, S);
    std::cout << result.first << "\t" << result.second << std::endl;

    result = smartApproach(array, size, S);
    std::cout << result.first << "\t" << result.second << std::endl;
}