#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int x, int y)
{
    if (abs(x) < abs(y)) swap(x, y);
    if (y == 0) return abs(x);
    if (x == 0) return abs(y);
    return gcd(((x % y) + y) % y, y);
}

int chai(int x)
{
    int r1 = 1;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % (i * i) == 0)
        {
            r1 *= i;
            x /= (i * i);
        }
    }
    return r1;
}

void cq(int x, int y)
{
    int g = gcd(x, y);
    x /= g, y /= g;
    if (y < 0) x = -x, y = -y;
    if (y == 1) printf("%d", x);
    else printf("%d/%d", x, y);
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d%d", &t, &m);
    while (t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int deta = b * b - 4 * a * c;
        if (deta < 0)
        {
            printf("NO\n");
            continue;
        }
        if (sqrt(deta) == floor(sqrt(deta)))
        {
            int p;
            if (a > 0) p = -b + sqrt(deta);
            else p = -b - sqrt(deta);
            int q = 2 * a;
            cq(p, q);
            printf("\n");
            continue;
        }
        if (b != 0)
        {
            cq(-b, 2 * a);
            printf("+");
        }
        int q2p = chai(deta), q2q = abs(2 * a), r = deta / (q2p * q2p);
        if (q2p == q2q) printf("sqrt(%d)\n", r);
        else if ((1.0 * q2p / q2q) == floor(1.0 * q2p / q2q))
            printf("%d*sqrt(%d)\n", abs(q2p / q2q), r);
        else if ((1.0 * q2q / q2p) == floor(1.0 * q2q / q2p))
            printf("sqrt(%d)/%d\n", r, abs(q2q / q2p));
        else
        {
            int g = gcd(q2p, q2q);
            q2p /= g, q2q /= g;
            printf("%d*sqrt(%d)/%d\n", q2p, r, q2q);
        }
    }
    return 0;
}