#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    long long m = n;
    int res = 0;
    int sum = 0;
    bool l = false;
    while(n!=0){
        int t = n/3;
        if(n%3!=0)t++;
        res++;
        if((n-1)%3==0&&l==false){
            sum = res;
            l = true;
        }
        n-=t;
    }
    printf("%d %d",res,sum);

    return 0;
}
