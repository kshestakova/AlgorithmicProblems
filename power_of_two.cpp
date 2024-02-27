#include <iostream>

using namespace std;

bool isPowerOfTwo(uint32_t number)
{
    int count = 0;
    while(number && count < 2)
    {
        count += number & 1;
        number >>= 1;
    }
    return count == 1;
}

int main()
{
    cout << isPowerOfTwo(0) << endl;
    cout << isPowerOfTwo(1) << endl;
    cout << isPowerOfTwo(2) << endl;
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(17) << endl;
    cout << isPowerOfTwo(0xffffffff) << endl;
}