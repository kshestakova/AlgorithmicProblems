#include <iostream>
#include <vector>
#include <stdlib.h>

int MAX = 10;
int SIZE = 20;

void product(std::vector<int>& v, std::vector<long long>& products)
{
    long long prod = 1;
    int zeros = 0;
    for(const auto& el : v)
    {
        
        if(el) prod *= el;
        else zeros++; 
    }

    if(zeros <= 1) 
    {
        for(int i = 0; i < SIZE; ++i)
        {
            if(v[i]) products[i] = v[i] ? prod / v[i] : prod;
        }
    }
}

int main()
{
    std::vector<int> v;
    for(int i = 0; i < SIZE; ++i)
    {
        v.emplace_back(rand() % MAX);
    }

    for(const auto& el : v)
    {
        std::cout << el << "\t";
    }

    std::cout << "\n";

    std::vector<long long> products(SIZE, 0);
    product(v, products);

    for(const auto& p : products)
    {
        std::cout << p << "\t";
    }
}