#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll M=2e4;
const ll N=1e4;
const ll K=100;
ll n,m,k,dis[N+5][K+5],op,vis[N+5];
struct Node
{
    ll v,a;
};
vector<Node> sz[N+5];
queue<ll> q;
void bfs()
{
    q.push(1);
    dis[1][0]=0;
    while(q.empty()==false)
    {
        ll now=q.front();q.pop();
        if(vis[now]==k) continue;
        vis[now]++;
        for(ll i=0;i<sz[now].size();i++)
        {
            for(ll j=0;j<k;j++)
            {
                if(dis[now][(j-1+k)%k]+1<dis[sz[now][i].v][j])
                    dis[sz[now][i].v][j]=dis[now][(j-1+k)%k]+1,op=1;
            }
            if(op==1) q.push(sz[now][i].v);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=m;i++)
    {
        ll u,v,a;
        scanf("%lld%lld%lld",&u,&v,&a);
        sz[u].push_back({v,a});
        if(a!=0) op=1;
    }
    if(op==0)
    {
        bfs();
        if(dis[n][0]==0x3f) printf("-1");
        else printf("%lld",dis[n][0]);
    }
    else printf("-1");
    return 0;
}
