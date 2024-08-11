#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5+5;
#define int long long
struct Node
{
    int v,w;
};
queue <int> q;
vector <Node> e[N];
int n,m,k;
bool st[N];
int dist[N];
int x[N],y[N],z[N];
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[1] = 0;
    q.push(1);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        st[u] = 0;
        for(auto x:e[u])
        {
            int v = x.v;
            if(dist[v]>dist[u]+1)
            {
                dist[v] = dist[u]+1;
                if(!st[v])
                {
                    q.push(v);
                    st[v] = 1;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
        e[x[i]].push_back({y[i],z[i]});
    }
    if(k==1) cout << spfa() << endl;
    else cout << -1 << endl;
    return 0;
}
