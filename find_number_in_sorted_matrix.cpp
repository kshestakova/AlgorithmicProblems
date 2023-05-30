/*
You are given a matrix of integers.
Every row and every column of them are sorted.
You need to find a number N in this matrix.
Return true if N is here and false otherwise.
*/

#include <iostream>

const int a = 5;
const int b = 6;
const int matrix[a][b] =
    {
        {1, 3,  5,  8,  11, 13},
        {2, 4,  7,  10, 17, 19},
        {4, 7,  9,  15, 18, 23},
        {5, 11, 14, 18, 22, 24},
        {7, 15, 16, 20, 25, 29}
    };

// Dumb approach: just check all the values in the matrix
// complexity: O(n*n)
bool simpleFind(const int N)
{
    for(int i = 0; i < a; ++i)
    {
        for(int j = 0; j < b; ++j)
        {
            if(matrix[i][j] == N) return true;
        }
    }
    return false;
}

// More promised approach:
// we know that rows are sorted,
// that's why we could use binary serch for each of it
// complexity: O(n * log n)
bool quickerFind(const int N)
{
    for(int i = 0; i < a; ++i)
    {
        int l = 0, r = b-1;
        while(l <= r)
        {
            int current = l + (r - l) / 2;
            if(matrix[i][current] == N) return true;
            if(matrix[i][current] > N) r = current - 1;
            else l = current + 1;
        }
    }
    return false;
}

// The fastest approach:
// we know that both rows and columns are sorted
// we start checking from the upper right corner
// if current value is equal to N, we return true and stop
// if it is smaller then N, we don't need to check upper values and go down
// if it is bigger, then we don't need values from the right side and go left
// complexity: O(a + b) ~ O(n)
bool smartFind(const int N)
{
    int i = 0, j = b-1;
    while(i < a && j >= 0)
    {
        if(matrix[i][j] == N) return true;
        if(matrix[i][j] < N) i++;
        else j--;
    }

    return false;
}

int main()
{  
    const int N = 14;
    
    std::cout << simpleFind(N) << std::endl;
    std::cout << quickerFind(N) << std::endl;
    std::cout << smartFind(N) << std::endl;
}