#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int k = 1;
    while (k != 0)
    {
        k = a % b;
        a = b;
        b = k;
    }
    return b;
}

int gen(int a)
{
    for (int i = 1; i < sqrt(a); i++)
    {
        if (gcd(a, i) == i)
        {
            if (sqrt(float(a / i)) == sqrt(a / i))
            {
                return a / i;
            }
        }
    }
    return a;
}

int main()
{
    freopen("uqe.in", r, stdin);
    freopen("uqe.out", w, stdout);
    int m, n;
    cin >> n >> m;
    int list[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i][0] >> list[i][1] >> list[i][2];
    }
    for (int i = 0; i < n; i++)
    {
        int derta, r, a = list[i][0], b = list[i][1], c = list[i][2];
        if (a < 0) {a = -a; b = -b; c= -c;}
        r = b * b- 4 * a * c;
        if (r < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (r == 0)
        {
            if (gcd(2 * a, abs(b)) == 2 * a)
            {
                cout << b / (2 * a) << endl;
            }
            else
            {
                cout << -b / gcd(2 * a, abs(b)) << "/" << a / gcd(2 * a, abs(b)) << endl;
            }
            continue;
        }
        if (gcd(2 * a, abs(b)) == 2 * a)
        {
            cout << -b / (2 * a) << "+";
        }
        else
        {
            cout << -b / gcd(2 * a, abs(b)) << "/" << a / gcd(2 * a, abs(b)) << "+";
        }
        derta = sqrt(gen(r));
        if (gcd(2 * a, derta) == 2 * a && gcd(2 * a, derta) == derta)
        {
            cout << "sqrt(" << r / derta / derta << ")" << endl;
        }
        else
        {
            if (gcd(2 * a, derta) == 2 * a)
            {
                cout << derta / 2 / a << "*" << "sqrt(" << r / derta / derta << ")" << endl;
            }
            else
            {
                if (gcd(derta, 2 * a) == derta)
                {
                    cout << "sqrt(" << r / derta / derta << ")/" << 2 * a / derta << endl;
                }
                else
                {
                    cout << derta / gcd(derta, 2 * a) << "*" << "sqrt(" << r / derta / derta << ")/" <<
                }
            }
        }
    }
    return 0;
}