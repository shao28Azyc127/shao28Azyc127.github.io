#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long  n;
    long long  b;
    long long sum[10005];
    long long k;
    sum[3]=4;
    scanf("%lld",&n);
    if(n<4)cout<<n<<" ";
    else if(n==4)cout<<3<<" ";
    else for(int i=4;i<=n;i++){
        sum[i]=sum[i-1]+i;
        if(n<sum[i]){
            printf("%lld ",i);
            k=i;
            break;
        }
    }if(n<=3)b=n;
    else if(n%3==1)b=1;
    else if(n%3==0)b=n/3;
    else if(n%3==2)b=k;
    printf("%lld",b);
   return 0;
}
