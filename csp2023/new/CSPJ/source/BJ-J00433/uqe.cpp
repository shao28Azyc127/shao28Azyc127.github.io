// 2022/10/21 09:30 finished
// By Jerry1031
//...
//freopen checked!

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int M; // M <= 1e3

void P(int &x, int &y)
{
    int sgnx = (x > 0 ? 1 : -1);
    int sgny = (y > 0 ? 1 : -1);
    x = abs(x);
    y = abs(y);
    int g = __gcd(x, y);
    x /= g;
    y /= g;
    x *= sgnx;
    y *= sgny;
}

void prtfrac(int p, int q)
{
    P(p, q);
    if(q == 1)
        cout << p;
    else
        cout << p << "/" << q;
}

pair<int, int> solveR(int a) // pair{p2, r}
{
    int p2 = 1, r = a;
    int sqrta = sqrt(a);
    for(int i = 2; i <= sqrta; i++)
    {
        int cnti = 0;
        while(a % i == 0)
        {
            a /= i;
            cnti++;
        }
        for(int k = 2; k <= cnti; k += 2)
        {
            p2 *= i;
            r /= i * i;
        }
    }
    return make_pair(p2, r);
}

// \frac{p1}{q1} + \frac{p2\sqrt{r2}}{q2}

void printsqrt(int p2, int q2, int r2)
{
    if(p2 == 1 && q2 == 1) // 1
    {
        cout << "sqrt(" << r2 << ")";
        return;
    }
    if(q2 == 1) // integer, q2 == 1
    {
        cout << p2 << "*sqrt(" << r2 << ")";
        return;
    }
    if(p2 == 1) // 1 / integer, p2 == 1
    {
        cout << "sqrt(" << r2 << ")/" << q2;
        return;
    }
    cout << p2 << "*sqrt(" << r2 << ")/" << q2;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a < 0)
    {
        a = -a;
        b = -b;
        c = -c;
    }

    int delta = b * b - 4 * a * c;
    if(delta < 0)
    {
        cout << "NO" << endl;
        return;
    }

    if(int(sqrt(delta)) * int(sqrt(delta)) == delta)
    {
        int p = -b + sqrt(delta);
        int q = 2 * a;
        prtfrac(p, q);
        cout << endl;
        return;
    }

    int p1 = -b, q1 = 2 * a;
    if(p1 != 0)
    {
        prtfrac(p1, q1);
        cout << "+";
    }

    int p2 = 1, r2 = delta, q2 = 2 * a;
    pair<int, int> Jerry1031 = solveR(r2);
    p2 = Jerry1031.first;
    r2 = Jerry1031.second;
    P(p2, q2);
    printsqrt(p2, q2, r2);
    cout << endl;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int T;
    cin >> T >> M;

    while(T--)
        solve();

    return 0;
}
