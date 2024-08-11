#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int pa, pb, qa, qb, r, ans1, ans2;

int gcd(int x, int y)
{
    if (x == 0 || x == y)return y;
    return gcd(abs(x - y), x);
}

int cal(int r)
{
    int ans = 1;
    for (int i = 1; i * i <= r; i++)
    {
        if (r % (i * i) == 0)
        {
            ans *= i;
            r /= i * i;
        }
    }
    return ans;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m;
    cin >> T >> m;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        r = b * b - 4 * a * c;
        if (r < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        pa = -1*b, pb = 2 * a;

        int f1 = 1;
        if ((pa > 0 && pb < 0) || (pa < 0 && pb > 0))f1 = -1; //
        int x = gcd(pa, pb);
        pa /= x / f1; //
        pb /= x; //
        int temp = cal(r);
        qa = temp, qb = 2 * a;

        int f2 = 1;
        if ((qa > 0 && qb < 0) || (qa < 0 && qb > 0))f2 = -1; //
        int y = gcd(qa, qb);
        qa /= y / f2; //
        qb /= y; //

        //cout << pa << " " << pb << " " << qa << " " << qb << endl;
        if (r == 0)
        {
            cout << pa << "/" << pb << endl;
        }
        else if (temp * temp == r)
        {
            ans1 = pa * qb + pb * qa, ans2 = pb * qb;

            int f3 = 1;
            if ((ans1 > 0 && ans2 < 0) || (ans1 < 0 && ans2 > 0))f3 = -1; //
            int z = gcd(ans1, ans2);
            ans1 /= z / f3; //
            ans2 /= z; //

            if (ans1 == ans2)cout << 1 << endl;
            else cout << ans1 << "/" << ans2 << endl;
        }
        else
        {
            r /= temp * temp;
            if (pa == pb)cout << 1 << "+";
            else if (pa != 0)cout << pa << "/" << pb << "+";
            if (qa == qb)cout << "sqrt(" << r << ")" << endl;
            else if (qa == 1)cout << "sqrt(" << r << ")/" << qb << endl;
            else if (qb == 1)cout << qa << "*sqrt(" << r << ")" << endl;
            else cout << qa << "*sqrt(" << r << ")/" << qb << endl;
        }
    }
    return 0;
}
