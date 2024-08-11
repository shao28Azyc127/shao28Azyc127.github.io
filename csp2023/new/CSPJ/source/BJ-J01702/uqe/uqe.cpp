#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,M;
ll gcd(ll a,ll b){
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&T,&M);
    while(T--){
        ll a,b,c;
        bool flag=0;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll d=b*b-4*a*c;
        if(d>=0){
            ll x=sqrt(d);
            if(x*x==d){
                if(a>0){
                    if(((-b)+x)%(2*a)==0){
                        printf("%lld",((-b)+x)/(2*a));
                    }else{
                        ll t=-b+x;
                        a=2*a;
                        ll G=gcd(abs(t),abs(a));
                        t/=G;
                        a/=G;
                        if(a<0&&t<0){
                            a=-a;
                            t=-t;
                        }else if(a<0&&t>=0){
                            printf("-");
                            a=-a;
                        }else if(a>=0&&t<0){
                            printf("-");
                            t=-t;
                        }
                        if(a!=1){
                            printf("%lld/%lld",t,a);
                        }
                    }
                }else{
                    if(((-b)-x)%(2*a)==0){
                        printf("%lld",((-b)-x)/(2*a));
                    }else{
                        ll t=-b-x;
                        a=2*a;
                        ll G=gcd(abs(t),abs(a));
                        t/=G;
                        a/=G;
                        if(a<0&&t<0){
                            a=-a;
                            t=-t;
                        }else if(a<0&&t>=0){
                            printf("-");
                            a=-a;
                        }else if(a>=0&&t<0){
                            printf("-");
                            t=-t;
                        }
                        if(a!=1){
                            printf("%lld/%lld",t,a);
                        }
                    }
                }

            }else{
                if(b!=0){
                    if((-b)%(2*a)==0){
                        printf("%lld",(-b)/(2*a));
                    }else{
                        if(a<0&&b<0){
                            printf("-");
                            a=-a;
                        }
                        if(a>0&&b>0){
                            printf("-");
                            b=-b;
                        }
                        ll G=gcd((-b),(2*a));
                        printf("%lld/%lld",(-b)/G,(2*a)/G);
                    }
                    flag=1;
                }
                if(flag){
                    printf("+");
                }
                ll ans=1;
                for(ll i=2;i*i<d;i++){
                    while(d%(i*i)==0){
                        d/=i*i;
                        ans*=i;
                    }
                }
                a=2*a;
                a=abs(a);
                ll G=gcd(ans,a);
                ans/=G;
                a/=G;
                if(ans>1){
                    printf("%lld*",ans);
                }
                printf("sqrt(%lld)",d);
                if(a!=1){
                    printf("/%lld",a);
                }
            }
        }else{
            printf("NO");
        }
        printf("\n");
    }
    return 0;
}
