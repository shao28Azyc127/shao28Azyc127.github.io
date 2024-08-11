#include <iostream>
#include <cstdio>
int a[100];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,b,r,t=0;
    scanf("%d",&n);
    r=n;
    while(n){
        b=n;
        n-=n/3;
        if(b%3!=0)--n;
        ++t;
    }
    printf("%d ",t);
    if(r%3==1)printf("1");
    else printf("%d",t);
}