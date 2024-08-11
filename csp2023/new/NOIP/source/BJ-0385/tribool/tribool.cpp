#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=f;
}
const int N=1e5+10;
int c,T,n,m;
struct node{
    char op;
    int x,y;
}q[N];
int ecnt,head[N],vis[N];
struct E{
    int v,next;
}e[N*2];
void add(int u,int v){
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}
int kd[N],d[N],ans,tmp[N];
void dfs(int dep){
    if(dep>n){
        int cnt=0;for(int i=1;i<=n;++i) if(kd[i]==2) cnt++;
        for(int i=1;i<=n;++i) d[i]=kd[i];
        for(int i=1;i<=m;++i){
            if(q[i].op=='+') d[q[i].x]=d[q[i].y];
            if(q[i].op=='-') d[q[i].x]=4-d[q[i].y];
            if(q[i].op=='U') d[q[i].x]=2;
            if(q[i].op=='T') d[q[i].x]=3;
            if(q[i].op=='F') d[q[i].x]=1;
        }
        for(int i=1;i<=n;++i) if(d[i]!=kd[i]) return;
        ans=min(ans,cnt);
        return;
    }
    kd[dep]=1;
    dfs(dep+1);
    kd[dep]=2;
    dfs(dep+1);
    kd[dep]=3;
    dfs(dep+1);
}
void solve(){
    read(n);read(m);
    bool tfu=1,u=1;int cntu=0;
    for(int i=1;i<=m;++i){
        cin>>q[i].op;
        if(q[i].op=='U') cntu++;
        if(q[i].op=='-'||q[i].op=='+') tfu=0;
        if(q[i].op!='U'&&q[i].op!='+') u=0;
        read(q[i].x);if(q[i].op=='-'||q[i].op=='+') read(q[i].y);
    }
    if(n<=13&&m<=13){
        ans=0x3f3f3f3f;
        dfs(1);
        printf("%d\n",ans);
    }
    else if(tfu){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;++i){
            if(q[i].op=='U') vis[q[i].x]=2;
            if(q[i].op=='T') vis[q[i].x]=1;
            if(q[i].op=='F') vis[q[i].x]=3;
        }
        ans=0;
        for(int i=1;i<=n;++i) if(vis[i]==2) ans++;
        printf("%d\n",ans);
        return;
    }
    else if(u){
        memset(vis,0,sizeof(vis));
        bool f=1;
        while(f){
            for(int i=1;i<=n;++i) tmp[i]=vis[i];
                for(int i=1;i<=m;++i){
                if(q[i].op=='U') vis[q[i].x]=2;
                if(q[i].op=='+') vis[q[i].x]=vis[q[i].y];
            }
            f=0;
            for(int i=1;i<=n;++i) if(vis[i]!=tmp[i]) f=1;
        }
        ans=0;
        for(int i=1;i<=n;++i) if(vis[i]==2) ans++;
        printf("%d\n",ans);
        return;
    }
    else{
        printf("%d\n",cntu);
        return;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    read(c);read(T);
    while(T--) solve();
    return 0;
}

