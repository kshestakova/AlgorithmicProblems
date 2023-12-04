#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>

int SIZE = 10000;
int MAX = 1000;

void quickSort(std::vector<int>& v)
{
    if(v.size() < 1) return;
    std::vector<int> left, right, middle;
    int m = v[v.size()/2];
    for(const auto& t : v)
    {
        if(t < m) left.emplace_back(t);
        else if(t == m) middle.emplace_back(t);
        else right.emplace_back(t);
    }
    v.clear();
    quickSort(left);
    quickSort(right);
    v.insert(v.begin(), left.begin(), left.end());
    v.insert(v.end(), middle.begin(), middle.end());
    v.insert(v.end(), right.begin(), right.end());
}


int main()
{
    std::vector<int> v;
    for(int i = 0; i < SIZE; ++i) v.emplace_back(rand() % MAX);
    for(const auto& t : v) std::cout << t << "\t";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    
    for(const auto& t : v) std::cout << t << "\t";
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTime taken by quickSort: " << duration.count() << " microseconds" << std::endl;


    return 0;
}