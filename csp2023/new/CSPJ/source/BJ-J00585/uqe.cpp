#include <bits/stdc++.h>

using namespace std;
const int op = 1e-8;
int T, M, a, b, c;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

double frk(int k)
{
    int ri= 1;
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0 && abs((k / i) - sqrt(k / i) * sqrt(k / i)) <= op)
        {
            ri = i;
        }
    }
    return ri;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    scanf("%d%d", &T, &M);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        int k = b * b - 4 * a * c;
        if (k < 0)
        {
            printf("NO\n");
            continue;
        }
        else if (k == 0)
        {
            int p1, p2, g = gcd(-b, 2 * a);
            p1 = -b / g; p2 = 2*a / g;
            if (p2 == 1)
                printf("%d", p1);
            else
            {
                printf("%d/%d", p1, p2);
            }
            printf("\n");
            continue;
        }
        else
        {
            double x = (-b + double(sqrt(k))) / (2 * a);
            if (abs(x - (int)x) <= op)
            {
                printf("%d\n", (int)x);
                continue;
            }
            double r = frk(k);
            int ffr = sqrt(k / r);
            double q1 = -b / double(2 * a), q2 = ffr / double(2 * a);
            if (q1 != 0)
            {
                int p1, p2, g = gcd(-b, 2 * a);
                p1 = -b / g; p2 = 2*a / g;
                if (p2 == 1)
                    printf("%d+", p1);
                else
                {
                    printf("%d/%d+", p1, p2);
                }
            }

            if (abs(q2 - 1) <= op)
            {
                printf("sqrt(%d)", (int)r);
            }
            else if (abs(q2 - (int)q2) <= op)
            {
                printf("%d*sqrt(%d)", (int)q2, (int)r);
            }
            else if (abs((1/q2) - int(1/q2)) <= op)
            {
                printf("sqrt(%d)/%d", (int)r, (int)(1/q2));
            }
            else
            {
                printf("%d*sqrt(%d)/%d", ffr, (int)r, (int)(2*a));
            }
            printf("\n");
        }
    }
    return 0;
}
