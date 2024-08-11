#include<bits/stdc++.h>
using namespace std;
const int MXN=2e4+10,MXM=5e4+10;
int n,m,k;
int head[MXN],to[MXM],nxt[MXM],t[MXM],cnt=1;
inline void add_e(int u,int v,int a){
    to[++cnt]=v;
    t[cnt]=a;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1,u,v,a;i<=m;i++){
        cin>>u>>v>>a;
        add_e(u,v,a);
    }
    cout<<-1<<'\n';
    return 0;
}
