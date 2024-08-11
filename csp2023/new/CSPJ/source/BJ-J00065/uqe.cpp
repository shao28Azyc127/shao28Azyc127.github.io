#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,m,k,ans=2e9,f[20005];
struct node{
    int v,a;
};
vector<node>e[20005],q[20005];
bool vis[20005];
void dfs(int now,int maxtime,int nowtime){
    if(now==n){
        if((maxtime+nowtime)%k==0)ans=min(ans,nowtime+maxtime);
        return;
    }
    for(auto h:e[now]){
        int g=h.a-nowtime;
        g=(g/k+(g%k!=0))*k;
        vis[h.v]=1;
        dfs(h.v,max(maxtime,g),nowtime+1);
        vis[h.v]=0;
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        e[u].push_back({v,a});
        q[v].push_back({u,a});
    }
    memset(f,-1,sizeof(f));
    if(n<=10&&m<=20){
        vis[1]=1;
        dfs(1,0,0);
        if(ans==2e9)ans=-1;
        cout<<ans;
        return 0;
    }
    cout<<-1;
    return 0;
}