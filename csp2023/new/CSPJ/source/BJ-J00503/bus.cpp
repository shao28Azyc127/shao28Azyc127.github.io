#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
struct Edge{int next,to,w;}edge[N];
int cnt,head[N];
inline void init(){cnt=0;memset(head,-1,sizeof(head));}
inline void add(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
struct node{int dis,pos;};
inline bool operator<(node a,node b){
    return a.dis>b.dis;
}
priority_queue<node>q;
int n,m,k,dis[N],vis[N];
inline void dij(){
    dis[1]=0;
    q.push((node){0,1});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int x=tmp.pos;
        if(vis[x]){continue;}
        vis[x]=1;
        for(int i=head[x];~i;i=edge[i].next){
            int v=edge[i].to;
            if(dis[v]>dis[x]+edge[i].w){
                dis[v]=dis[x]+edge[i].w;
                q.push((node){dis[v],v});
            }
        }
    }

}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdin);
    init();
    memset(dis,0x7f,sizeof(dis));
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        add(u,v,1);
    }
    dij();
    int tmp=k,tim=0;
    while(1){
        if(k>=dis[n]){cout<<k;return 0;}
        tim++;
        k=tmp*tim;
    }
    return 0;
}
