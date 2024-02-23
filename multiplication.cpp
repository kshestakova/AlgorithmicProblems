#include <iostream>


// Multiplication through addition, O(n)

int multiply(int a, int b)
{
    if(a == 0 || b == 0) return 0;

    int sign = 1;
    if(a < 0)
    {
        sign = -sign;
        a = -a;
    }
    if(b < 0)
    {
        sign = -sign;
        b = -b;
    }
    int result = 0;
    while(a--)
    {
        result += b;
    }
    return sign > 0 ? result : -result;

}

// Bitwise multiplication - Booth's algorythm
// Formal complexity - O(n^2), n - used bits
// much faster than via addition

int bitwise(int a, int b)
{
    int result = 0;

    int sign = 1;
    if(a < 0)
    {
        sign = -sign;
        a = -a;
    }
    if(b < 0)
    {
        sign = -sign;
        b = -b;
    }

    while(b)
    { 
        // If the least significant bit of y is 1, add x to the result
        if(b & 1) result += a;
        // Shift x to the left by 1 (equivalent to multiplying by 2)
        a <<= 1;
        // Shift y to the right by 1 (equivalent to dividing by 2)
        b >>= 1;
    }
    return sign > 0 ? result : -result;
}

int main()
{
    std::cout << multiply(0, 1) << std::endl;
    std::cout << multiply(1, 0) << std::endl;
    std::cout << multiply(1, 5) << std::endl;
    std::cout << multiply(5, 6) << std::endl;
    std::cout << multiply(-5, 6) << std::endl;
    std::cout << multiply(-5, -6) << std::endl;
    std::cout << multiply(5, -6) << std::endl;

    std::cout << bitwise(0, 1) << std::endl;
    std::cout << bitwise(1, 0) << std::endl;
    std::cout << bitwise(1, 5) << std::endl;
    std::cout << bitwise(5, 6) << std::endl;
    std::cout << bitwise(-5, 6) << std::endl;
    std::cout << bitwise(-5, -6) << std::endl;
    std::cout << bitwise(5, -6) << std::endl;
}
