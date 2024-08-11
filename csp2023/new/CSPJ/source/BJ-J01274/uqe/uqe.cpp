#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
ll t,m;
ll x;
ll p,q,k;
ll e=1,r,tmp,o;
ll gcd(ll a,ll b){
    if(a<b){
        swap(a,b);
    }
    int c;
    while(a%b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return b;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&t,&m);
    while(t--){
        scanf("%lld%lld%lld",&a,&b,&c);
        d=b*b-4*a*c;
        if(d<0){
            printf("NO\n");
        }
        else if(d>=0){
            o=(long long)sqrt(d);
            if(o*o==d){
                p=sqrt(d)-b;
                q=2*a;
                k=gcd(p,q);
                p/=k,q/=k;
                if(q/-1>0){
                    p*=-1;
                    q*=-1;
                }
                if(q==1){
                    printf("%lld\n",p);
                }else{
                    printf("%lld/%lld\n",p,q);
                }
            }else{
                p=-1*b;
                q=2*a;
                k=gcd(p,q);
                p/=k,q/=k;
                if(q/-1>0){
                    p*=-1;
                    q*=-1;
                }
                if(p!=0){
                    if(q==1){
                        printf("%lld+",p);
                    }else{
                        printf("%lld/%lld+",p,q);
                    }
                }
                e=1;
                for(int i=2;i<=(ll)sqrt(d);i++){
                    if(d%(i*i)==0){
                        e*=i;
                        d/=i*i;
                    }
                }
                p=e,q=2*a;
                k=gcd(p,q);
                p/=k,q/=k;
                //cerr<<p<<endl;
                if(p!=1){
                    printf("%lld*",e);
                }
                printf("sqrt(%lld)/%lld\n",d,q);
            }
        }
    }
    return 0;
}
