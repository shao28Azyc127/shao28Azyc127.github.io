#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e4+10;
int n,m,k,cnt;
int head[maxn],dis[maxn];
bool vis[maxn];
queue<int>q;
struct node{
    int v,nxt;
}e[maxn<<2];
inline void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
bool flag=true;
inline void input(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        add(x,y);
        if(z!=0)flag=false;
    }
}
inline void bfs(){
    for(int i=1;i<=n;i++)dis[i]=1e18;
    vis[1]=true;
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        // printf("%lld\n",u);
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(vis[v])continue;
            vis[v]=true;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    int p=dis[n]/k;
    if(dis[n]%k)++p;
    printf("%lld\n",p*k);
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    input();
    if(flag)bfs();
    if(!flag)printf("-1\n");
    return 0;
}