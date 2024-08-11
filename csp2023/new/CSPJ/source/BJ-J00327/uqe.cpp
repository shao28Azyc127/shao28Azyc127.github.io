#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
void sim(ll &p,ll &q){
    if(p==0){
        q=1;
        return;
    }
    ll tp=gcd(p,q);
    p/=tp,q/=tp;
}
void process_q(ll &f,ll &p,ll &q,ll p1,ll q1){
    p=abs(p1),q=abs(q1),f=1;
    if(p1<0) f*=-1;
    if(q1<0) f*=-1;
}
void print_q(ll f,ll p,ll q){
    sim(p,q);
    if(f==-1&&p!=0){
        printf("-");
    }
    printf("%lld",p);
    if(q>1){
        printf("/%lld",q);
    }
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll t,m;
    scanf("%lld%lld",&t,&m);
    for(ll k=1;k<=t;k++){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll d=b*b-4*a*c;
        if(d<0){
            printf("NO\n");
            continue;
        }
        ll f1,p1,q1,f=d,g=1;
        process_q(f1,p1,q1,-b,a*2);
        if(d==0){
            sim(p1,q1);
            print_q(f1,p1,q1);
            printf("\n");
            continue;
        }
        for(ll i=2;i*i<=d;i++){
            while(f%(i*i)==0){
                f/=i*i,g*=i;
            }
        }
        ll q2=q1;
        if(f==1){
            p1=p1*f1+g;
            f1=p1>0?1:-1;
            p1=abs(p1);
            sim(p1,q1);
            print_q(f1,p1,q1);
            printf("\n");
        }else{
            sim(p1,q1),sim(g,q2);
            if(p1!=0){
                print_q(f1,p1,q1);
                if(g>0) printf("+");
                else printf("-");
            }
            if(g!=1) printf("%lld*",g);
            printf("sqrt(%lld)",f);
            if(q2!=1) printf("/%lld",q2);
            printf("\n");
        }
    }
    return 0;
}
