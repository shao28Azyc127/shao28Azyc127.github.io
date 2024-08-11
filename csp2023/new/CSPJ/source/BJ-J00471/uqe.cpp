//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<list>
#include<queue>
#include<stack>>
#include<list>
#include<vector>
#include<map>
using namespace std;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int check1(double x){
    for(int q=1;q<=1000;q++){
        if(int(q*x)==q*x){
            if(gcd(q,int(q*x))==1||gcd(q,int(q*x))==-1){
                return q;
            }
        }
    }
    return -1;
}
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int t=b*b-4*a*c;
        if(t<0){
            printf("NO");
        }else{
            double t1=(-b+sqrt(t*1.0))/(2.0*a);
            double t2=(-b-sqrt(t*1.0))/(2.0*a);
            double x=max(t1,t2);
            int q=check1(x);
            if(q!=-1||int(x)==x){
                if(q==1||int(x)==x){
                    printf("%d",int(x));
                }else{
                    printf("%d/%d",int(x*q),q);
                }
            }else{
            }
        }
        printf("\n");
    }
    return 0;
}

