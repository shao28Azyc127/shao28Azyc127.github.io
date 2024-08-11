#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
#define maxn 10005
struct edge{
    int to,next;
}e[maxn*2];
int n,m,k,d[maxn],tot,ans=-1;
bool vis[maxn][105];
void addedge(int u,int v){
    e[++tot].to=v;
    e[tot].next=d[u];
    d[u]=tot;
}
void bfs(void){
    queue<pair<int,int> > q;
    q.push(make_pair(1,0));
    vis[1][0]=true;
    while(!q.empty()){
        pair<int,int> now=q.front();
        q.pop();
        if(now.first==n){
            if(now.second%k==0){
                ans=now.second;
                return;
            }
            else{
                continue;
            }
        }
        for(int i=d[now.first];i!=0;i=e[i].next){
            if(!vis[e[i].to][(now.second+1)%k]){
                q.push(make_pair(e[i].to,now.second+1));
                vis[e[i].to][(now.second+1)%k]=true;
            }
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        addedge(u,v);
    }
    bfs();
    cout<<ans;
    return 0;
}
