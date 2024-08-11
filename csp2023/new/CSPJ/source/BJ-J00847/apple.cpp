#include<bits/stdc++.h>
using namespace std;
long long n,a=0,b=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    while(n>0){
        int m=(n-1)/3+1;
        a++;
        if((n-1)%3==1&&b==0)b==a;
        n-=m;
    }
    printf("%d %d",a,b);
    return 0;
}