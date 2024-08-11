#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
struct edge{
    int v,w,next;
}e[N];
int head[N],cur;
void add(int u,int v,int w){
    e[++cur].next=head[u];
    e[cur].v=v;
    e[cur].w=w;
    head[u]=cur;
}
struct Node{
    int v,t,ceng;
};
int n,m,k;
int maxx=0;
int vis[20005],dis[205][20005],U[20005],V[20005],W[20005];
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;++i){
        cin>>U[i]>>V[i]>>W[i];
        add(U[i],V[i],W[i]);
        maxx=max(maxx,W[i]);
    }
    int ans=2e9;
    for(int j=0;j<=maxx;++j){
        memset(dis,0x3f,sizeof dis);
        queue<Node> q;
        q.push({1,j,j%k});
        dis[j%k][1]=j;
        while(!q.empty()){
            Node top=q.front();
            q.pop();
            for(int i=head[top.v];i;i=e[i].next){
                if(e[i].w<=q.front().t){
                    q.push({e[i].v,top.t+1,(top.t+1)%k});
                    dis[(top.t+1)%k][e[i].v]=min(dis[top.t%k][top.v]+1,dis[(top.t+1)%k][e[i].v]);

                }
            }
        }
        ans=min(ans,dis[0][n]);
        if(clock()/CLOCKS_PER_SEC>=0.9){
            break;
        }
    }
    if(ans==0x3f3f3f3f) cout<<"-1";
    else cout<<ans;
    return 0;
}
