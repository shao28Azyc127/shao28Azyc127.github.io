#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10005],v[10005],a[10005];
int cnt[10005];
int ans;
int time1;
struct Point
{
    int vi;
    int ai;
}ui[10005][10005];

void dfs(int i)
{
    if (time1%k==0 && v[i]==n)
    {
        ans=min(ans,time1);
    }
    for (int j=1;j<=cnt[i];j++)
    {
        if (ui[i][j].ai<=time1)
        {
            time1+=1;
            dfs(ui[i][j].vi);
            time1-=1;
        }

    }
    return;

}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>u[i]>>v[i]>>a[i];
        ui[u[i]][++cnt[u[i]]].vi=v[i];
        ui[u[i]][++cnt[u[i]]].ai==a[i];
    }
    for (int i=0;i<10000;i+=3)
    {
        time1=i;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}