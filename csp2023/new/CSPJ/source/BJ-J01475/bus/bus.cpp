#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[20010],u[20010],v[20010];
int ru,minans=INT_MAX,ans=INT_MAX;
int mp[20010][20010];
int vis[20010];
void dfs(int now,int time)
{
    if (vis[now])
    {
        return ;
    }
    //cout<<"nowI'min"<<now<<",time"<<time<<'\n';
    if (now == n)
    {
        if (time % k || ru % k)
        {
            return ;
        }
        else
        {
            ans = min(ans,time);
        }
    }
    for (int i = 1;i <= n;i++)
    {
        //cout<<"mp["<<now<<"]["<<i<<"]="<<mp[now][i]<<endl;
        if (i == now)
        {
            continue;
        }
        if (mp[now][i] != -1 && time >= mp[now][i])
        {
            vis[now] = 1;
            dfs(i,time+1);
            vis[now] = 0;
        }
    }
    return ;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(mp,-1,sizeof(mp));
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&a[i]);
        mp[u[i]][v[i]] = a[i];
        //cout<<"mp["<<u[i]<<"]["<<v[i]<<"]="<<mp[u[i]][v[i]]<<endl;
        if (v[i] == n)
        {
            minans = min(a[i],minans);
        }
    }
    ru = minans;
    while (ru <= minans+500)
    {
        dfs(1,ru);
        ru++;
    }
    if (ans != INT_MAX)
    {
        cout<<ans;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}