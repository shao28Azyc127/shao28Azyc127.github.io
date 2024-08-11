#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,d,Min,ans,now;
int a[N],v[N],sum[N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    if(n==1){
        puts("0");
        return 0;
    }
    for(int i=1;i<n;i++) scanf("%lld",&v[i]),sum[i+1]=sum[i]+v[i];
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    Min=a[1];
    for(int i=2;i<n;i++){
        if(a[i]<Min){
            ans+=((sum[i]-1)/d+1-now)*Min;
            now=(sum[i]-1)/d+1;
            Min=a[i];
        }
    }
    printf("%lld\n",ans+((sum[n]-1)/d+1-now)*Min);
    return 0;
}
