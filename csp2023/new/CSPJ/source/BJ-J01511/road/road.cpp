#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d,ans,sum;
int v[100010],w[100010],vv[100010];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=2;i<=n;i++) scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=2;i<=n;i++) vv[i]=vv[i-1]+v[i];
    int last=0x3f3f3f,l=0;
    for(int i=1;i<=n;i++){
        if(w[i]<last||i==n){
            int xx=(vv[i]-vv[l]-sum+d-1)/d;
            ans+=xx*last;
            sum=xx*d-(vv[i]-vv[l]-sum);
            last=w[i];l=i;
            //cout<<i<<" "<<ans<<" "<<last<<endl;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
