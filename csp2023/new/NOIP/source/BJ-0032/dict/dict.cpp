#include <iostream>
#include <algorithm>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc() (p1 == p2 && ((p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin)), p1 == p2) ? EOF : *p1++)
    template <typename T>
    inline void Read(T &x)
    {
        x = 0; bool sgn = 0; char ch = gc();
        while (ch < '0' || ch > '9') {if (ch == '-') sgn = 1; ch = gc();}
        while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        if (sgn) x = -x;
    }
}

using FastIO::Read;
using namespace std;

const int MAXN = 3010, MAXM = 9e6 + 10;

int n, m;
char s[MAXN][MAXN];

int tr[MAXM][26], cnt[MAXM], tot;
int mn1[MAXM], mn2[MAXM];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i] + 1;
    mn1[0] = mn2[0] = 50;
    for (int i = 1; i <= n; i++)
    {
        sort(s[i] + 1, s[i] + m + 1);
        int cur = 0;
        for (int j = m; j >= 1; j--)
        {
            int c = s[i][j] - 'a';
            if (!tr[cur][c]) tr[cur][c] = ++tot, mn1[tot] = mn2[tot] = 50;
            if (mn1[cur] > c) mn2[cur] = mn1[cur], mn1[cur] = c;
            else if (c > mn1[cur] && c < mn2[cur]) mn2[cur] = c;
            cur = tr[cur][c], cnt[cur]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = 1;
        int cur = 0;
        for (int j = m; j >= 1; j--)
        {
            int c = s[i][j] - 'a';
            cur = tr[cur][c], cnt[cur]--;
        }
        cur = 0;
        for (int j = 1; j <= m; j++)
        {
            int c = s[i][j] - 'a';
            if (mn1[cur] < c && cnt[tr[cur][mn1[cur]]]) flag = 0;
            else if (mn2[cur] < c && cnt[tr[cur][mn2[cur]]]) flag = 0;
            if (!flag) break;
            if (!tr[cur][c]) break;
            cur = tr[cur][c];
        }
        if (flag) cout << "1";
        else cout << "0";
        cur = 0;
        for (int j = m; j >= 1; j--)
        {
            int c = s[i][j] - 'a';
            cur = tr[cur][c], cnt[cur]++;
        }
    }
    return 0;
}