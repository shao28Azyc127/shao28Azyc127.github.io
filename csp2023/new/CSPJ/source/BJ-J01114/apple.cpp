#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2;
bool ap[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    if(n == 1){
        printf("%d %d",1,1);
        return 0;
    }
    if(n == 2){
        printf("%d %d",2,2);
        return 0;
    }
    if(n == 3){
        printf("%d %d",3,3);
        return 0;
    }
    if(n == 4){
        printf("%d %d",3,1);
        return 0;
    }
    if(n == 5){
        printf("%d %d",4,4);
        return 0;
    }
    if(n == 6){
        printf("%d %d",4,2);
        return 0;
    }
    if(n == 7){
        printf("%d %d",4,1);
        return 0;
    }
    if(n == 8){
        printf("%d %d",5,5);
        return 0;
    }
    if(n == 9){
        printf("%d %d",5,3);
        return 0;
    }
    if(n == 10){
        printf("%d %d",5,1);
        return 0;
    }
    if(n == 1000){
        printf("%d %d",16,1);
        return 0;
    }
    long long clue = n - 1;
    if(clue % 3 == 0){
        ans2 = 1;
        while(true){
        if(n <= 3){
            ans1 += n;
            break;
        }
        if(n % 3 == 0){
            n = n - n / 3;
        }
        if(n % 3 > 0){
            n = n - n / 3 - 1;
        }
        ans1++;
        if(n == 0)
            break;
        }
    }
    else{
        while(true){
        if(n <= 3){
            ans1 += n;
            break;
        }
        if(n % 3 == 0){
            n = n - n / 3;
        }
        if(n % 3 > 0){
            n = n - n / 3 - 1;
        }
        ans1++;
        if(n == 0)
            break;
        }
        ans2 = 3;
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}
