#include <iostream>
using namespace std;
long long T, M, a, b, c, q1p, q1q, q2p, q2q, r, tmp;
long long gcd(long long x, long long y)
{
    return x ? gcd(y % x, x) : y;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while (T--)
    {
        cin >> a >> b >> c;
        if (a < 0)
        {
            a = -a;
            b = -b;
            c = -c;
        }
        r = b * b - 4 * a * c;
        if (r < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        q2p = 1;
        for (int i = 2; i * i <= r; i++)
            while (r % (i * i) == 0)
                r /= i * i, q2p *= i;
        q1p = -b;
        q1q = 2 * a;
        if (r <= 1)
            q1p += q2p * r, q2p = 0;
        q2q = 2 * a;
        tmp = gcd(abs(q1p), q1q);
        q1p /= tmp;
        q1q /= tmp;
        tmp = gcd(q2p, q2q);
        q2p /= tmp;
        q2q /= tmp;
        if (!q1p && !q2p)
            cout << "0";
        if (q1p)
        {
            cout << q1p;
            if (q1q > 1)
                cout << "/" << q1q;
        }
        if (q1p && q2p)
            cout << "+";
        if (q2p)
        {
            if (q2p > 1)
                cout << q2p << "*";
            cout << "sqrt(" << r << ")";
            if (q2q > 1)
                cout << "/" << q2q;
        }
        cout << endl;
    }
    return 0;
}
