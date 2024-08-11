#include<bits/stdc++.h>
using namespace std;
int n,m,k,vis[20010],minn=10010;
vector<int> a[2][20010];
bool flag=false;
void dfs(int x,int time){
    vis[x]=true;
    if(x==n){
        flag=true;
        minn=min(time,minn);
    }
    for(int i=0;i<a[0][x].size();i++){
        if(!vis[a[0][x][i]]&&time>=a[1][x][i]) dfs(a[0][x][i],time+1);
    }
    vis[x]=false;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[0][x].push_back(y);
        a[0][y].push_back(x);
        int k;
        cin>>k;
        a[1][x].push_back(k);
        a[1][y].push_back(k);
    }
    dfs(1,0);
    cout<<-1<<'\n';
    return 0;
}