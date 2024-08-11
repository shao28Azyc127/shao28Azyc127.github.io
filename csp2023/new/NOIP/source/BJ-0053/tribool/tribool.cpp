#include<iostream>
#include<vector>
using namespace std;
const int N=100100;
inline int read(){
    int i=getchar(),r=0;
    while(i<'0'||i>'9')i=getchar();
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r;
}
inline char readc(){
    char i=getchar();
    while(i!='-'&&i!='+'&&i!='T'&&i!='F'&&i!='U')i=getchar();
    return i;
}
int n,m,now[N];
int dsu[N];
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
//-n,...,-1,1,...,n;
//U->0;
//T->n+1;
//F->-n-1;
int ans[N];
bool vis[N];
int head[N],to[N<<1],nex[N<<1],wei[N<<1],edge;
inline void insert(int u,int v,int w){
    dsu[find(u)]=find(v);
    edge++;
    to[edge<<1]=v;
    nex[edge<<1]=head[u];
    head[u]=edge<<1;
    to[edge<<1|1]=u;
    nex[edge<<1|1]=head[v];
    head[v]=edge<<1|1;
    wei[edge<<1]=wei[edge<<1|1]=w;
}
vector<int>bel[N];
void init(){
    cin>>n>>m;
    edge=0;
    for(int i=0;i<=n+1;i++){
        bel[i].clear();
        now[i]=dsu[i]=i;
        vis[i]=false;
        head[i]=0;
    }
    for(int i=1;i<=m;i++){
        char t=readc();
        if(t=='-'){
            int u=read(),v=read();
            now[u]=-now[v];
        }
        else if(t=='+'){
            int u=read(),v=read();
            now[u]=now[v];
        }
        else if(t=='T'){
            int u=read();
            now[u]=n+1;
        }
        else if(t=='F'){
            int u=read();
            now[u]=-n-1;
        }
        else{
            int u=read();
            now[u]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(now[i]>=0)insert(i,now[i],1);
        else insert(i,-now[i],-1);
    }
    for(int i=0;i<=n+1;i++)bel[find(i)].emplace_back(i);
}
bool dfs(int nd,int col){
    vis[nd]=true;
    ans[nd]=col;
    for(int i=head[nd];i;i=nex[i]){
        if(vis[to[i]]){
            if(wei[i]*col!=ans[to[i]])return false;
        }
        else{
            if(!dfs(to[i],wei[i]*col))return false;
        }
    }
    return true;
}
//remember to clear!!!
int main(){
    // freopen("tribool/tribool4.in","r",stdin);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c;cin>>c;
    int t;cin>>t;
    while(t--){
        init();
        dfs(0,0);
        if(!dfs(n+1,1)){
            for(int j:bel[find(n+1)]){
                ans[j]=0;
                vis[j]=true;
            }
        }
        for(int i=1;i<=n;i++)if(!vis[i]){
            if(!dfs(i,1)){
                for(int j:bel[find(i)]){
                    ans[j]=0;
                    vis[j]=true;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)if(ans[i]==0)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}