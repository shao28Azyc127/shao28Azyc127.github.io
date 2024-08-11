#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define repp(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll cnt[100005],n,b[15];
ll calc(){
    ll x=0;
    rep(i,1,5){
        x*=10;
        x+=b[i];
    }
    return x;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    rep(i,1,n){
        rep(j,1,5) scanf("%lld",b+j);
        rep(j,1,4){
            rep(k,1,9){
                b[j]+=k;
                b[j]%=10;
                ++cnt[calc()];
                b[j+1]+=k;
                b[j+1]%=10;
                ++cnt[calc()];
                b[j]-=k-10;
                b[j]%=10;
                if(j==4) ++cnt[calc()];
                b[j+1]-=k-10;
                b[j+1]%=10;
            }
        }
    }
    ll ans=0;
    rep(i,0,99999) if(cnt[i]==n) ++ans;
    printf("%lld",ans);
    return 0;
}
