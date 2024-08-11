#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll cal(ll a,ll b,ll c){
    ll delta = b*b-4*a*c;
    if(delta == 0){
    }
    if((ll)sqrt(delta) == sqrt(delta)){

    }
}
ll gcd(ll a,ll b){
    if(a == 0)  return b;
    else if(b == 0)  return a;
    else    return gcd(b,a%b);
}
ll z1,z2,mu;
void qout(ll a,ll b,ll c){
    z1 = a;
    z2 = b;
    mu = c;
    if(z1*1.0/mu > z2*1.0/mu){
            if(c < 0){
                printf("%lld/%lld\n",-(z1/gcd(z1,mu)),-(mu/gcd(z1,mu)));
            }
            else    printf("%lld/%lld\n",z1/gcd(z1,mu),mu/gcd(z1,mu));
    }
    else{
        if(c < 0){
            printf("%lld/%lld\n",-(z2/gcd(z2,mu)),-(mu/gcd(z2,mu)));
        }
        else    printf("%lld/%lld\n",z2/gcd(z2,mu),mu/gcd(z2,mu));
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll a,b;
    scanf("%lld%lld",&a,&b);
    for(ll i = 0;i < a;i++){
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        ll delta = y*y-4*x*z;
        if(delta < 0){
            printf("NO\n");
            continue;
        }
        if((ll)sqrt(delta) == sqrt(delta)){
                qout(sqrt(delta)-y,-(sqrt(delta))-y,2*x);
        }
        //else{
          //  ll r = -y;
          //  ll mu = 2*x;
          //  qout(-0x3f3f3f3f,z,mu);
          //  printf("+");
          //  if(sqrt(delta)/2.0/x > sqrt(delta)/2.0/x){
        //        if(2*x == 1){
            //       printf("sqrt(delta)")
         //       }
         //   }
        //}
    }
    return 0;
}
