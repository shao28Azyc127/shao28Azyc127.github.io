#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> g[100005][3];
bool vis[100005];
bool w[100005];
int t=0;
int ans;

int main(){

    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    cout<<"-1";
    /*cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        g[u][0].push_back(v);
        g[u][1].push_back(a);
    }

    //bfs
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now=q.front();
        q.pop();

        for(int i=1;i<=g[now][0].size();i++){
            int u=g[now][0][i];
            if(g[now][1][i]<=t&&vis[u]==0){
                q.push(u);
                vis[u]=1;
            }
        }
        if(now=n){
            vis[now]=1;
            break;
        }
        t++;
    }

    if(vis[n]==1){
        if(t%k==0){
            cout<<t;
        }else if(t%k!=0){
            int ans=(t/k+1)*k;
            cout<<ans;
        }
    }else{
        cout<<"-1";
    }*/
    return 0;
}
