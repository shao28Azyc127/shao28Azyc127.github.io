#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=1e5+5;

ll n,ans=9e18,a[N],b[N],c[N],vis[N],tyc=1;
vector<int>g[N];
bool A=1,B=1,C=1,D=1;

ll plant(int x,ll t)
{
    if(c[x]==0)
    {
        int k;
        if(a[x]%b[x]==0)
            k=a[x]/b[x];
        else
            k=a[x]/b[x]+1;
        return t+k;
    }
    if(b[x]+t*c[x]<=1)
        return t+a[x]-1;
    if(c[x]>0)
    {
        ll l=0,r=a[x]/b[x]+1,K=1e9;
        while(l<=r)
        {
            ll k=(l+r)/2;
            ll sum=b[x]*k+c[x]*(t+t+k-1)*k/2;
            if(sum>=a[x])
            {
                K=k;
                r=k-1;
            }
            else
                l=k+1;
        }
        return t+K-1;
    }
    else
    {
        ll tmax=(1-b[x])/c[x];
        ll kmax=tmax-t+1    ;
        ll sum=b[x]*kmax+c[x]*(t+t+kmax-1)*kmax/2;
        if(sum<a[x])
            return tmax+a[x]-sum;
        ll l=0,r=kmax,K=1e9;
        while(l<=r)
        {
            ll k=(l+r)/2;
            if(b[x]*k+c[x]*(t+t+k-1)*k/2>=a[x])
            {
                K=k;
                r=k-1;
            }
            else
                l=k+1;
        }
        return t+K-1;
    }
}

void dfs(ll Max,int step)
{
    if(Max>=ans)
        return;
    if(step==n)
    {
        ans=min(ans,Max);
        return;
    }
    for(int x=1;x<=n;x++)
        if(vis[x])
            for(int i=0;i<g[x].size();i++)
                if(!vis[g[x][i]])
                {
                    int t=g[x][i];
                    vis[t]=1;
                    dfs(max(Max,plant(t,step+1)),step+1);
                    vis[t]=0;
                }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]!=0)
            A=0;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u!=i||v!=i+1)
            B=0;
        if(u!=1)
            D=0;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n<=20)
    {
        vis[1]=1;
        dfs(plant(1,1),1);
        cout<<ans<<endl;
    }
    else
    {
        ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,plant(i,i));
        cout<<ans<<endl;
    }
    return 0;
}

