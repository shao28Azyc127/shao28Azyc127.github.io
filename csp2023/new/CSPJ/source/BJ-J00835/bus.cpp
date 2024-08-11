#include<bits/stdc++.h>
using namespace std;
struct id{
    int u,a;
};
struct node{
    int num,time;
};
int n,m,p;
vector<id>v[10001];
void bfs(){
    queue<node>q;
    q.push(node{1,0});
    while(!q.empty()){
        node k=q.front();
        q.pop();
        if(k.num==n&&k.time%p==0){
            cout<<k.time;
            return;
        }
        for(int i=0;i<v[k.num].size();i++)
            if(k.time>=v[k.num][i].a)q.push(node{v[k.num][i].u,k.time+1});
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>p;
    for(int i=1;i<=m;i++){
        int u,c,a;
        cin>>u>>c>>a;
        v[u].push_back(id{c,a});
    }
    bfs();
    return 0;
}
