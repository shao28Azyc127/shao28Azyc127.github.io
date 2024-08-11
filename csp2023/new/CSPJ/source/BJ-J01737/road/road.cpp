#include <bits/stdc++.h>
using namespace std;
long long n,d,a[100005],b[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    long long m=b[1],qs=0,sx=0;
    for(int i=2;i<=n;i++){
        qs+=m*((a[i-1]+d-1-sx)/d);
        sx=(a[i-1]+d-1-sx)/d*d-(a[i-1]-sx);
        if(b[i]<m){
           m=b[i];
        }
    }
    printf("%lld",qs);
    return 0;
}
