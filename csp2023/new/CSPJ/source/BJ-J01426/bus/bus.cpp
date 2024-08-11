#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;
struct node
{
    vector<int> v,w;
}a[maxn];
queue<int> q,t;
int ans=0;
int n,m,k;
int st;
bool vis[maxn];
void bfs(int s)
{
    q.push(1);
    t.push(s);
    while(!q.empty())
    {
        int p=q.front(),d=t.front();
        q.pop(),t.pop();
        vis[p]=1;
        if(p==n&&d%k==0)
        {
            ans=d;
            return;
        }
        if(clock()-st>=920000)
        {
            cout<<-1<<endl;
            exit(0);
        }
        for(int i=0;i<a[p].v.size();++i)
        {
            int v=a[p].v[i];
            if(!vis[v]&&d>=a[p].w[i])
            {
                q.push(v),t.push(d+1);
            }
        }
    }
}void bfs1(int s)
{
    q.push(1);
    t.push(s);
    while(!q.empty())
    {
        int p=q.front(),d=t.front();
        q.pop(),t.pop();
        if(d==s+n+1)return;
        if(p==n&&d%k==0)
        {
            ans=d;
            return;
        }
        if(clock()-st>=920000)
        {
            cout<<-1<<endl;
            exit(0);
        }
        for(int i=0;i<a[p].v.size();++i)
        {
            int v=a[p].v[i];
            if(d>=a[p].w[i])
            {
                q.push(v),t.push(d+1);
            }
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    st=clock();
    cin>>n>>m>>k;
    if(n<=10)
    {
        for(int i=1;i<=m;++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            a[u].v.push_back(v);
            a[u].w.push_back(w);
        }
        for(int i=0;;i+=k)
        {
            bfs1(i);
            if(ans)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].v.push_back(v);
        a[u].w.push_back(w);
    }
    for(int i=0;;i+=k)
    {
        for(int j=1;j<=n;++j)
        {
            vis[j]=0;
            if(clock()-st>=920000)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        bfs(i);
        if(ans)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}
