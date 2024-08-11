#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,i,u[m],v[m],a[m],sh;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>u[i]<<v[i]<<a[i];
        sh+=a[i];
    }
    return 0;
}
    