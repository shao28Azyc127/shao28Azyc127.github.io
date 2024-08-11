#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 1e5 + 5, M = 2 * N;

int n, x, y, e[M], h[N], nxt[M], vis[N], num = 1, id, ans = 1e9;
ll a[N], b[N], c[N];

void add(int x, int y)
{
    //printf("%d %d\n", x, y);
    e[++id] = y, nxt[id] = h[x], h[x] = id;
    //printf("%d\n", e[id]);
}

void dfs(int x, int day)
{
    //printf("%d %d %d\n", x, num, day);
    num++;
    if (day > ans) return;
    if (num == n + 1) ans = min(ans, day);
    for (int i = h[x]; i; i = nxt[i])
    {
        int nx = e[i];
        if (vis[nx]) return;
        vis[nx] = 1;
        ll tmp = 0;
        int cnt = num;
        while (tmp < a[nx])
        {
            tmp += max(b[nx] + (cnt + 1) * c[nx], (ll)1), cnt++;
            if (c[nx] < 0 && b[nx] + (cnt + 1) * c[nx] <= 1)
            {
                cnt += a[nx] - tmp;
                break;
            }
        }
        //printf("%d %d %d\n", tmp, cnt, nx);
        dfs(nx, max(num + 1, max(day, cnt)));
        vis[nx] = 0;
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    //for (int i = 1; i <= n; i++) printf("%d %d %d\n", a[i], b[i], c[i]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    //for (int i = 1; i <= id; i++) printf("%d\n", e[i]);
    ll tmp = 0;
    int cnt = 1;
    while (tmp < a[1])
    {
        tmp += max(b[1] + (cnt + 1) * c[1], (ll)1), cnt++;
        if (c[1] < 0 && b[1] + (cnt + 1) * c[1] <= 1)
        {
            cnt += a[1] - tmp;
            break;
        }
    }
    dfs(1, cnt);
    printf("%d", ans);
    return 0;
}