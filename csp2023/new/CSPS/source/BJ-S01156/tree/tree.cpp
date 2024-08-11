#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],len[N];
bool f[N],vis[N],g[N];
vector<int> v[N];
int ans;
int n;
void dfs(int x, int s)
{
//    cout<<x<<endl;
    bool flag=true;
    if(s==n)
    {
        int t=2000;
        while(t--)
        {
            flag=true,s++;
            for(int i=1; i<=n; i++)
                if(len[i]<a[i]) flag=false;
            if(flag)
            {
                ans=min(ans,s);
                break;
            }
            for(int i=1; i<=n; i++)
                len[x]+=max(b[i]+s*c[i],1);
        }
        return;
    }
    vis[x]=true;
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(vis[x]) len[x]+=max(b[i]+s*c[i],1);
    for(int i=0; i<v[x].size(); i++)
        if(!f[v[x][i]]) f[v[x][i]]=true,q.push(v[x][i]);
    for(int i=1; i<=n; i++)
        if(f[i] && !vis[i]) dfs(i,s+1);
    for(int i=1; i<=n; i++)
        if(vis[x]) len[x]-=max(b[i]+s*c[i],1);
    while(!q.empty())
        f[q.front()]=false,q.pop();
    vis[x]=false;
}
signed main(){
//    ios::sync_with_stdio(false);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans=1e9;
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}

