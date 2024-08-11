#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int u[N],v[N],a[N];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&u[i],&v[i],&a[i]);
    }
    printf("%d",m/2*k);
    return 0;
}
