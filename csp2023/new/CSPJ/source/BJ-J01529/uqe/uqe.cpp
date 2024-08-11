#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

long long a, b, c;
long long q11, q12;
long long q21, q22;
long long r;

void toans(long long& x, long long& y)
{
    int t = __gcd(x, y);
    x = x / t;
    y = y / t;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int T, M;
    scanf("%d%d", &T, &M);
    while (T --)
    {
        scanf("%lld%lld%lld", &a, &b, &c);

        r = b * b - 4 * a * c;
        if (r < 0)
        {
            printf("NO\n");
            continue;
        }

        long long t = sqrt(r);
        if (t * t == r)
        {
            q12 = 2 * a;
            q11 = -b + t;
            toans(q11, q12);
            if (q11 > 0 && q12 < 0)
            {
                q11 = -q11;
                q12 = -q12;
            }
            if (q12 == 1)
                printf("%lld\n", q11);
            else
                printf("%lld/%lld\n", q11, q12);
            continue;
        }

        q11 = -b, q12 = 2 * a;
        toans(q11, q12);
        q22 = 2 * a;
        q21 = 1;
        for (int i = sqrt(r);i > 1;i --)
        {
            if (r % (i * i) == 0)
            {
                r /= (i * i);
                q21 *= i;
            }
        }
        toans(q21, q22);

        if (q11 > 0 && q12 < 0)
        {
            q11 = -q11;
            q12 = -q12;
        }
        if (q11 != 0)
        {
            if (q12 == 1)
                printf("%lld+", q11);
            else
                printf("%lld/%lld+", q11, q12);
        }
        if (q21 == 1 && q22 == 1)
            printf("sqrt(%lld)", r);
        else if (q21 == 1)
            printf("sqrt(%lld)/%lld", r, abs(q22));
        else if (q22 == 1)
            printf("%lld*sqrt(%lld)", abs(q21), r);
        else
            printf("%lld/%lld*sqrt(%lld)", abs(q21), abs(q22), r);
        printf("\n");
    }
    return 0;
}
