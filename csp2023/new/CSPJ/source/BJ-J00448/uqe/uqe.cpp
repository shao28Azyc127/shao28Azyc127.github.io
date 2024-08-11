#include <bits/stdc++.h>
using namespace std;

int csqrt(int x)
{
    int l = 0, r = x;
    while(l <= r)
    {
        int mid = (l + r) / 2, a = mid * mid;
        if(a == x)
        {
            return mid;
        }
        if(a < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int vsqrt(int x)
{
    int res = 1;
    for(int i = 2;i * i <= x;i++)
    {
        bool add = false;
        while(x % i == 0)
        {
            if(add)
            {
                res *= i;
            }
            add = !add;
            x /= i;
        }
    }
    return res;
}

int gcd(int x, int y)
{
    if(x > y)
    {
        swap(x, y);
    }
    while(x)
    {
        int tmp = x;
        x = y % x;
        y = tmp;
    }
    return y;
}

void printfrac(int x, int y)
{
    if(x < 0 && y < 0)
    {
        x = -x;
        y = -y;
    }
    else if(x < 0)
    {
        x = -x;
        printf("-");
    }
    else if(y < 0)
    {
        y = -y;
        printf("-");
    }
    int z = gcd(x, y);
    x /= z;
    y /= z;
    if(y == 1)
    {
        printf("%d", x);
    }
    else
    {
        printf("%d/%d", x, y);
    }
}

void printsqrt(int x1, int y1, int x2, int y2)
{
    if(x1)
    {
        printfrac(x1, y1);
        printf("+");
    }
    int x = vsqrt(x2), y = x2 / (x * x), z = gcd(x, y2);
    x /= z;
    y2 /= z;
    if(x != 1)
    {
        printf("%d*", x);
    }
    if(y2 == 1)
    {
        printf("sqrt(%d)", y);
    }
    else
    {
        printf("sqrt(%d)/%d", y, y2);
    }
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d %d", &t, &m);
    while(t--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int d = b * b - 4 * a * c;
        if(d < 0)
        {
            printf("NO\n");
            continue;
        }
        int tmp = csqrt(d);
        if(tmp != -1)
        {
            printfrac(-b + tmp, 2 * a);
        }
        else
        {
            if(a > 0)
            {
                printsqrt(-b, 2 * a, d, 2 * a);
            }
            else
            {
                printsqrt(-b, 2 * a, d, -2 * a);
            }
        }
        printf("\n");
    }
    return 0;
}
