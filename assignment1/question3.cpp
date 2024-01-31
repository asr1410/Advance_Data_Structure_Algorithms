#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }

    if (a % 11 == 0 && b % 11 == 0)
    {
        return 11 * gcd(a / 11, b / 11);
    }
    else if (a % 11 == 0 && a % 2 != 0 && b % 11 != 0)
    {
        return gcd(a / 11, 2 * b);
    }
    else if (a % 11 == 0 && a % 2 == 0 && b % 11 != 0)
    {
        return gcd(a / 11, abs(a - b));
    }
    else if (b % 11 == 0 && b % 2 != 0 && a % 11 != 0)
    {
        return gcd(2 * a, b / 11);
    }
    else if (b % 11 == 0 && b % 2 == 0 && a % 11 != 0)
    {
        return gcd(abs(a - b), b / 11);
    }
    else
    {
        return gcd(abs(a - b), min(a, b));
    }
}

int main()
{
    int a, b;
    cout << "Enter First Number: ";
    cin >> a;
    cout << "Enter Second Number: ";
    cin >> b;
    cout << "GCD of " << a << " and " << b << ": " << gcd(a, b) << endl;
}
