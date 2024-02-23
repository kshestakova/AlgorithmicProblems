#include <iostream>
#include <random>

const int ARRAY_SIZE = 100;

int main()
{
    // data preparation
    int arr[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) arr[i] = i;

    for(int i = ARRAY_SIZE - 1; i > 1; --i)
    {
        int t = std::rand() % i;
        std::swap(arr[t], arr[i]);
    }

    for(int i = 0; i < ARRAY_SIZE; i++) std::cout << arr[i] << "\t";

}