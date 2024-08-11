#include <iostream>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
    #define isdigit(x) ((x) >= '0' && (x) <= '9')
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool f = 0; char ch = gc();
        while (!isdigit(ch)) {if (ch == '-') f = 1; ch = gc();}
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (f) x = -x;
    }
}

using FastIO::Read;
using namespace std;

const int MAXN = 1e5 + 10;

int n, a[5];
int msk[MAXN];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    Read(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 5; j++) Read(a[j]);
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                a[j] = (a[j] + 1) % 10;
                int cur = 0;
                for (int t = 0; t < 5; t++) cur = cur * 10 + a[t];
                msk[cur] |= (1 << i - 1);
                // cout << cur << '\n';
            }
            a[j] = (a[j] + 1) % 10;
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                a[j] = (a[j] + 1) % 10, a[j + 1] = (a[j + 1] + 1) % 10;
                int cur = 0;
                for (int t = 0; t < 5; t++) cur = cur * 10 + a[t];
                msk[cur] |= (1 << i - 1);
                // cout << cur << "\n";
            }
            a[j] = (a[j] + 1) % 10, a[j + 1] = (a[j + 1] + 1) % 10;
        }
    }
    int ans = 0;
    for (int i = 0; i < 1e5; i++)
        if (msk[i] == (1 << n) - 1) ans++;
    cout << ans << "\n";
    return 0;
}