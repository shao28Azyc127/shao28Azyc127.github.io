#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 1005;

int c, t, n, m, k, d;
ll sum[N], ans;

struct node{
    int x, y;
    ll v;
    bool operator < (const node &a) const
    {
        return x < a.x;
    }
}a[N];

void dfs(int x, int nowday, int nownum, ll nowans)
{
    if (x > n)
    {
        while (nownum <= m && x > a[nownum].x)
        {
            if (nowday >= a[nownum].y) nowans += a[nownum].v;
            nownum++;
        }
        ans = max(ans, nowans);
        return;
    }
    if (nowans + sum[nownum] < ans) return;
    while (nownum <= m && x > a[nownum].x)
    {
        if (nowday >= a[nownum].y) nowans += a[nownum].v;
        nownum++;
    }
    if (nowday < k) dfs(x + 1, nowday + 1, nownum, nowans - 1);
    dfs(x + 1, 0, nownum, nowans);
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        ans = 0;
        memset(sum, 0, sizeof sum);
        scanf("%d%d%d%d", &n, &m, &k, &d);
        for (int i = 1; i <= m; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
        sort(a + 1, a + m + 1);
        for (int i = m; i >= 1; i--) sum[i] = sum[i + 1] + a[i].v;
        dfs(1, 0, 1, 0);
        printf("%lld", ans);
    }
    return 0;
}