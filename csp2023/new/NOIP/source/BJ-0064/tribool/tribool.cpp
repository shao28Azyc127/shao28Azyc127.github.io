#include<iostream>
#include<cstring>
using namespace std;
int read()
{
    int n = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') n = n*10+(ch^48), ch = getchar();
    return n*f;
}
char readop()
{
    char ch = getchar();
    while(ch != '+' && ch != '-' && ch != 'T' && ch != 'F' && ch != 'U') ch = getchar();
    return ch;
}
int a[100005];
int val[100005], n, m;
int vis[100005];
void dfs(int p, int k)
{
    if(vis[p] && vis[p] != k) return val[p] = n+3, void();
    if(vis[p]) return val[p] = n+1, void();
    if(val[p]) return;
    vis[p] = k;
    if(a[p] < 0) dfs(-a[p], -k);
    else dfs(a[p], k);
    val[p] = val[abs(a[p])];
    vis[p] = 0;
}
void solve()
{
    memset(vis, 0, sizeof(vis));
    memset(val, 0, sizeof(val));
    n = read(), m = read();
    val[n+1] = n+1;
    val[n+2] = n+2;
    val[n+3] = n+3;
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 1; i <= m; i++)
    {
        char t = readop();
        if(t == '+' || t == '-')
        {
            int u = read(), v = read();
            a[u] = ((t=='+')?1:-1)*a[v];
        }
        else {
            int u = read();
            if(t == 'T') a[u] = n+1;
            if(t == 'F') a[u] = n+2;
            if(t == 'U') a[u] = n+3;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) dfs(i, 1);
    for(int i = 1; i <= n; i++) ans += val[i] == n+3;
    printf("%d\n", ans);
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int C = read(), T = read();
    while(T--) solve();
    return 0;
}