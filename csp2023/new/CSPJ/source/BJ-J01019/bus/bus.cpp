#include<bits/stdc++.h>
using namespace std;
vector<int> G[10005];
bool v[10005];
struct node{
    int x,b;
};
int n,m,k;
int minn=2e9;
void dfs(int x,int b){
    if(x==n){
        if(b%3==0){
            minn=min(minn,b);
        }
        return ;
    }
    for(int i=0;i<G[x].size();i++){
        if(!v[G[x][i]]){
            v[G[x][i]]=1;
            dfs(G[x][i],b+1);
            v[G[x][i]]=0;
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int u,vv,w;
    for(int i=1;i<=m;i++){
        cin>>u>>vv>>w;
        G[u].push_back(vv);
    }
    if(k==1){
        queue<node> q;
        node l;
        q.push((node){1,0});
        v[1]=1;
        while(!q.empty()){
            l=q.front();
            q.pop();
            if(l.x==n){
                cout<<l.b;
                return 0;
            }
            for(int i=0;i<G[l.x].size();i++){
                if(!v[G[l.x][i]]){
                    q.push((node){G[l.x][i],l.b+1});
                    v[G[l.x][i]]=1;
                }
            }
        }
        cout<<-1;
        return 0;
    }
    else{
        dfs(1,0);
        if(minn==2e9) cout<<-1;
        else cout<<minn;
    }
    return 0;
}

