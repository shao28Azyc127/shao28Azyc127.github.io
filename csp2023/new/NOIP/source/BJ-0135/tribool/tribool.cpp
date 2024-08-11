#include <cstdio>
#include <vector>
using namespace std;
struct node{
    int y,w;
};
vector<node> g[100007];
int dd[100007],fw[100007],f[100007],kd[100007],n,m,vis[100007],now,sum,tmp[100007];
struct xw{
    char op;
    int x,y;
};
xw ttt[100007];
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].y;
        if(vis[v]) continue;
        if(dd[v]) continue;
        if(g[u][i].w) fw[v]=2-fw[u];
        else fw[v]=fw[u];
        dfs(v);
    }
}
void dfs1(int u,int t){
    vis[u]=1;
    sum++;
    fw[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].y;
        if(vis[v]){
            t^=g[u][i].w;
            if(t!=0) now=1;
            t^=g[u][i].w;
            continue;
        }
        if(g[u][i].w) t^=g[u][i].w;
        dfs1(v,t);
        t^=g[u][i].w;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) dd[i]=0,fw[i]=0,f[i]=i,kd[i]=0,vis[i]=0,g[i].clear(),tmp[i]=0;
        for(int i=1;i<=m;i++){
            char op;
            int x,y;
            scanf(" %c%d",&op,&x);
            if(op=='T') dd[x]=1,fw[x]=0;
            else if(op=='U') dd[x]=1,fw[x]=1;
            else if(op=='F') dd[x]=1,fw[x]=2;
            else if(op=='+'){
                y=x;
                scanf("%d",&x);
                if(dd[x]) dd[y]=1,fw[y]=fw[x];
                else{
                    dd[y]=0;
                    kd[y]=kd[x];
                    f[y]=f[x];
                }
            }else if(op=='-'){
                y=x;
                scanf("%d",&x);
                if(dd[x]) dd[y]=1,fw[y]=2-fw[x];
                else{
                    dd[y]=0;
                    kd[y]=kd[x]^1;
                    f[y]=f[x];
                }
            }
            ttt[i].op=op,ttt[i].x=x,ttt[i].y=y;
        }
        for(int i=1;i<=n;i++){
            if(!dd[i]) fw[i]=0;
            f[i]=i,kd[i]=0;
        }
        for(int i=1;i<=m;i++){
            char op=ttt[i].op;
            int x=ttt[i].x,y=ttt[i].y;
            if(op=='T') dd[x]=1,fw[x]=0;
            else if(op=='U') dd[x]=1,fw[x]=1;
            else if(op=='F') dd[x]=1,fw[x]=2;
            else if(op=='+'){
                if(dd[x]) dd[y]=1,fw[y]=fw[x];
                else{
                    dd[y]=0;
                    kd[y]=kd[x];
                    f[y]=f[x];
                }
            }else if(op=='-'){
                if(dd[x]) dd[y]=1,fw[y]=2-fw[x];
                else{
                    dd[y]=0;
                    kd[y]=kd[x]^1;
                    f[y]=f[x];
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!dd[i] && f[i]==i){
                if(kd[i]) fw[i]=1;
                else fw[i]=0;
            }else{
                g[f[i]].push_back((node){i,kd[i]});
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(dd[i] || f[i]==i){
                dfs(i);
                cnt++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cur=i;
                while(!tmp[cur]) tmp[cur]=1,cur=f[cur];
                now=0,sum=0;
                dfs1(cur,0);
                if(now) ans+=sum;
                cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            if(fw[i]==1) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1 1
10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/