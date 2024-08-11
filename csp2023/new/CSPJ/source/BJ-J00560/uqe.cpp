#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;

int gcd(int m, int n)
{
    int r = 1;
    while (r)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

void printYouLi(int p, int q)
{
    int g = gcd(p, q);
    p /= g;
    q /= g;
    if (q < 0)
    {
        p = -p;
        q = -q;
    }
    if (q == 1)
    {
        printf("%d", p);
    }
    else
    {
        printf("%d/%d", p, q);
    }
}

pair<int, int> simpleGenShi(int q2, int r)
{
    int tmp = r;
    for (int i = 2; i * i <= tmp; ++i)
    {
        while (r % (i * i) == 0)
        {
            q2 *= i;
            r /= (i * i);
        }
    }
    return { q2, r };
}

void printWuLi(int b, int d, int a, int sign)
{
    if (-b != 0)
    {
        printYouLi(-b, 2 * a);
        printf("+");
    }
    int q2 = sign, r = d;
    auto p = simpleGenShi(q2, r);
    q2 = p.first;
    r = p.second;
    int g = gcd(q2, 2 * a);
    q2 /= g;
    int div = 2 * a / g;
    if (div == 1 && q2 == 1)
    {
        printf("sqrt(%d)\n", r);
    }
    else if (div == 1)
    {
        printf("%d*sqrt(%d)\n", q2, r);
    }
    else if (q2 == 1)
    {
        printf("sqrt(%d)/%d\n", r, div);
    }
    else
    {
        printf("%d*sqrt(%d)/%d\n", q2, r, div);
    }
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
        int d = b * b - 4 * a * c;
        if (d < 0)
        {
            printf("NO\n");
        }
        else if (d == 0)
        {
            printYouLi(-b, 2 * a);
            printf("\n");
        }
        else
        {
            double sq = sqrt(d);
            bool square = abs(double(int(sq)) - sq) <= 1e-6;
            if ((-b + sq) / (2 * a) >= (-b - sq) / (2 * a))
            {
                if (square)
                {
                    printYouLi(-b + sq, 2 * a);
                    printf("\n");
                }
                else
                {
                    printWuLi(b, d, a, 1);
                }

            }
            else
            {
                if (square)
                {
                    printYouLi(-b - sq, 2 * a);
                    printf("\n");
                }
                else
                {
                    printWuLi(b, d, a, -1);
                }
            }
        }
    }
}
