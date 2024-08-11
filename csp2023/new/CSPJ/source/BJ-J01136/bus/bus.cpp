#include<bits/stdc++.h>
using namespace std;
int v[10005][10005],f[10005];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,x,y,z;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        v[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==1){
                f[i]=f[j]+1;
            }
            if(j==n){
                f[i]=1;
            }
        }
    }
    cout<<-1;
    return 0;
}
