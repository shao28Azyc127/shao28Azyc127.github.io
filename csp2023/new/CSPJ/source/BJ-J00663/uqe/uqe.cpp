#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool gcd(int a, int b)
{
    for (int i = 2; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool check(int v)
{
    for (int q = 1; q <= v; q++)
    {
        double p = v * q;
        if (int(p) == p && gcd(p, q))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d %d", &t, &m);
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (b * b - 4 * a * c < 0)
        {
            printf("NO\n");
            continue;
        }
    }
    return 0;
}
