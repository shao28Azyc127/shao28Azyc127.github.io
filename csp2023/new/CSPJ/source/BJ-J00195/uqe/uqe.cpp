#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//10:10 AC T3
//3min earlier,my computer is stucked and I was very nervous
//but luckily it's running again.
// /bx

struct Q
{
    int son, mom;//son/mom
};

struct R
{
    int r, sqt, son, mom;//(son + r * sqrt(sqt)) / mom
};

Q getdelta(int a, int b, int c)
{
    Q ans;
    ans.mom = 1, ans.son = b * b - 4 * a * c;
    return ans; 
}

void chai(int r, int &q)
{
    for(int i = 2;i * i <= r;i++)
    {
        if(r % i == 0)
        {
            int t = 0;
            while(r % i == 0)
            {
                t++;
                r /= i;
            }
            q *= pow(i, t / 2);
        }
    }
    if(r)
    {
        if((int)(sqrt(r)) * (int)(sqrt(r)) == r)
        {
            q *= (int)(sqrt(r));
        }
    }
    return;
}

R getx(int a, int b, int c)
{
    Q delta = getdelta(a, b, c);
    R x;
    x.mom = a * 2;
    x.son = -b;
    x.sqt = delta.son;
    x.r = 1;
    if(a < 0)
    {
        x.mom = -x.mom, x.son = b;
    }
    chai(x.sqt, x.r);
    x.sqt /= x.r;
    x.sqt /= x.r;
    return x;
}

void printQ(Q x)
{
    if(x.mom < 0)
    {
        x.mom = -x.mom, x.son = -x.son;
    }
    if(x.mom == x.son)
    {
        cout << 1;
        return;
    }
    if(x.mom == -x.son)
    {
        cout << -1;
        return;
    }
    if(x.son % x.mom == 0)
    {
        cout << x.son / x.mom;
        return;
    }
    int gcd = __gcd(x.son, x.mom);
    x.son /= gcd;
    x.mom /= gcd;
    if(x.mom < 0)
    {
        x.mom = -x.mom, x.son = -x.son;
    }
    cout << x.son << "/" << x.mom;
    return;
}

void yuefen(Q &q)
{
    int gcd = __gcd(q.son, q.mom);
    q.son /= gcd, q.mom /= gcd;
    if(q.mom < 0)q.mom = -q.mom, q.son = -q.son;
    return;
}

void print(R x)
{
    if(x.sqt * x.r == 0)//son/mom
    {
        Q y;
        y.son = x.son, y.mom = x.mom;
        printQ(y);
        cout << "\n";
        return;
    }
    if(x.sqt == 1)
    {
        x.son += x.r;
        Q y;
        y.son = x.son, y.mom = x.mom;
        printQ(y);
        cout << "\n";
        return;
    }
    Q q1, q2;
    q1.son = x.son, q1.mom = x.mom;
    q2.mom = x.mom, q2.son = x.r;
    int r = x.sqt;
    yuefen(q2);
    if(q1.son)
    {
        printQ(q1);
        cout << "+";
    }
    if(q2.son == q2.mom)
    {
        cout << "sqrt(" << r << ")\n";
        return;
    }
    if(q2.mom == 1)
    {
        cout << q2.son  << "*sqrt(" << r << ")\n";
        return;
    }
    if(q2.son == 1)
    {
        cout << "sqrt(" << r << ")/" << q2.mom << "\n";
        return;
    }
    cout << q2.son << "*sqrt(" << r << ")/" << q2.mom << "\n";
    return;
}

signed main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    srand(time(0) + 2327);
    int t, m;
    t = read(), m = read();
    while(t--)
    {
        int a, b, c;
        a = read(), b = read(), c = read();
        Q delta = getdelta(a, b, c);
        if(delta.son < 0)
        {
            cout << "NO\n";
            continue;
        }
        R x = getx(a, b, c);
        print(x);
    }
    return 0;
}