#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
struct num{
    int x,y;// x/y
};
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int prime[1005];
int m,p,u,v;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    scanf("%d%d",&t,&m);
    for(int i=2;i<=2000;i++){
        bool f=1;
        if(i%2==0||i%3==0){
            f=0;
            continue;
        }
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                f=0;
                break;
            }
        }
        if(f) prime[p++]=i;
    }
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int d=b*b-4*a*c;
        if(d<0){
            printf("NO\n");
            continue;
        }
        num a1;
        a1.x=(-b);
        a1.y=(2*a);
        if(d==0){
           a1.x=a1.x/gcd(a1.x,a1.y);
           a1.y=a1.y/gcd(a1.x,a1.y);
           if(a1.y==1||a1.y==-1||a1.x==0){
              printf("%d\n",a1.x/a1.y);
           }
           else{
              if(a1.x<0&&a1.y<0){
                printf("%d/%d\n",-a1.x,-a1.y);
              }
              else if(a1.x>0&&a1.y<0){
                printf("%d/%d\n",-a1.x,a1.y);
              }
              else{
                printf("%d/%d\n",a1.x,a1.y);
              }
           }
        }
        if(ceil(sqrt(d*1.00)/1.00)==sqrt(d*1.00)/1.00){
            a1.x+=sqrt(d);
            a1.x=a1.x/gcd(a1.x,a1.y);
            a1.y=a1.y/gcd(a1.x,a1.y);
            if(a1.y==1||a1.y==-1||a1.x==0){
              printf("%d\n",a1.x/a1.y);
            }
            else{
              if(a1.x<0&&a1.y<0){
                printf("%d/%d\n",-a1.x,-a1.y);
              }
              else if(a1.x>0&&a1.y<0){
                printf("%d/%d\n",-a1.x,a1.y);
              }
              else{
                printf("%d/%d\n",a1.x,a1.y);
              }
            }
            continue;
        }
    }
    return 0;
}
