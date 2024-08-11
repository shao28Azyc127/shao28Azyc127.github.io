#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
    x=0;char c=getchar();int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;
}
template<typename T,typename ...Args>
void read(T &x,Args &...rest){read(x);read(rest...);}

const int N=1e4+5;
typedef pair<int,int> pii;
int n,m,k;
struct edge{int v,nx,a;}e[2*N];
int head[N];

int dis[N];
bool vis[N];
void dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    memset(dis,0x7f,sizeof(dis));
    dis[1]=0;
    Q.push(make_pair(0,1));
    while(!Q.empty()){
        int u=Q.top().second;
        Q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];~i;i=e[i].nx){
            int v=e[i].v;
            if(dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                Q.push(make_pair(dis[v],v));
            }
        }
    }
}
bool subtask(){for(int i=1;i<=m;i++)if(e[i].a)return 0;return 1;}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    read(n,m,k);
    memset(head,-1,sizeof(head));
    for(int i=1,u,v,a;i<=m;i++){
        read(u,v,a);
        e[i]=(edge){v,head[u],a};
        head[u]=i;
    }
    if(k==1&&subtask()){
        dijkstra();
        printf("%d",dis[n]==2139062143?-1:dis[n]);
    }
    else printf("-1");
    return 0;
}
