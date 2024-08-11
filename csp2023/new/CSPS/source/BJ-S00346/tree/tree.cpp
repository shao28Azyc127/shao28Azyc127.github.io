#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=25;
ll que[N],vis[N],sum[N],undo[N],ans=1e9+10,n,father[N],f[N],dfn[N];
struct nod
{
    ll a,b,c;
}tr[N];
vector<int> G[2*N];
void cal(int x,int fa)
{
    father[x]=fa;
    for(auto to:G[x])  if(to!=fa)  cal(to,x);
}
void dfs(int x,int k)
{
   // cout<<" x "<<x<<endl;
    vis[x]=1,undo[x]=0,dfn[k]=x;//cout<<" k "<<k<<endl;
    if(x==1)  dfn[1]=1;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        //sum[i]+=max(tr[i].b+k?tr[i].c,(ll)1);
        if(vis[i]==0)  flag=0;
    }
    if(k>=n)
    {
        
        ll ret=0;
        for(int day=n;day>=1;day--)
        {
            int p=dfn[day];
            ll sum=(n-day+1)*max((ll)1,tr[p].b+k*tr[p].c);
            ll tmp=n;
            while(sum<tr[p].a)  tmp++,sum+=max((ll)1,tr[p].b+tmp*tr[p].c);
            ret=max(ret,tmp);
        }
        ans=min(ans,ret);
        memset(vis,0,sizeof(vis));
        return ;
    }
    for(auto to:G[x])
    {
        if(to!=father[x])  undo[to]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(undo[i]==1)
        {
            dfs(i,k+1);
            vis[i]=0;
        }
        //cout<<" i "<<i<<endl;
        //for(int i=1;i<=n;i++)  cout<<undo[i]<<" ";
        //cout<<endl;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>tr[i].a>>tr[i].b>>tr[i].c;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cal(1,0);
    dfs(1,1);
    cout<<ans;
    return 0;
}