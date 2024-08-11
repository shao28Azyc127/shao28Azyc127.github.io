#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN=100010;
int a[maxN],v[maxN];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,k,l=0,o=0,ans=0;
    scanf("%lld%lld",&n,&k);
    for(int i=2;i<=n;i++) scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int minp=a[1];
    for(int i=2;i<=n;i++){
        l+=v[i];
        if(a[i]<minp || i==n){
            int r=(l-o+k-1)/k;
            ans+=r*minp;
            o=r*k-(l-o);
            l=0;
            minp=a[i];
        }
    }
    printf("%lld",ans);
    return 0;
}