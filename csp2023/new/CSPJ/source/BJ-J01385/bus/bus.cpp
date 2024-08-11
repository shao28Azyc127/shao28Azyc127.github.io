#include <bits/stdc++.h>
using namespace std;
int n,m,ans=2e9,k;
int a[10005];
vector<int> g[10005];
void bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(x==n){
            if(y%k==0) ans=min(ans,y);
        }
        for(int i=0;i<g[x].size();i++){
            q.push(make_pair(g[x][i],y+1));
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        cin >>u>>v>>a[i];
        g[u].push_back(v);
    }
    bfs();
    cout <<ans;
    return 0;
}
