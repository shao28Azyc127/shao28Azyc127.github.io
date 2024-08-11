#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
const int N=1e5+7;
typedef long long ll;
ll n,d;
ll v[N],a[N],curmin=LLONG_MAX,pos=1,rem=0,ans=0;
inline ll cnt(ll dist){
    return (dist%d==0?dist/d:dist/d+1);
}
int main(){
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    curmin=a[1];
    for(int i=2;i<=n;i++){// currently drove to i
        //calculate the price from i-1->i
        ll dist=v[i-1];
        if(rem>=dist){
            rem-=dist;
        }else{
            dist-=rem;
            rem=0;
            ll nd=cnt(dist);
            ans+=(a[pos]*nd);
            rem=nd*d-dist;
        }
        if(curmin>a[i]){
            curmin=a[i];
            pos=i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
