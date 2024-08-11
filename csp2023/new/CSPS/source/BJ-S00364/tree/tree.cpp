#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=s*10+c-'0';c=getchar();}
    return s*f;
}
struct Egde{int next,to;}edge[2*N];
int cnt,head[2*N];
inline void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
inline void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
struct pos{int a,b,c;}po[N];
int n;
struct Tree{
    int fa,son,siz,tall;
    bool vis;
}tree[N];
inline void dfs1(int u,int f){
    tree[u].fa=f;
    tree[u].siz=1;
    int ma=-1;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==tree[u].fa){continue;}
        dfs1(v,u);
        tree[u].siz+=tree[v].siz;
        if(ma<tree[v].siz){
            ma=tree[v].siz;
            tree[u].son=v;
        }
    }
}
int tim;
inline void grow(int x){
    for(int i=1;i<=n;i++){
        if(tree[i].vis){tree[i].tall+=(max(1ll,po[i].b+po[i].c*x));}
    }
}
inline void dfs2(int u){
    if(!tree[u].son){tree[u].vis=1;return;}
    else tree[tree[u].son].vis=1;
    grow(++tim);
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==tree[i].son||v==tree[i].fa){continue;}
        dfs2(v);
    }
}
inline bool check(int x){
    for(int i=1;i<=n;i++){
        if(tree[i].tall<po[i].a){return 0;}
    }
    return 1;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();init();
    for(int i=1;i<=n;i++){
        po[i].a=read();
        po[i].b=read();
        po[i].c=read();
    }
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);dfs2(1);
    while(!check(tim)){tim++;grow(tim);}
    cout<<tim;
    return 0;
}
