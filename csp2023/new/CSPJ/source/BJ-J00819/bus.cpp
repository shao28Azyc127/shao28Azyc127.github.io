#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=1e4+5;
int n,m,k;
vector<int> g[N];
bool vis[N];
int mins=1e9;
void dfs(int u,int cnt){
    if(u==n&&cnt%k==0){
        mins=min(mins,cnt);
        return;
    }
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v]) {
            dfs(v,cnt+1);
        }
    }
    vis[u]=0;
    return;
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    n=read(),m=read(),k=read();
    bool f=1;
    for(int i=1;i<=m;i++){
        int u=read(),v=read(),w=read();
        if(w>0) f=0;
        g[u].push_back(v);
    }
    if(!f){
        cout<<-1;
        return 0;
    }
    dfs(1,0);
    if(mins==1e9) cout<<-1;
    else cout<<mins;
    return 0;
}
