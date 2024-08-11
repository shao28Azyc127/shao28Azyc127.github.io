#include<iostream>
#include<cstring>
#include<unordered_map>
#include<array>
#include<cassert>
#include<algorithm>
using namespace std;
int read()
{
    int n = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') n = n*10+(ch^48), ch = getchar();
    return n*f;
}
typedef long long ll;
int l[100005], r[100005], v[100005];
ll jr[1005][1005];
ll dp[1005][1005];
void solve1()
{
    memset(dp, 0, sizeof(dp));
    memset(jr, 0, sizeof(jr));
    int n = read(), m = read(), k = read(), d = read();
    for(int i = 1; i <= m; i++)
    {
        r[i] = read();
        l[i] = read();
        v[i] = read();
        jr[r[i]][l[i]] += v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i && j <= k; j++)
        {
            jr[i][j] += jr[i][j-1];
        }
    }
    for(int i = 1; i <= n+1; i++)
    {
        for(int j = 1; j <= i && j <= k; j++)
        {
            dp[i][j] = dp[i-1][j-1]+jr[i][j]-d;
        }
        for(int j = 0; j < i && j <= k; j++) dp[i][0] = max(dp[i][0], dp[i-1][j]);
    }
    printf("%lld\n", dp[n+1][0]);
}
ll f[100005][2];
void solve2()
{
    memset(f, 0, sizeof(f));
    int n = read(), m = read(), k = read(), d = read();
    for(int i = 1; i <= m; i++)
    {
        r[i] = read();
        l[i] = read();
        v[i] = read();
    }
    r[0] = -1;
    for(int i = 1; i <= m+1; i++)
    {
        if(r[i]-l[i] == r[i-1] && l[i]+l[i-1] > k) f[i][1] = f[i-1][0]-l[i]*d+v[i];
        else f[i][1] = max(f[i-1][0], f[i-1][1])-l[i]*d+v[i];
        
        f[i][0] = max(f[i-1][0], f[i-1][1]);
    }
    printf("%lld\n", f[m+1][0]);
}
namespace solve3{
struct qry {
    int l, r, v;
    bool operator<(qry o) const
    {
        if(r != o.r) return r < o.r;
        return l < o.l;
    }
} q[100005];
ll dp[2][105];
ll jr[100005][105];
int pre[100005];
void solve3()
{
    memset(jr, 0, sizeof(jr));
    int n = read(), m = read(), k = read(), d = read();
    for(int i = 1; i <= m; i++)
    {
        q[i].r = read();
        q[i].l = read();
        q[i].v = read();
        if(q[i].l > k) i--, m--;
    }
    sort(q+1, q+m+1);
    q[0].r = -1e9;
    for(int i = 1; i <= m; i++)
    {
        if(q[i].r == q[i-1].r) pre[i] = pre[i-1];
        else pre[i] = i;
        jr[pre[i]][q[i].l] += q[i].v;
    }
    for(int i = 1; i <= m; i++)
    {
        if(pre[i] != i) continue;
        for(int j = 1; j <= k; j++) jr[i][j] += jr[i][j-1];
    }
    ll mx = 0;
    int cur = 0;
    int l = 0;
    for(int i = 1; i <= m; i++)
    {
        if(pre[i] != i) continue;
        if(q[i].r-q[i].l-q[i-1].r > k+1)
        {
            cur = q[i].r-1;
            l ^= 1;
            for(int i = 0; i <= k; i++)
            {
                dp[l][i] = mx-i*d;
            }
        }
        for(cur++; cur <= q[i].r; cur++)
        {
            l ^= 1;
            memset(dp[l], 0, sizeof(dp[l]));
            dp[l][0] = mx;
            for(int j = 1; j <= k; j++)
            {
                dp[l][j] = dp[l^1][j-1]-d+(cur==q[i].r?jr[i][j]:0);
                mx = max(mx, dp[l][j]);
            }
        }
        cur--;
    }
    printf("%lld\n", mx);
}
}
int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int C, T;
    C = read(), T = read();
    if(C <= 9) while(T--) solve1();
    else if(C >= 17) while(T--) solve2();
    else while(T--) solve3::solve3();
    return 0;
}