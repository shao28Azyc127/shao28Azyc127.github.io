#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[100005],b[100005],c[100005],u,v,ans=minn,s[100005];
vector<long long>g[100005];
bool vis[100005];
bool chk()
{
    for(int i=1;i<=n;++i)
        if(!vis[i] || s[i]<a[i])
            return false;
    return true;
}
void dfs(long long p,long long x)
{
    if(chk())
    {
        ans=min(ans,p);
        return ;
    }
    bool flag=false;
    for(int i=0;i<g[x].size();++i)
    {
        if(!vis[g[x][i]])
        {
            vis[g[x][i]]=true;
            s[g[x][i]]=p;
            dfs(p+1,g[x][i]);
            vis[g[x][i]]=false;
            s[g[x][i]]=0;
        }
    }

}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;++i)
    {
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    s[1]=max(b[1]+c[1],1);
    dfs(1,1);
    return 0;
}
