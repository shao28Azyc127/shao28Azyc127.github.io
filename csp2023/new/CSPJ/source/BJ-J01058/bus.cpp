#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
struct node
{
    int v,a;
};
vector<node> mp[N];
ll n,m,k,minn=9e18;
void dfs(ll t,ll now,ll wkt)
{
    if((t+wkt)>=minn)
    {
        return;
    }
    if(now==n)
    {
        if(wkt%k!=0||t%k!=0)
        {
            return;
        }
        minn=min(minn,t+wkt);
        return;
    }
    for(ll i=0;i<mp[now].size();i++)
    {
        if(mp[now][i].a>t)
        {
            dfs(ceil(mp[now][i].a/double(k))*k,mp[now][i].v,wkt+1);
        }
        else
        {
            dfs(t,mp[now][i].v,wkt+1);
        }
    }
}
void work()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,vt,at;
        cin>>u>>vt>>at;
        mp[u].push_back({vt,at});
    }
    if(n<=20)
    {
        dfs(0,1,0);
    }
    if(minn!=9e18)
    {
        cout<<minn;
        return;
    }
    cout<<-1;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    work();
    return 0;
}