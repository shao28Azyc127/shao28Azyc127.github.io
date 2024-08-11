#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[20005];
vector<int> g[20005];
bool vis[20005];
struct Node{
    int pos,step;
};
int bfs(){
    queue<Node> q;
    q.push({1,0});
    vis[1]=1;
    while(!q.empty()){
        int pos=q.front().pos,step=q.front().step;
        q.pop();
        if(pos==n){
            if(step%k==0){
                return step;
            }
            continue;
        }
        vis[pos]=1;
        for(int x:g[pos]){
            if(vis[x]){
                continue;
            }
            q.push({x,step+1});
        }
    }
    return -1;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d %d",&u,&v,&a[i]);
        g[u].push_back(v);
    }
    printf("%d",bfs());
    return 0;
}
