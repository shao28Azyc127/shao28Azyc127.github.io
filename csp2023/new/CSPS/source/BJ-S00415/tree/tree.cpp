#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int n, u, v;
long long a[N], b[N], c[N], ans = 2e18;
bool cnt[N];
vector <int> q, e[N];

inline void dfs(int x, int sum, long long mn)
{
    if(cnt[x] || mn > ans)
        return ;
    cnt[x] = true;
    register long long tot = mn;
    register long long tmp = 0ll, i = sum - 1;
    while(tmp < a[i])
    {
        i++;
        tmp += max(1ll, b[x] + c[x] * i);
    }
    if(i == sum - 1)
        i++;
    mn = max(mn, i);
    if(sum >= n)
    {
        ans = min(ans, mn);
        return ;
    }
    for(register int i = 0;i <= e[x].size();i++)
        if(!cnt[e[x][i]])
            q.push_back(e[x][i]);
    for(register int i = 0;i < q.size();i++)
        if(!cnt[q[i]])
            dfs(q[i], sum+1, mn);
    cnt[x] = false;
    return ;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for(register int i = 1;i <= n;i++)
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
    for(register int i = 1;i < n;i++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1ll, 1ll, 0ll);
    printf("%lld", ans);
    return 0;
}
