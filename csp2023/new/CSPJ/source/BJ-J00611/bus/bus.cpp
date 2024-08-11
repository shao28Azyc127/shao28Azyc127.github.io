#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    int to,a;
};
struct Node2{
    int id,t;
    friend bool operator < (Node2 x,Node2 y){
        return x.t>y.t;
    }
};
int n,m,k;
bool vis[100005];
vector<Node> vec[10005];
int bfs(){
    priority_queue<Node2> q;
    q.push((Node2){1,0});
    while(!q.empty()){
        int now=q.top().id,t=q.top().t; q.pop();
        //cout<<now<<" "<<t<<endl;
        if(now==n&&t%k==0) return t;
        for(int i=0;i<vec[now].size();i++){
            if(t>=vec[now][i].a) q.push((Node2{vec[now][i].to,t+1}));
            else q.push((Node2){vec[now][i].to,t+1+k*((vec[now][i].a-t+k-1)/k)});
        }
    }
    return -1;
}
int bfs2(){
    priority_queue<Node2> q;
    q.push((Node2){1,0});
    while(!q.empty()){
        int now=q.top().id,t=q.top().t; q.pop();
        //cout<<now<<" "<<t<<endl;
        if(now==n&&t%k==0) return t;
        for(int i=0;i<vec[now].size();i++){
            if(vis[vec[now][i].to]) continue;
            vis[vec[now][i].to]=1;
            if(t>=vec[now][i].a) q.push((Node2{vec[now][i].to,t+1}));
            else q.push((Node2){vec[now][i].to,vec[now][i].a+1});
        }
    }
    return -1;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        vec[u].push_back((Node){v,w});
    }
    if(k!=1) cout<<bfs()<<endl;
    if(k==1) cout<<bfs2()<<endl;
}
