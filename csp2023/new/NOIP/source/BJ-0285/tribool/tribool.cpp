#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
}

const int N=2e5+5;

int C,T;

int n,m,x,y;
char c;

struct edge{
    int next,to;
}e[N<<1];
int head[N],cnt;
void add(int x,int y){
    e[++cnt].next=head[x];
    e[cnt].to=y,head[x]=cnt;
}

int ins[N],sta[N],top;
int dfn[N],tot,low[N];
int scc,col[N];
bool vis[N];
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    ins[x]=1,sta[++top]=x;
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].to;
        if(!dfn[y]) tarjan(y),low[x]=min(low[x],low[y]);
        else if(ins[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        col[x]=++scc;
        while(sta[top+1]!=x)
            col[sta[top]]=scc,ins[sta[top--]]=0;
    }
}

int from[N],v[N];

queue<int>q;
void topo(){
    for(int i=1;i<=2*n;i++)
        if(v[i]) q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=e[i].next){
            int y=e[i].to;
            if(!v[y]){
                v[y]=v[x],q.push(y);
                if(v[y]==3) v[y+n]=3;
            }
        }
    }
}

signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    read(C),read(T);
    while(T--){
        read(n),read(m);
        for(int i=1;i<=2*n;i++)
            head[i]=v[i]=0,from[i]=i;
        tot=cnt=0;
        for(int i=1;i<=m;i++){
            c=getchar();
            while(c!='+'&&c!='-'&&c!='T'&&c!='F'&&c!='U') c=getchar();
            read(x);
            if(c=='+'||c=='-'){
                read(y);
                int x2=x+n,y2=y+n;
                if(c=='+') from[x]=from[y],from[x2]=from[y2];
                else from[x]=from[y2],from[x2]=from[y];
                v[x]=0;
            }
            else if(c=='T') v[x]=1,from[x]=from[x+n]=0;
            else if(c=='F') v[x]=2,from[x]=from[x+n]=0;
            else if(c=='U') v[x]=3,from[x]=from[x+n]=0;
        }
        for(int i=1;i<=n;i++){
            if(v[i]==1) v[i+n]=2;
            else if(v[i]==2) v[i+n]=1;
            else if(v[i]==3) v[i+n]=3;
        }
        for(int i=1;i<=2*n;i++)
            if(from[i]) add(i,from[i]),add(from[i],i);
        topo();
        int ans=0;
        for(int i=1;i<=n;i++)
            if(v[i]==3||v[i+n]==3) ans++;
        for(int i=1;i<=2*n;i++)
            head[i]=low[i]=dfn[i]=0;
        for(int i=1;i<=2*n;i++)
            col[i]=0,vis[i]=0;
        scc=tot=cnt=0;
        for(int i=1;i<=2*n;i++)
            if(!v[i]) add(from[i],i);
        for(int i=1;i<=2*n;i++)
            if(!v[i]&&!dfn[i]) tarjan(i);
        //for(int i=1;i<=n;i++)
         //   cout<<from[i]<<" ";
        for(int i=1;i<=n;i++)
            if(!v[i]&&col[i]==col[i+n]) vis[i]=vis[i+n]=1;
        for(int i=1;i<=n;i++)
            if(vis[from[i]]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
