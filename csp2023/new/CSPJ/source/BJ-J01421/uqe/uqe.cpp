#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int t,m;
double a,b,c,q1,q2,drt,sd,x1,x2;
void printgcd(int a,int b){
    int gcdab=__gcd(a,b);
    printf("%d %d",a/gcdab,b/gcdab);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%lf%lf%lf",&a,&b,&c);
        drt=b*b-4*a*c;
        if(drt<0){printf("NO\n");continue;}
        sd=sqrt(drt);
        int gcd=__gcd((int)(drt),(int)(2*a));
        if(sd*sd==drt){
            if(drt==0){
                x1=(-b+sd)/(2*a);
                if(abs(x1-(int)x1)<=1e-6)printf("%d\n",(int)x1);
                else printgcd((int)(-b+sd),(int)(2*a));
                printf("\n");
                continue;
            }
            x1=(-b+sd)/(2*a);
            x2=(-b-sd)/(2*a);
            if(x1>x2){
                if(abs(x1-(int)x1)<=1e-6)printf("%d\n",(int)x1);
                else printgcd((int)(-b+sd),(int)(2*a));
                printf("\n");
                continue;
            }
            else{
                if(abs(x2-(int)x2)<=1e-6)printf("%d\n",(int)x2);
                else printgcd((int)(-b-sd),(int)(2*a));
                printf("\n");
                continue;
            }
        }
        else{
            if(-b/(2*a)==(int)(-b/(2*a))){
                int gcd=__gcd((int)(drt),(int)(2*a));
                if(x1>x2){
                    if(drt/(2*a)==(int)drt/(2*a))printf("%d+sqrt(%d)\n",-b/(2*a),(drt/(2*a)));
                    else printf("%d+sqrt(%d)/%d\n",-b/(2*a),drt/gcd,2*a/gcd);
                }
                else{
                    if(drt/(2*a)==(int)drt/(2*a))printf("%d-sqrt(%d)\n",-b/(2*a),(drt/(2*a)));
                    else printf("%d-sqrt(%d)/%d\n",-b/(2*a),drt/gcd,2*a/gcd);
                }
                continue;
            }
            else{
                printgcd(-b,2*a);
                if(x1>x2){
                    if(drt/(2*a)==(int)drt/(2*a))printf("+sqrt(%d)\n",(drt/(2*a)));
                    else printf("+sqrt(%d)/%d\n",drt/gcd,2*a/gcd);
                }
                else{
                    if(drt/(2*a)==(int)drt/(2*a))printf("-sqrt(%d)\n",(drt/(2*a)));
                    else printf("-sqrt(%d)/%d\n",drt/gcd,2*a/gcd);
                }
                continue;
            }
        }
    }
    return 0;
}
