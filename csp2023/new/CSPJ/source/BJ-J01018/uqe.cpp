#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}
int xx;
inline void out(int x, int y)
{
    if (y < 0)
        x = -x, y = -y;
    xx = gcd(abs(x), abs(y));
    x /= xx, y /= xx;
    if (x == y)
        printf("1");
    else if (x % y == 0)
        printf("%lld", x / y);
    else if (x == 0)
        printf("0");
    else if (y == 1)
        printf("%lld", x);
    else
        printf("%lld/%lld", x, y);
}
inline int ksm(int x, int y)
{
    xx = 1;
    while (y)
    {
        if (y & 1)
            xx *= x;
        x *= x, y >>= 1;
    }
    return xx;
}
signed main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m, a, b, c, q2, r, rr, nc, nn;
    scanf("%lld %lld", &t, &m);
    while (t--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (b * b - 4 * a * c < 0)
        {
            printf("NO\n");
        }
        else
        {
            if (b * b - 4 * a * c == 0)
            {
                out(-b, a * 2);
                putchar('\n');
            }
            else
            {
                r = b * b - 4 * a * c;
                rr = r;
                nn = 1;
                for (int i = 2; i * i <= rr; i++)
                {
                    nc = 0;
                    while (rr % i == 0)
                        nc++, rr /= i;
                    if (nc > 1)
                        nn *= ksm(i, nc / 2), r /= ksm(i, nc - nc % 2);
                }
                if (r == 1)
                {
                    out(-b + nn, 2 * a);
                    putchar('\n');
                }
                else
                {
                    if (1.0 * b / (2 * a) != 0)
                    {
                        out(-b, 2 * a);
                        putchar('+');
                    }
                    if (abs(nn) == abs(2 * a))
                    {
                        printf("sqrt(%lld)\n", r);
                    }
                    else if (nn % (2 * a) == 0)
                    {
                        printf("%lld*sqrt(%lld)\n", abs(nn / (2 * a)), r);
                    }
                    else if ((2 * a) % nn == 0)
                        printf("sqrt(%lld)/%lld\n", r, abs((2 * a) / nn));
                    else
                    {
                        xx = gcd(nn, a * 2);
                        printf("%lld*sqrt(%lld)/%lld\n", nn / xx, r, abs(2 * a) / xx);
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//ZYC AK IOI, RANGER_CW AK IOI