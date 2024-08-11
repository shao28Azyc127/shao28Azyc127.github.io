#include <bits/stdc++.h>
using namespace std;
bool f[10000005];
int gcd(int x, int y)
{
    x = abs(x);
    y = abs(y);
    while(x != 0 && y != 0)
    {
        if (x > y) x %= y;
        else y %= x;
    }
    return max(x, y);
}
int work(int x)
{
    int ans = 1;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % (i * i) == 0)
        {
            ans *= i;
            x /= (i * i);
        }
    }
    return ans;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    scanf("%d%d", &T, &M);
    for (int i = 0; i <= 2 * M; i++) f[i * i] = 1;
    while(T--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int x = (b * b) - (4 * a * c);
        if (x < 0)
        {
            printf("NO\n");
            continue;
        }
        if (f[x])
        {
            int sx = sqrt(x);
            if (a >= 0)
            {
                int p = -b + sx;
                int q = 2 * a;
                if (q < 0)
                {
                    p *= -1;
                    q *= -1;
                }
                int tmp = gcd(p, q);
                p /= tmp;
                q /= tmp;
                if (q == 1) printf("%d\n", p);
                else printf("%d/%d\n", p, q);
            }
            else
            {
                int p = -b - sx;
                int q = 2 * a;
                if (q < 0)
                {
                    p *= -1;
                    q *= -1;
                }
                int tmp = gcd(p, q);
                p /= tmp;
                q /= tmp;
                if (q == 1) printf("%d\n", p);
                else printf("%d/%d\n", p, q);
            }
        }
        else
        {
            if (a >= 0)
            {
                if (b != 0)
                {
                    int p1 = -b, q1 = 2 * a;
                    if (q1 < 0)
                    {
                        p1 *= -1;
                        q1 *= -1;
                    }
                    int tmp = gcd(p1, q1);
                    p1 /= tmp;
                    q1 /= tmp;
                    if (q1 == 1) printf("%d", p1);
                    else printf("%d/%d", p1, q1);
                    cout << '+';
                }
                int xxs = work(x);
                int r = x / xxs / xxs;
                if (xxs == 2 * a) printf("sqrt(%d)", r);
                else if (xxs % abs((2 * a)) == 0) printf("%d*sqrt(%d)", xxs / (2 * a), r);
                else if (abs((2 * a)) % xxs == 0) printf("sqrt(%d)/%d", r, (2 * a) / xxs);
                else
                {
                    int p2 = xxs;
                    int q2 = 2 * a;
                    if (q2 < 0)
                    {
                        p2 *= -1;
                        q2 *= -1;
                    }
                    int tmp = gcd(xxs, 2 * a);
                    p2 /= tmp;
                    q2 /= tmp;
                    printf("%d*sqrt(%d)/%d", p2, r, q2);
                }
                printf("\n");
            }
            else
            {
                if (b != 0)
                {
                    int p1 = -b, q1 = 2 * a;
                    if (q1 < 0)
                    {
                        p1 *= -1;
                        q1 *= -1;
                    }
                    int tmp = gcd(p1, q1);
                    p1 /= tmp;
                    q1 /= tmp;
                    if (q1 == 1) printf("%d", p1);
                    else printf("%d/%d", p1, q1);
                    cout << '+';
                }
                int xxs = -work(x);
                int r = x / xxs / xxs;
                if (xxs == 2 * a) printf("sqrt(%d)", r);
                else if (xxs % abs((2 * a)) == 0) printf("%d*sqrt(%d)", xxs / (2 * a), r);
                else if (abs((2 * a)) % xxs == 0) printf("sqrt(%d)/%d", r, (2 * a) / xxs);
                else
                {
                    int p2 = xxs;
                    int q2 = 2 * a;
                    if (q2 < 0)
                    {
                        p2 *= -1;
                        q2 *= -1;
                    }
                    int tmp = gcd(xxs, 2 * a);
                    p2 /= tmp;
                    q2 /= tmp;
                    printf("%d*sqrt(%d)/%d", p2, r, q2);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
