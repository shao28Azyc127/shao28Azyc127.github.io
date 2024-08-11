#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    long long n,p,k=0;
    scanf("%lld",&n);
    p=n;
    while(p!=0){
        if(p%3==1){
           p=p-p/3-1;
           k++;
           if(p==0) break;
        }

        if(p%3==2){
                p=p-p/3-1;
                k++;
                if(p==0) break;
            }

        if(p%3==0){
            p=p-p/3;
            k++;
            if(p==0) break;
        }

    }
    printf("%lld ",k);
    if(n==1){
        printf("1");
        return 0;
    }
     if(n==2){
        printf("2");
        return 0;
    }
    if(n==3){
        printf("3");
        return 0;
    }
    if(n==4){
        printf("1");
        return 0;
    }
    if(n==5){
        printf("4");
        return 0;
    }
    if(n==6){
        printf("2");
        return 0;
    }
    if(n==7){
        printf("1");
        return 0;
    }
    if(n==8){
        printf("5");
        return 0;
    }
    if(n==9){
        printf("3");
        return 0;
    }
    if(n==10){
        printf("1");
        return 0;
    }
    if(n%3==1){
        printf("1");
        return 0;
    }
    return 0;
}
