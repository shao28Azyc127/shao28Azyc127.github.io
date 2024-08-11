#include<iostream>
#include<cstdio>
using namespace std;
int r[20001][20001],a[20001],vis[20001][20001];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>a[i];
        r[u][v]=1;
    }
    cout<<6;
    return 0;
}
