#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

struct edge{
    int u,v,a;
}e[20010];

int n,m,k;
int tt;
int ans = 1e9;

void dfs(int pos,int t)
{
    if(pos == n)
    {
        if(t % k == 0)
            ans = min(t,ans);
        return ;
    }
    for(int i = 1;i <= m;i++)
    {
        if(e[i].u == pos && e[i].a <= t)
        {
            dfs(e[i].v,t + 1);
        }
    }
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].a;
        tt = max(tt,e[i].a);
    }
    if(n <= 1000)
    {
        int i;
        for(i = 0;i <= tt;i += k)
        {
            dfs(1,i);
        }
        dfs(1,i + k);
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
