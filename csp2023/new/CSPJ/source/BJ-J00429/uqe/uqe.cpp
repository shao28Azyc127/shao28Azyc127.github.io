#include <bits/stdc++.h>
using namespace std;
int T, M;
int a, b, c;
int gcd(int a, int b)
{
    if (a == 0 || b == 0) return 1;
    if (a > 0 && b > 0) return __gcd(abs(a), abs(b));
    if (a > 0 && b < 0) return -__gcd(abs(a), abs(b));
    if (a < 0 && b > 0) return -__gcd(abs(a), abs(b));
    if (a < 0 && b < 0) return __gcd(abs(a), abs(b));
}
int __gcd(int a, int b)
{
    if (b == 0) return a;
    else return __gcd(b, a % b);
}
vector<pair<int, int> > divide(int x)
{
    vector<pair<int, int> > ans;
    for (int i = 2, cnt; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            ans.push_back(make_pair(i, cnt));
        }
    }
    if (x > 1) ans.push_back(make_pair(x, 1));
    return ans;
}
inline void solve()
{
    scanf("%d%d%d", &a, &b, &c);
    int t = b * b - 4 * a * c;
    if (t < 0) printf("NO\n");
    else
    {
        // -b / 2a + sqrt(t) / 2a
        // A/B+C*sqrt(D)/E
        int A = -b;
        int B = 2 * a;
        int k = gcd(A, B);
        A = A / k;
        B = B / k;
        int C = (a > 0) ? 1 : -1;
        int D = t;
        int E = 2 * a;
        vector<pair<int, int> > x = divide(D);
        int tk = 1;
        for (int i = 0; i < x.size(); i++)
        {
            tk *= pow(x[i].first, x[i].second / 2);
        }
        D /= tk;
        D /= tk;
        C *= tk;
        k = gcd(C, E);
        C = C / k;
        E = E / k;
        if (E < 0)
        {
            E = -E;
            C = -C;
        }
        if (D == 1)
        {
            A = A * E + C * B;
            B = B * E;
            k = gcd(A, B);
            A = A / k;
            B = B / k;
            D = 0;
        }
        if (B < 0)
        {
            B = -B;
            A = -A;
        }
        if (C < 0) C = -C; // ะþัง
        if (A == 0)
        {
            if (D == 0) printf("0\n");
            else
            {
                if (D == 1) printf("%d/%d\n", C, E);
                else
                {
                    if (C == 1 && E == 1) printf("sqrt(%d)\n", D);
                    else if (C == 1) printf("sqrt(%d)/%d\n", D, E);
                    else if (E == 1) printf("%d*sqrt(%d)\n", C, D);
                    else printf("%d*sqrt(%d)/%d\n", C, D, E);
                }
            }
        }
        else
        {
            if (A == 1 && B == 1) printf("1");
            else if (A == -1 && B == 1) printf("-1");
            else if (B == 1) printf("%d", A);
            else
            {
                printf("%d/%d", A, B);
            }
            if (D == 0) printf("\n");
            else
            {
                if (C == 1 && E == 1) printf("+sqrt(%d)\n", D);
                else if (C == 1) printf("+sqrt(%d)/%d\n", D, E);
                else if (E == 1) printf("+%d*sqrt(%d)\n", C, D);
                else printf("+%d*sqrt(%d)/%d\n", C, D, E);
            }
        }
    }
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while (T--)
    {
        solve();
    }
    return 0;
}
