#include <vector>

using namespace std;

// Supposed we have a vector of balls with values 0, 1 and 2
// We need to sort it with minimal complexity, preferably in-place
// Solution using Dutch national flag algorythm - O(n), in-place
void sort(vector<int>& balls)
{
    int n = balls.size();
    int low = 0, mid = 0, high = n-1;
    int count = 0;
    while(mid <= high)
    {
        if(balls[mid] == 0)
        {
            swap(balls[low], balls[mid]);
            low++;
            mid++;
        }
        else if(balls[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(balls[high], balls[mid]);
            high--;
        }
    }
}

int main()
{
    vector<int> balls {1, 0, 1, 0, 2, 2, 0, 2, 1};
    sort(balls);
    
}