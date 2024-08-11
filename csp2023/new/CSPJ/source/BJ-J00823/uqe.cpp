#include<bits/stdc++.h>
using namespace std;
int Gcd(int x, int y)
{
    if(y == 0) return x;
    return Gcd(y, x % y);
}
void Outfact(int u, int d, bool flag)
{
    if(u == 0)
    {
        if(flag) printf("0");
        return;
    }
    if(u < 0 && d >= 0)
    {
        printf("-");
    }
    else if(u >= 0 && d < 0)
    {
        printf("-");
    }
    u = abs(u);
    d = abs(d);
    int g = Gcd(u, d);
    u /= g;
    d /= g;
    if(d == 1) printf("%d", u);
    else printf("%d/%d", u, d);
}
void Outsqrt(int u, int d, int r)
{
    int g = Gcd(u, d);
    u /= g;
    d /= g;
    if(u == 1 && d == 1) printf("sqrt(%d)", r);
    else if(d == 1) printf("%d*sqrt(%d)", u, r);
    else if(u == 1) printf("sqrt(%d)/%d", r, d);
    else printf("%d*sqrt(%d)/%d", u, r, d);
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d%d", &t, &m);
    while(t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int r = b * b - 4 * a * c;
        if(r < 0)
        {
            puts("NO");
            continue;
        }
        int sqt = -1;
        for(int i = 0; i * i <= r; i++)
        {
            if(i * i == r)
            {
                sqt = i;
                break;
            }
        }
        if(sqt == -1)
        {
            int u = -b;
            int d = 2 * a;
            if(u != 0)
            {
                Outfact(u, d, false);
                printf("+");
            }
            u = 1;
            d = abs(d);
            for(int i = 2; i * i <= r; i++)
            {
                while(r % (i * i) == 0)
                {
                    r /= (i * i);
                    u *= i;
                }
            }
            Outsqrt(u, d, r);
        }
        else
        {
            if(2 * a > 0) Outfact(sqt - b, 2 * a, true);
            else Outfact((-sqt) - b, 2 * a, true);
        }
        puts("");
    }
    return 0;
}
