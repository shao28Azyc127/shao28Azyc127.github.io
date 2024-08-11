#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k,g[10005][10005],u,v,a,ds[10005];
bool vs[10005]={0};
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    memset(ds,0x3f,sizeof(ds));
    memset(g,0x3f,sizeof(g));
    for(int i = 1;i <= m;i++){
        cin >> u >> v >> a;
        g[u][v]=a;
    }
    ds[1]=0;
    for(int i = 1;i <= n;i++){
        int minp=n+1;
        for(int j = 1;j <= n;j++){
            if(!vs[j] && ds[j]<ds[minp]){
                minp=j;
            }
        }
        vs[minp]=1;
        for(int j = 1;j <= n;j++){
            if(g[minp][j]<=ds[minp]){
                ds[j]=min(ds[j],ds[minp]+1);
            }
            else if(minp==1){
                ds[j]=min(ds[j],(g[1][j]+k-1)/k*k);
            }
        }
    }
    if(ds[n]!=0x3f3f3f3f && ds[n]%k==0)cout << ds[n];
    else cout << -1;
    return 0;
}
