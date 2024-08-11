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

const int MAXN = 2e6 + 10;

int n;
char s[MAXN];
ll ans;

int f[MAXN][26], g[MAXN];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s + 1;
    for (int i = 0; i < 26; i++) f[n + 1][i] = f[n][i] = n + 1;
    f[n][s[n] - 'a'] = n, g[n] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (f[i + 1][s[i] - 'a'] == n + 1)
        {
            for (int j = 0; j < 26; j++) f[i][j] = n + 1;
            f[i][s[i] - 'a'] = i, g[i] = 0;
            continue;
        }
        int nxt = f[i + 1][s[i] - 'a'] + 1;
        for (int j = 0; j < 26; j++) f[i][j] = f[nxt][j];
        f[i][s[i] - 'a'] = i, g[i] = g[nxt] + 1;
        ans += g[i];
    }
    cout << ans << "\n";
    return 0;
}