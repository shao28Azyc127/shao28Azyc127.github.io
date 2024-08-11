#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int k = b * b - 4 * a * c;
        if (k < 0)
        {
            cout << "NO" << endl;
        }
        else if (sqrt(k) == 1.0 * floor(sqrt(k)))
        {
            int p;
            if (a > 0) p = sqrt(k) - b;
            else p = -sqrt(k) - b;
            int q = 2 * a;
            if (p * q < 0) cout << "-";
            p = abs(p);
            q = abs(q);
            int g = gcd(p, q);
            p /= g;
            q /= g;
            if (q == 1) cout << p << endl;
            else printf("%d/%d\n", p, q);
        }
        else
        {
            int op = k, mul = 1, p, q;
            for (int i = 2; i * i <= op; i++)
            {
                while (op % (i * i) == 0)
                {
                    op /= i * i;
                    mul *= i;
                }
            }
            if (b != 0)
            {
                p = -b;
                q = 2 * a;
                if (p * q < 0) cout << "-";
                p = abs(p);
                q = abs(q);
                int g = gcd(p, q);
                p /= g;
                q /= g;
                if (q == 1) cout << p;
                else printf("%d/%d", p, q);
            }
            p = mul;
            q = 2 * a;
            if (b != 0) cout << "+";
            p = abs(p);
            q = abs(q);
            int g = gcd(p, q);
            p /= g;
            q /= g;
            if (p == 1)
            {
                printf("sqrt(%d)", op);
                if (q != 1) printf("/%d", q);
            }
            else
            {
                printf("%d*sqrt(%d)", p, op);
                if (q != 1) printf("/%d", q);
            }
            cout << endl;
        }
    }
    return 0;
}
