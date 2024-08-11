#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll t,m;
    scanf("%lld%lld",&t,&m);
    for (ll i = 1; i <= t; i++){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if ((b*b-4*a*c) < 0) printf("NO\n");
        else{
            ll t = sqrt(b*b-4*a*c);
            if (t * t == (b*b-4*a*c)){
                ll p = -b+t;
                ll q = 2*a;
                if (__gcd(p,q) != 1){
                    p /= __gcd(p,q);
                    q /= __gcd(p,q);
                }
                if (q == 1){
                    printf("%lld\n",p);
                } else {
                    printf("%lld/%lld\n",p,q);
                }
            }else {
                ll q1 = -b/2a;
                ll q2 = 2*a;
                if (-b != 0){
                    printf("%lld/%lld+",b,2*a);
                }
                if (a == 1){
                    printf("sqrt(%lld)\n",b*b-4*a*c);
                }
            }
        }
    }
    return 0;
}
