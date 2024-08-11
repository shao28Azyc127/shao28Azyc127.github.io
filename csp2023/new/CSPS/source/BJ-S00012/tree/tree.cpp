#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
struct node{
    long long  a,b,c;
}s[maxn];
vector<int >edge[maxn];
int dfsclock=0,fa[maxn],dfn[maxn];
void dfs(int u,int f){
    fa[u]=f;
    dfn[u]=++dfsclock;
    for(int i=0;i<edge[u].size();i++){
        if(edge[u][i]==fa[u])
             continue;
        dfs(edge[u][i],u);
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdin);
    int n,u,v;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b>>s[i].c;
        fa[i]=i;
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    int day[maxn];
    for(int i=1;i<=n;i++){
        if(b[i]<1)
            day[i]=a[i];
        else
            day[i]=a[i]/b[i]+0.5;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,day[i]);
    }
    cout<<ans;
    return 0;
}