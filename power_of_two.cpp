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

bool isPowerSimple(uint32_t number)
{
    return (number & (number-1)) == 0 && number != 0;
}

int main()
{
    cout << isPowerOfTwo(0) << "\t" << isPowerSimple(0) << endl;
    cout << isPowerOfTwo(1) << "\t" << isPowerSimple(1) << endl;
    cout << isPowerOfTwo(2) << "\t" << isPowerSimple(2) << endl;
    cout << isPowerOfTwo(16) << "\t" << isPowerSimple(16) << endl;
    cout << isPowerOfTwo(17) << "\t" << isPowerSimple(17) << endl;
    cout << isPowerOfTwo(0xffffffff) << "\t" << isPowerSimple(0xffffffff) << endl;
}