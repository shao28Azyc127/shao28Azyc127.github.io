#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//14:40 AC T1

struct edge
{
    int v, w, nxt;
}e[200010];

int h[100010], cnt;

void addedge(int u, int v, int w)
{
    cnt++;
    e[cnt].v = v, e[cnt].w = w, e[cnt].nxt = h[u];
    h[u] = cnt;
    return;
}

int n;
int lk[10][10];

int vis[1000010];//看每个数的出现次数

int s[10];

int tox()
{
    int x = 0;
    for(int i = 1;i <= 5;i++)
    {
        x = x * 10 + s[i];
    }
    return x;
}

signed main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    srand(time(0) + 2327);
    n = read();
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            lk[i][j] = read();
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            s[j] = lk[i][j];
        }
        for(int j = 1;j <= 5;j++)
        {
            for(int k = 1;k <= 9;k++)
            {
                s[j] += k;
                s[j] %= 10;
                vis[tox()]++;
                s[j] -= k;
                s[j] = (s[j] + 10) % 10;
            }
        }
        for(int j = 1;j <= 4;j++)
        {
            for(int k = 1;k <= 9;k++)
            {
                s[j] += k;
                s[j] %= 10;
                s[j + 1] += k;
                s[j + 1] %= 10;
                vis[tox()]++;
                s[j] -= k;
                s[j] = (s[j] + 10) % 10;
                s[j + 1] -= k;
                s[j + 1] = (s[j + 1] + 10) % 10;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= 99999;i++)
    {
        if(vis[i] == n)
        {
            ans++;
            //cout << i << "\n";
        }
    }
    cout << ans;
    return 0;
}