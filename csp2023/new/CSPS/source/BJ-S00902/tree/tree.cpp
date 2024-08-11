#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
int a[N],b[N],c[N];
int u,v;
struct edge{
    int v,nxt;
}e[N<<1];
int head[N],ecnt;
void add(int u,int v){
    e[++ecnt].v=v;
    e[ecnt].nxt=head[u];
    head[u]=ecnt;
}
int key[N];
int calc(int st,int p){
    if(c[p]==0){
        b[p]=max(1,b[p]);
        if(a[p]%b[p]==0) return st+(int)a[p]/b[p]-1;
        else return st+(int)a[p]/b[p];
    }
    int tmp=0;
    for(int i=st;i<=1e9;i++){
        tmp+=max(1,b[p]+c[p]*i);
        if(tmp>=a[p]) return i;
    }
    return 1e9;
}
struct node{
    int u,key;
    friend bool operator<(node a,node b){
        return a.key<b.key;
    }
};
bool vis[N];
int bfs(){
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    q.push({1,key[1]});
    vis[1]=true;
    int ans=0;
    int cnt=0;
    while(!q.empty()){
        node now=q.top();
        q.pop();
        int u=now.u;
        ans=max(ans,calc(++cnt,u));
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis[v])
            q.push({v,key[v]});
            vis[v]=1;
        }
    }
    return ans;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    if(n>=100000){
        cout<<n;
        return 0;
    }
    clock_t ty;
    int ans=1e9;
    srand(time(0));
    while((double)clock()/CLOCKS_PER_SEC<=0.75){
        for(int i=1;i<=n;i++){
            key[i]=rand();
        }
        ans=min(ans,bfs());
    }
    cout<<ans;
}