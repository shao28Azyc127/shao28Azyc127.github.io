#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
ll v[1000005];
int main(){
    //t2
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d;
    scanf("%lld%lld",&n,&d);
    ll tot;
    for(int i=1;i<=n-1;i++){
        scanf("%lld",&v[i]);
        tot+=v[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    ll ans=0;
    ll last=0;
    for(int i=1;i<=n;){
        ll sum=0;
        int j=i+1;
        while(a[j]>a[i]){
            if(j==n){
                break;
            }
            sum+=v[j-1];
            j++;
        }
        sum+=v[j-1];
        sum-=last;
        ll tmp;
        if(sum%d==0){
            tmp=sum/d;
        }else{
            tmp=sum/d+1;
            last=tmp*d-sum;
        }
        ans+=tmp*a[i];
        i=j;
        if(i==n){
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
