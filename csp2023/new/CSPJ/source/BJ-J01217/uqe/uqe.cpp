#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct number
{
    int p;
    int q;
    int c;
    int r;
    int d;
};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

inline void work(number &x)
{
    int f = -1;
    if (x.p < 0 && x.q < 0 || 
        x.p > 0 && x.q > 0)
        f = 1;
    x.p = abs(x.p);
    x.q = abs(x.q);
    int _gcd = gcd(x.p, x.q);
    x.p /= _gcd;
    x.q /= _gcd;
    x.p *= f;

    for (int i = sqrt(x.r); i > 1; i--)
        if (x.r % (i * i) == 0)
        {
            x.r /= i * i;
            x.c *= i;
            break;
        }
    f = -1;
    if (x.c < 0 && x.d < 0 || 
        x.c > 0 && x.d > 0)
        f = 1;
    x.c = abs(x.c);
    x.d = abs(x.d);
    _gcd = gcd(x.c, x.d);
    x.c /= _gcd;
    x.d /= _gcd;
    x.c *= f;

    if (x.r == 1)
    {
        int lcm = x.q * x.d / gcd(x.q, x.d);
        x.p = x.p * lcm / x.q + x.c * lcm / x.d;  
        x.q = lcm;
        f = -1;
        if (x.p < 0 && x.q < 0 || 
            x.p > 0 && x.q > 0)
            f = 1;
        x.p = abs(x.p);
        x.q = abs(x.q);
        _gcd = gcd(x.p, x.q);
        x.p /= _gcd;
        x.q /= _gcd;
        x.p *= f;
        x.c = x.r = x.d = 0;
    }
}

inline void print(number x)
{
    if (x.p || !x.r)
    {
        printf("%d", x.p);
        if (x.q != 1)
            printf("/%d", x.q);
    }
    if (x.r)
    {
        if (x.p)
            printf("+");
        if (x.c == 1 && x.d == 1)
            printf("sqrt(%d)", x.r);
        else if (x.d == 1)
            printf("%d*sqrt(%d)", x.c, x.r);
        else if (x.c == 1)
            printf("sqrt(%d)/%d", x.r, x.d);
        else
            printf("%d*sqrt(%d)/%d", x.c, x.r, x.d);
    }
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t, m;
    scanf("%d%d", &t, &m);
    int a, b, c;
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        int d = b * b - 4 * a * c;
        if (d < 0)
            printf("NO\n");
        else
        {
            number ans;
            if (a > 0)
                ans = (number){-b, a * 2, 1, d, a * 2};
            else
                ans = (number){-b, a * 2, -1, d, a * 2};
            work(ans);
            print(ans);
            printf("\n");
        }
    }
    
    fclose(stdin);
    fclose(stdout);

    return 0;
}