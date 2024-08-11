#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+10;
int n,cnt,tot;
bool flag=true;
int head[maxn],dfn[maxn];
bool vis[maxn];
struct node1{
    ll h,x,y;
}a[maxn];
struct node2{
    int v,nxt;
}e[maxn<<1];
inline void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
struct vertex{
    ll ds;
    int op;
    bool operator<(const vertex& nx)const{return ds<nx.ds;}
};
inline void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i].h,&a[i].x,&a[i].y);
        if(a[i].y!=0)flag=false;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
}
priority_queue<vertex>q;
inline void Dijkstra(){
    q.push((vertex){0,1});
    vis[1]=true;
    while(!q.empty()){
        int x=q.top().op;
        q.pop();
        dfn[++tot]=x;
        for(int i=head[x];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis[v]){
                vis[v]=true;
                ll r=a[v].h/a[v].x;
                if(a[v].h%a[v].x)++r;
                q.push((vertex){r,v});
            }
        }
    }
}
inline void solve1(){
    ll mx=tot;
    for(int i=1;i<=tot;i++){
        int v=dfn[i];
        ll t=tot-i+1;
        if(t*a[v].x>=a[v].h)continue;
        ll d=a[v].h-t*a[v].x;
        ll p=d/a[v].x;
        if(d%a[v].x)++p;
        mx=max(mx,tot+p);
    }
    printf("%lld\n",mx);
}
// inline void solve2(){
//     ll mx=tot;
//     for(int i=1;i<=tot;i++){
//         int v=dfn[i];
//         ll t=tot-i+1;
//         if(a[v].y>=0){
//             int p=(a[v].x+i*)
//         }
//         else{

//         }
//     }
// }
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    input();
    Dijkstra();
    if(flag)solve1();
    // else solve2();
    return 0;
}