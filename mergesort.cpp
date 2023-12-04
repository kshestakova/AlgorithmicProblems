#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>

int SIZE = 10000;
int MAX = 1000;

void merge(std::vector<int>& v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = v[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = v[mid + 1 + j];
    }

    int i = 0; 
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);

        merge(v, left, mid, right);
    }
}

int main() {

    std::vector<int> v;
    for(int i = 0; i < SIZE; ++i) v.emplace_back(rand() % MAX);

    int vn = v.size();

    for(const auto& t : v) std::cout << t << "\t";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(v, 0, vn - 1);
    auto stop = std::chrono::high_resolution_clock::now();  

    for(const auto& t : v) std::cout << t << "\t";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTime taken by mergeSort: " << duration.count() << " microseconds" << std::endl; 
    return 0;
}