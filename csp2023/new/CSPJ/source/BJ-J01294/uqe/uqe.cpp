#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,g;scanf("%d%d",&t,&m);
    double f,p,q;
    for(int i=1;i<=t;++i){
        scanf("%d%d%d",&a,&b,&c);
        if(b*b-4*a*c<0)printf("NO\n");
        else{
            f=(double)(-b+sqrt(b*b-4*a*c))/(2*a);
            p=f;q=1;
            p*=(2*a);
            q*=(2*a);
            g=gcd(max(int(p),int(q)),min(int(p),int(q)));
            p/=g;
            q/=g;
            if(q==1)printf("%d",int(p));
            else{
                if(q<=0){
                    p=-p;
                    q=-q;
                }
                printf("%d/%d",int(p),int(q));
            }
        }
    }
    return 0;
}
