#include<bits/stdc++.h>

using namespace std;

const int NR=1e5+10;

int n,m;
int id[NR];

struct Node{
    int x,w;
}a[NR*2];
int sz;

struct Edge{
    int to,nxt,w;
}g[NR*2];
int fte[NR],gsz;

void addedge(int x,int y,int w){
    g[++gsz]=(Edge){y,fte[x],w};
    fte[x]=gsz;
}

bool vis[NR],flag;
int s[NR],cnt,ans;

void dfs(int x){
    vis[x]=1;
    if(flag) ans++;
    for(int i=fte[x];i;i=g[i].nxt){
        int y=g[i].to;
        if(!vis[y]) dfs(y);
    }
}

void dfs2(int x){
    vis[x]=1;
    cnt++;
    for(int i=fte[x];i;i=g[i].nxt){
        int y=g[i].to;
        if(vis[y]){
            if(s[y]!=(s[x]^g[i].w)) flag=0;
            continue;
        }
        s[y]=(s[x]^g[i].w);
        dfs2(y);
    }
}

void work(int x){
    flag=1;
    cnt=s[x]=0;
    dfs2(x);
    if(!flag) ans+=cnt;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T; scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%d",&n,&m);
        sz=0;
        for(int i=1;i<=n+3;i++){
            id[i]=i;
            a[++sz]=(Node){i,0};
        }
        for(int i=1;i<=m;i++){
            char c; int x,y;
            scanf(" %c",&c);
            if(c=='+'||c=='-') scanf("%d%d",&x,&y);
            else{
                scanf("%d",&x);
                if(c=='T') y=n+1;
                else if(c=='F') y=n+2;
                else y=n+3;
            }
            a[sz+1]=a[id[y]];
            id[x]=++sz;
            if(c=='-') a[sz].w^=1;
        }
        memset(fte,0,sizeof(fte));
        gsz=0;
        for(int i=1;i<=n;i++){
            int x=a[id[i]].x,w=a[id[i]].w;
            if(x==i){
                if(w==1){
                    addedge(i,n+3,0);
                    addedge(n+3,i,0);
                }
                continue;
            }
            addedge(i,x,w);
            addedge(x,i,w);
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        memset(s,-1,sizeof(s));
        flag=0;
        dfs(n+1); // T
        dfs(n+2); // F
        flag=1;
        dfs(n+3); // U
        ans--;
        for(int i=1;i<=n;i++){
            if(!vis[i]) work(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}