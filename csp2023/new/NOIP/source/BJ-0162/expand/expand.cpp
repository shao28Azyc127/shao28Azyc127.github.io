#include <bits/stdc++.h>

using namespace std;
const int N = 2010;
const int INF = 2e9;

int f[2][N], id, n, m, q, a[N], b[N], a2[N], b2[N], mn[N][21], mx[N][21], len[N];

int read()
{
    int x = 0, t = 1; char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') t = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * t;
}

void init(int a[N])
{
    for(int i = 1; i <= m; i++) mn[i][0] = mx[i][0] = a[i];
    mn[m + 1][0] = INF, mx[m + 1][0] = -INF;
    for(int j = 1; j <= 20; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= m + 1; i++)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 2; i <= m + 1; i++) len[i] = len[i >> 1] + 1;
}

int querymn(int l, int r)
{
    if(l > r) return INF;
    int t = len[r - l + 1];
    return min(mn[l][t], mn[r - (1 << t) + 1][t]);
}

int querymx(int l, int r)
{
    if(l > r) return -INF;
    int t = len[r - l + 1];
    return max(mx[l][t], mx[r - (1 << t) + 1][t]);
}

void solve(int a[N], int b[N])
{
    init(b);
    int flag = 0;
    memset(f, 0, sizeof(f));
    if(a[1] < b[1]) f[0][1] = 1, f[0][2] = -1;
    for(int i = 0; i < n; i++)
    {
        memset(f[(i + 1) & 1], 0, sizeof(f[(i + 1) & 1]));
        for(int j = 1; j <= m; j++)
        {
            f[i & 1][j] += f[i & 1][j - 1];
            if(f[i & 1][j])
            {
                if(a[i + 1] < b[j]) f[(i + 1) & 1][j]++, f[(i + 1) & 1][j + 1]--;
                int l = j + 1, r = m + 1;
                while(l < r)
                {
                    int mid = l + r >> 1;
                    if(a[i + 1] >= querymn(j + 1, mid)) r = mid;
                    else l = mid + 1;
                }
                f[(i + 1) & 1][j + 1]++, f[(i + 1) & 1][l]--;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        f[n & 1][i] += f[n & 1][i - 1];
    }
    flag |= f[n & 1][m] > 0;
    memset(f, 0, sizeof(f));
    if(a[1] > b[1]) f[0][1] = 1, f[0][2] = -1;
    for(int i = 0; i < n; i++)
    {
        memset(f[(i + 1) & 1], 0, sizeof(f[(i + 1) & 1]));
        for(int j = 1; j <= m; j++)
        {
            f[i & 1][j] += f[i & 1][j - 1];
            if(f[i & 1][j])
            {
                if(a[i + 1] > b[j]) f[(i + 1) & 1][j]++, f[(i + 1) & 1][j + 1]--;
                int l = j + 1, r = m + 1;
                while(l < r)
                {
                    int mid = l + r >> 1;
                    if(a[i + 1] <= querymx(j + 1, mid)) r = mid;
                    else l = mid + 1;
                }
                f[(i + 1) & 1][j + 1]++, f[(i + 1) & 1][l]--;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        f[n & 1][i] += f[n & 1][i - 1];
    }
    flag |= f[n & 1][m] > 0;
    putchar('0' + flag);
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    id = read(), n = read(), m = read(), q = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for(int j = 1; j <= m; j++)
    {
        b[j] = read();
    }
    solve(a, b);
    while(q--)
    {
        memcpy(a2, a, sizeof(a));
        memcpy(b2, b, sizeof(b));
        int cntx = read(), cnty = read(), pos, v;
        while(cntx--)
        {
            pos = read(), v = read();
            a2[pos] = v;
        }
        while(cnty--)
        {
            pos = read(), v = read();
            b2[pos] = v;
        }
        solve(a2, b2);
    }
    return 0;
}
