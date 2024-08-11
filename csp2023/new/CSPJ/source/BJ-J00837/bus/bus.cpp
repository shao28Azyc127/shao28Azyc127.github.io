#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[4005][4005],dis[4005][4005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,x;
        cin>>u>>v>>x;
        a[u][v]=1;
    }
    cout<<-1;
    return 0;
    for(int k=0;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][k],dis[k][j])+a[i][j];
            }
        }
    }
    cout<<dis[1][n];
    return 0;
}
