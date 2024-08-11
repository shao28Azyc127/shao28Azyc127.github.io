#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int>g[10005],a[10005];
struct node{
    int i,t;
    bool operator>(const node l1) const{
        return t>l1.t;
    }
    bool operator<(const node l1) const{
        return t<l1.t;
    }
};
priority_queue<node,vector<node>,greater<node> >q;
int n,m,k;
int vis[10005][105];
void bfs(){
    while(!q.empty()){
        int i=q.top().i,t=q.top().t;
        q.pop();
        //cout<<i<<" "<<t<<endl;
        if(vis[i][t%k])continue;
        vis[i][t%k]=1;
        if(i==n&&t%k==0){
            cout<<t;
            exit(0);
        }
        for(int j=0;j<g[i].size();j++){
            if(t<a[i][j]){
                int l=(a[i][j]-t)/k;
                if((a[i][j]-t)%k!=0)++l;
                q.push(node{g[i][j],t+l*k+1});

            }
            else q.push(node{g[i][j],t+1});
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        a[u].push_back(w);
    }
    q.push(node{1,0});
    bfs();
    cout<<"-1";
    return 0;
}
/*
5 5 3
1 2 0
2 5 1
1 3 0
3 4 3
4 5 1
*/
