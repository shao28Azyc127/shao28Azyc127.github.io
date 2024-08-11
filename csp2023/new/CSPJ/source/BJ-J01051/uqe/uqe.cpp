#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c;
ll check(ll n){
    ll r=sqrt(n);
    ll tmp=r*r;
    if(tmp==n)return r;
    else return -1;
}
void out_yl(ll zi,ll mu){
    if(zi==0){printf("0");return;}
    if(zi<0||mu<0){
        if(zi<0&&mu>=0||mu<0&&zi>=0)printf("-");
        zi=abs(zi),mu=abs(mu);
    }
    ll qq=__gcd(zi,mu);
    zi/=qq,mu/=qq;
    if(mu==1)printf("%lld",zi);
    else printf("%lld/%lld",zi,mu);
}
void out_wl(ll q2,ll r,ll mu){
    if(q2==mu)printf("sqrt(%lld)",r);
    else if(q2%mu==0)printf("%lld*sqrt(%lld)",q2/mu,r);
    else if(mu%q2==0)printf("sqrt(%lld)/%lld",r,mu/q2);
    else {
        ll qq=__gcd(q2,mu);
        q2/=qq,mu/=qq;
        printf("%lld*sqrt(%lld)/%lld",q2,r,mu);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll T,m;scanf("%lld%lld",&T,&m);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a<0)a=-a,b=-b,c=-c;
        ll der=b*b-4*a*c;
        if(der<0){
            printf("NO\n");
            continue;
        }
        if(check(der)!=-1){
            ll zi=check(der)-b;
            ll mu=a*2;
            out_yl(zi,mu);printf("\n");
            continue;
        }
        if(b!=0){
            out_yl(-b,2*a);printf("+");
        }
        ll ttt=der,ans=1;
        for(ll i=2;i*i<=der;i++)
            while(ttt%(i*i)==0){
                ttt/=(i*i);ans*=i;
            }
        ll q2=ttt,r=ans;
        //printf("%lld %lld ",q2,r);
        out_wl(r,q2,2*a);
        printf("\n");
    }
    return 0;
}
