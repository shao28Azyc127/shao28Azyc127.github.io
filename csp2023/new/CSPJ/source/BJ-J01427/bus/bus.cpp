#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,c[20],vis[20][25],ans = 1e9;
struct baba
{
    int v,a;
}u[20][25];
void ss(int s,int cnt,int sum)
{
    if(s == n)
    {
        if(cnt % k == 0)
        ans = min(ans,cnt+sum+k-(sum%k));
    }
    for(int i = 1;i <= c[s];i++)
    {
        if(vis[s][i] == 0)
        {
            vis[s][i] = 1;
            ss(u[s][i].v,cnt+1,max(sum,u[s][i].a-cnt));
            vis[s][i] = 0;
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
        int x;
        cin >> x;
        c[x]++;
        cin >> u[x][c[x]].v >> u[x][c[x]].a;
    }
    ss(1,0,0);
    if(ans == 1e9)cout << -1;
    else cout << ans;
    return 0;
}
