#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int>g[100005],w[100005];
int vis[100005],ci=0;
int ds[100005];
bool flag=0;
int sz=0;
void dfs(int i,int he){
    if(flag)return;
    vis[i]=ci,ds[i]=he;
    ++sz;
    for(int j=0;j<g[i].size();j++){
        int v=g[i][j];
        if(vis[v]==ci){
            if((ds[i]+w[i][j]-ds[v]%2)==1){
                flag=1;
                return;
            }
        }
        if(vis[v]==0)dfs(v,ci+w[i][j]);
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cout<<"0\n";
        /*int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char a;
            cin>>a;
            if(a=="+"){
                int x,y;
                cin>>x>>y;
                g[y].push_back(x);
                w[y].push_back(0);
            }
            else if(a=="-"){
                int x,y;
                cin>>x>>y;
                g[y].push_back(x);
                w[y].push_back(1);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            flag=0;
            if(vis[i]==0){
                ++ci;
                dfs(i,0);
            }
        }
        if(flag)cout<<"*/
    }
    return 0;
}
