#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,m,a,b,c,s,t,x,y,g;
ll Gcd(ll a,ll b){
    return (b)?Gcd(b,a%b):a;
}
void print(ll a,ll b){
    if(b==1){
        printf("%lld",a);
    }else{
        printf("%lld/%lld",a,b);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&T,&m);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&c);
        s=b*b-4*a*c;
        if(s<0){
            printf("NO\n");
            continue;
        }
        t=ll(sqrt(s));
        if(t*t==s){
            if(a<0) x=-b-t;
            else x=-b+t;
            y=2*a;
            g=Gcd(abs(x),abs(y));
            x/=g;y/=g;
            print(x,y);
            printf("\n");
        }
    }
    return 0;
}