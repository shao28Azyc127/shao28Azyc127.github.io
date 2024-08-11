#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
long long n,d;
long long a[N],v[N];
long long lb,r,ans,t,tmp,p,q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n-1;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
    }
    lb=1;
    for(int i=1;i<=n;i++){
        if(v[i]<v[lb]||i==n){
            if((t-r)%d==0){
                p=(t-r)/d;
            }else{
                p=(t-r)/d+1;
            }
            q=p*d+r;
            ans+=p*v[lb];
            r=q-t;
            //cout<<lb<<' '<<t<<' '<<q<<' '<<r<<' '<<ans<<endl;
            lb=i;
            t=0;
        }
        if(i<=n-1){
            t+=a[i];
        }
    }
    printf("%lld",ans);
    return 0;
}
