#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> quickSort(const vector<int>& nums)
{
    int n = nums.size(); 
    if(n < 2) return nums;
    vector<int> left, right, middle;
    int m = nums[n/2];
    for(const auto& t : nums)
    {
        if(t < m) left.emplace_back(t);
        else if(t > m) right.emplace_back(t);
        else middle.emplace_back(t);
    }
    left = quickSort(left);
    right = quickSort(right);
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

vector<int> twoSum(vector<int>& nums, int target) {
    nums = quickSort(nums);
    vector<int>::iterator a = nums.begin();
    vector<int>::iterator b = nums.end() - 1;
    vector<int> result;
    while(a != b)
    {
        if(*a + *b == target)
        {
            result.emplace_back(*a);
            result.emplace_back(*b);
            return result;
        }
        else if(*(a + 1) + *b <= target) a++;
        else b--;
    }
    return result;
}

int main()
{
    vector<int> nums;
    for(int i = 0; i < 10; ++i)
    {
        nums.emplace_back(rand()%10);
        cout << *(nums.end() - 1) << "\t";
    }
    cout << endl;
    nums = quickSort(nums);
    for(const auto& t : nums) cout << t << "\t";
    cout << endl;  

    vector<int> result = twoSum(nums, 5);
    for(const auto& t : result) cout << t << "\t";
}