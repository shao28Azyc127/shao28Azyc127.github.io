#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int prime(int x)
{
    int ans = 1;
    for (int i = 2; i * i <= x; i++)
    {
        while (1)
        {
            if (x %(i*i) != 0) break;
            x = x / i / i;
            ans *= i;
        }
    }
    return ans;
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    if (y > x)
    {
        int q = x;
        x = y;
        y = q;
    }
    x = x % y;
    return gcd(y, x);
}

void does()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int d = b * b - 4 * a * c;
    if (d < 0)
    {
        cout << "NO" << endl;
        return ;
    }
    if (int(sqrt(d)) * int(sqrt(d)) == d)
    {
        if (a < 0) b += sqrt(d);
        else b -= sqrt(d);
        d = -1;
    }
    if (b != 0)
    {
        if (b * a > 0) cout << "-";
        if (int(abs(b)) % int(abs(a * 2)) == 0)
        {
            cout << abs(b) / abs(a * 2);
        }
        else
        {
            int p = gcd(b, 2 * a);
            cout << abs(b / p) << "/" << abs(2 * a / p);
        }
        if (d != -1) cout << "+";
    }
    if (d == -1)
    {
        cout << endl;
        return ;
    }
    int k = prime(d);
    d /= k*k;
    if (k == abs(a * 2))
    {
        printf("sqrt(%d)", d);
    }
    else if (k % int(abs(a * 2)) == 0)
    {
        printf("%d*sqrt(%d)", k / abs(a*2), d);
    }
    else if (int(abs(a * 2)) % k == 0)
    {
        printf("sqrt(%d)/%d", d, abs(a*2) / k);
    }
    else{
        int p = gcd(k, 2 * a);
        printf("%d*sqrt(%d)/%d", k / p, d, abs(a*2) / p);
    }
    cout << endl;
    return ;
}


int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        does();
    }
    return 0;
}
