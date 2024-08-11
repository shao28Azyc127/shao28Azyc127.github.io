#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int T, M;

long long gcd(long long a, long long b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct Q
{
    long long p, q;
    void yuefen()
    {
        if (q < 0)
        {
            p = -p;
            q = -q;
        }
        long long gcd_ = gcd(p, q);
        p /= gcd_;
        q /= gcd_;
    }
    void prt()
    {
        yuefen();
        if (q == 1) cout << p;
        else cout << p << "/" << q;
    }
};

bool operator== (Q a, long long b)
{
    a.yuefen();
    return a.p == b && a.q == 1;
}

bool operator!= (Q a, long long b)
{
    return !(a == b);
}

Q operator+ (Q a, Q b)
{
    Q ans = {a.p * b.q + b.p * a.q, a.q * b.q};
    ans.yuefen();
    return ans;
}

long long pull(long long undersqrt)
{
    long long pout = 1;
    for (int i = 2; i <= M; i++)
    {
        while (undersqrt % (i * i) == 0)
        {
            undersqrt /= (i * i);
            pout *= i;
        }
    }
    return pout;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    for (int i = 1; i <= T; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a < 0)
        {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        int gcd__ = gcd(a, gcd(b, c));
        if (gcd__ > 1)
        {
            a /= gcd__;
            b /= gcd__;
            c /= gcd__;
        }
        if (b * b < 4 * a * c)
        {
            cout << "NO" << endl;
            continue;
        }
        long long delta = b * b - 4 * a * c;
        long long sqrtdel = sqrt(delta);
        if (sqrtdel * sqrtdel == delta)
        {
            Q num_ = {-b + sqrtdel, 2 * a};
            num_.prt();
            cout << endl;
            continue;
        }
        Q num1 = {-b, 2 * a};
        num1.yuefen();
        long long zero = 0;
        if (num1 != zero)
        {
            num1.prt();
            cout << "+";
        }
        long long pout = pull(delta);
        delta /= pout * pout;
        Q num2 = {pout, 2 * a};
        num2.yuefen();
        if (num2 != 1ll)
        {
            //if (num2.p < 0) num2.p *= -1;
            //if (num2.q < 0) num2.q *= -1;
            if (num2.p != 1ll) cout << num2.p << "*";
            cout << "sqrt(" << delta << ")";
            if (num2.q != 1ll) cout << "/" << num2.q;
        }
        else cout << "sqrt(" << delta << ")";
        cout << endl;
    }
    return 0;
}
