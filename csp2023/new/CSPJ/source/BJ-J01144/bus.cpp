#include <bits/stdc++.h>

using namespace std;

struct dat
{
    long long a,u,v;
};

long long mp[10005][10005] = {0},vis[10005][10005] = {0};
long long n,m,k,cnt = 1,ans[10000000] = {0};

void dfs(long long x)
{
    long long o;
    if(x == n)
    {
        ans[cnt++] = o - 1;
        return;
    }
    for(long long i = x;i <= n;i++)
    {
        if(mp[x][i] && !vis[x][i])
        {
            vis[x][i] = 1;
            o += 1;
            dfs(i);
        }
    }
    o = 0;
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    dat lo[10005];
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++)
    {
        cin>>lo[i].u>>lo[i].v>>lo[i].a;
        mp[lo[i].u][lo[i].v] = 1;
    }
    dfs(1);
    sort(ans + 1,ans + cnt + 1);
    int flag = 0;
    for(int i = 1;i <= cnt;i++)
    {
        if(k + ans[i] % k == 0)
        {
            cout<<ans[i];
            flag += 1;
            break;
        }
    }
    if(!flag)
    {
        cout<<-1;
    }
    return 0;
}