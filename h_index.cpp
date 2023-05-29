/*
Your friend is a scientist. They wrote a lot of scientific articles.
You are given an array with citation indexes for every their article.
For example, if an article was cited three times by other scientists, 
its citation index is 3.

Your task is to find H-index (Hirsch index). 
The h-index is defined as the maximum value of h 
such that the given author/journal has published at least h papers 
that have each been cited at least h times.
*/

#include <iostream>
#include <algorithm>


// Simple dumb solution: 
// count how much articles were cited at least i times
// then return maximum possible value (when i articles were cited i times) 
// complexity: O(n*n)

int simpleApproach(const int* array, const int size)
{
    for(int i = 1; i <= size; ++i)
    {
        int count = 0;
        for(int j = 0; j < size; ++j)
        {
            if(array[j] >= i) count++;
        }
        if(count < i) return i-1;
    }
    return 0;
}

// More promised way: 
// sort array by std::sort with log(n) complexity,
// then check values until the condition 
// "i articles with at least i citation"
// is no longer met 
// complexity: O(n*log n)

int sortApproach(const int* array, const int size)
{
    // for sort we should create s copy because array is const
    int arrayCopy[size];
    std::copy(array, array+size, arrayCopy); 
    std::sort(arrayCopy, arrayCopy+size);

    for(int i = 1; i <= size; ++i)
    {
        if(i < arrayCopy[i-1]) return i-1;
    }
    return 0;
}

// Smartest way
// we create an additional array to make sort by counting.
// we count how many times value is presented in the array
// and then 'recover' a sorted array by inserting values counted times.
// it is ok for arrays consisted of values in not too big interval - for example, from 0 to their size.
// h-index couldn't be bigger then size, 
// that's why we could use size value for bigger citation indexes.
// size + 1 - because citation could be from 0 to size.
// then we just check values as in previous example
// complexity: O(n)

int smartApproach(const int* array, const int size)
{
    int tempArray[size + 1] = {0};

    for(int i = 0; i < size; ++i)
    {
        if(array[i] >= size) tempArray[size]++;
        else tempArray[array[i]]++;
    }

    int sortedArray[size] = {0};
    int pos = 0;

    for(int i = 0; i < size+1; ++i)
    {
        for(int j = 0; j < tempArray[i]; ++j)
        {
            sortedArray[pos] = i;
            pos++;
        }
    }

    for(int i = 1; i <= size; ++i)
    {
        if(i < sortedArray[i-1]) return i-1;
    }

    return 0;
}

int main()
{
    int citations[] = {3, 0, 4, 1, 7, 8, 11};
    int n = 7;

    std::cout << simpleApproach(citations, n) << std::endl;
    std::cout << sortApproach(citations, n) << std::endl;
    std::cout << smartApproach(citations, n) << std::endl;
}