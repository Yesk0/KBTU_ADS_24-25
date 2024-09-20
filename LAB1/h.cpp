#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (is_prime(n) ? "YES" : "NO")<< endl;
    return 0;
}