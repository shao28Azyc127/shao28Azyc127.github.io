#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int u;long long t;
    bool operator < (const node &n1) const{return t<n1.t;}
};
int n,minn=INT_MAX;long long a[N],b[N],c[N],h[N];bool vis[N];vector<int> lj[N];
bool chk()
{
    for(int i=1;i<=n;i++) if(!vis[i]) return false;
    return true;
}
void dfs(int u,int t)
{
    if(chk())
    {
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            int tmpt=t,tmph=h[i];
            while(tmph<a[i]) tmph+=max(b[i]+tmpt*c[i],1ll),tmpt++;
            maxx=max(maxx,tmpt);
        }
        minn=min(minn,maxx);
        return;
    }
    for(int i=1;i<=n;i++) if(vis[i]) h[i]+=max(b[i]+t*c[i],1ll);
    for(int i=1;i<=n;i++) if(vis[i]) for(auto e:lj[i]) if(!vis[e]) vis[e]=true,dfs(e,t+1),vis[e]=false;
    for(int i=1;i<=n;i++) if(vis[i]) h[i]-=max(b[i]+t*c[i],1ll);
}
int main()
{
    freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        lj[u].push_back(v);lj[v].push_back(u);
    }
    if(n>20)
    {
        priority_queue<node,vector<node>,less<node> > q;
        vis[1]=true;
        q.push({1,ceil(a[1]/double(b[1]))});
        int i=0;long long maxx=0;
        while(!q.empty())
        {
            node tmp=q.top();q.pop();maxx=max(maxx,i+tmp.t);i++;
            for(int i=1;i<=n;i++) if(vis[i]) for(auto e:lj[tmp.u]) if(!vis[e]) vis[e]=true,q.push({e,ceil(a[e]/double(b[e]))});
        }
        cout<<maxx;
        return 0;
    }
    vis[1]=true;
    dfs(1,1);
    cout<<minn;
    return 0;
}
