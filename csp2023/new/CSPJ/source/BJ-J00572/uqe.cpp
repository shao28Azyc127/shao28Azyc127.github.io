#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long T,M;
// cn=7
// 7mod3=1
// 1 2 3 4 5 6 7 ORIG
// 1 2 0 1 2 0 1 MOD3
// TAKE ALL %3 == 1
// 2 3 5 6
// 1 2 0 1
bool isINT(double in){
    int altv=floor(in);
    if(abs((double)altv-in)<=(double)0.0000001F)return 1;
    return 0;
}
long long gcd(long long a,long long b){
    if(b==0)return a;
    if(a==0)return b;
    return gcd(b,a%b);
}
int main(){
    printf("%lld\n",gcd(12ll,18ll));
    //#ifdef ONLINE_JUDGE
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    //#endif
    scanf("%lld %lld",&T,&M);
    while(T--){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long delta=b*b-4*a*c;
        if(delta<0){
            printf("NO\n");
            continue;
        }
        if(isINT(sqrt(delta))){
            long long ps=-b+sqrt(delta),ms=-b-sqrt(delta);
            long long psa=ps/gcd(2*a,ps),msa=ms/gcd(2*a,ms);
            if(psa%(2*a)==0)
            
            //if(up/2*a==1)printf("%d\n",);
            //else printf("%lld/%lld\n",up,2*a/up);
        }
        else printf("-1/2*sqrt(%d)+3/4\n",delta);
    }
    return 0;
}