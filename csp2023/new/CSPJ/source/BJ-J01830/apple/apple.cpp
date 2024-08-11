#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans1, ans2;
int main() {

    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%lld", &n);
    for(long long i=1; n; i++) {
        if(n%3==1 && !ans2) ans2=i;
        if(n<4) n--;
        else n-=(n+2)/3;
        if(n==0) ans1=i;
    }

    printf("%lld %lld", ans1, ans2);

    return 0;
}
