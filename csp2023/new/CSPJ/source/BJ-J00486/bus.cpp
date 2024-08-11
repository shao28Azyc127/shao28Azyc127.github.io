#include<bits/stdc++.h>
using namespace std;

struct node{
    int to=0;
    int next=0;
    int w;
}edge [100005];

int cnt=0,head[100005];

int n,m,k,ans=0;

void check(int deep,int bg){
    if(bg%k==0) deep+=bg;
    else{
        deep=deep+(bg/k)*k;
    }
    if(deep%k==0){
        if(ans==0) ans=deep;
        else ans=min(ans,deep);
    }
}

void build(int u,int v,int t){
    edge[++cnt].to=v;
    edge[cnt].w=t;
    edge[cnt].next=head[u];
    head[u]=cnt;
}

void dfs(int root,int deep,int bg){
    if(root==n) {
        check(deep,bg);
    }
    if(deep>k*m) return;
    for(int i=head[root];i!=0;i=edge[i].next){
        int v=edge[i].to;
        dfs(v,deep+1,max(bg,edge[i].w));
    }
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,t;
        cin>>u>>v>>t;
        build(u,v,t);
    }
    dfs(1,0,0);
    if(ans==0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
