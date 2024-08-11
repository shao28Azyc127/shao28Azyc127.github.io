#include <iostream>
#include<queue>
using namespace std;

#define M 100005
long long a[M],b[M],c[M],n;
long long days[M],vis[M];
vector<long long> m[M];
queue<long long> q;
long long ans=-1;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        m[u].push_back(v);
        m[v].push_back(u);
    }
    int u=1;
    for(int i=1;i<n;i++)
    {
        vis[u]=true;
        long long height=0,nowd=i;
        while(height<a[u])
        {
            height+=max(b[u]+nowd*c[u],1ll);
            nowd++;
        }
        ans=max(ans,nowd-1);
        for(int i=0;i<m[u].size();i++)
        {
            if(!vis[m[u][i]])
            {
                u=m[u][i];
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}