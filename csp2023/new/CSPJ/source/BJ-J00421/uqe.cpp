#include <bits/stdc++.h>
using namespace std;
int T,m;
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&m);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(m<=1 && b==0 && a==0){
            if(c>0) puts("NO");
            else{
                if(c==0)
                    puts("0");
                else if(c==-1)
                    puts("2");
                else printf("2*sqrt(%d)",-c);
            }
            continue;
        }
        int x=b*b-4*a*c;
        if(x<0){
            puts("NO");
            continue;
        }
        int y=sqrt(x);
        if(y*y==x){
            int z=gcd(-b+y,2*a);
            if(2*a%z==0) printf("%d\n",(y-b)/z);
            else printf("%d/%d\n",(y-b)/z,2*a/z);
            continue;
        }
        if(-b/2/a!=0){
            int z=gcd(-b,2*a);
            if(2*a%z==0) printf("%d+",(-b)/z);
            else printf("%d/%d+",(-b)/z,2*a/z);
        }
        if(1/2/a==1){
            printf("sqrt(%d)",x);
        }
        else{
            if(1/2/a==int(1/2/a)){
                printf("%d*sqrt(%d)",1/2/a,x);
            }
            else{
                if(2*a==int(2*a)) printf("sqrt(%d)/%d",x,2*a);
            }
        }
        puts("");
    }
    return 0;
}