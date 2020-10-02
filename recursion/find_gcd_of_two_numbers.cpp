// Find the Greatest Common Divisor of two numbers
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int main()
{
    int a = 14, b = 20;
    cout << gcd(a, b) << endl;
    return 0;
}