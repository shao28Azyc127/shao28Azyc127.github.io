#include <bits/stdc++.h>
using namespace std;
const int N=20000+10,K=100+10;
struct PP{
    int v,w;
};vector<PP>vc[N];
int dis[N][K],vis[N][K];
int n,m,kk;

int check(int u){
    u*=kk;
    for(int i=1;i<=n;i++)for(int j=0;j<kk;j++)dis[i][j]=vis[i][j]=0;
    queue<PP>que;que.push({1,u});dis[1][0]=u;vis[1][0]=1;
    //cout<<u<<endl;
    while(que.size()){
        PP t=que.front();que.pop();
        for(auto i:vc[t.v]){
            if(vis[i.v][(t.w+1)%kk])continue;
            dis[i.v][(t.w+1)%kk]=t.w+1;vis[i.v][(t.w+1)%kk]=1;
            que.push({i.v,t.w+1});
        }
    }
    return vis[n][0]?dis[n][0]:-1;
}

void test(){
    cin>>n>>m>>kk;
    int t=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;t=max(t,w/kk+1);
        vc[u].push_back({v,w});
    }
    cout<<check(0)<<endl;return;
}

signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    test();
    return 0;
}
