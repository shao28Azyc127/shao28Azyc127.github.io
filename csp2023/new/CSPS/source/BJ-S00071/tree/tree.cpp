#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,ans=0;
long long a[100005],b[100005],c[10005],sum[100005];
bool vis[10005][10005];

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(sum,0,sizeof(sum));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vis[u][v]=vis[v][u]=true;

    }
    ll t=1;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(sum[i]<a[i])
        {
            sum[i]+=max(b[i]+c[i]*j,t);
            j++;
        }
        j--;
        ans=max(ans,j*1ll);
    }
    cout<<ans<<endl;
    return 0;
}
