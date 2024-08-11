#include<bits/stdc++.h>
using namespace std;
long long n,d,v[114514],a[114514],ans=0,lc=0,noww=1;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=2;i<=n;++i){
        scanf("%lld",&v[i]);
        v[i]=v[i-1]+v[i];
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=2;i<n;++i){
        if(a[i]<a[noww]){
            lc+=v[i]-v[noww];
            ans+=(lc/d)*a[noww];
            lc=lc%d;
            if(lc>0){
                lc-=d;
                ans+=a[noww];
            }
            noww=i;
        }
    }
    lc+=v[n]-v[noww];
    ans+=(lc/d)*a[noww];
    lc=lc%d;
    if(lc>0){
        lc-=d;
        ans+=a[noww];
    }
    printf("%lld",ans);
    return 0;
}

