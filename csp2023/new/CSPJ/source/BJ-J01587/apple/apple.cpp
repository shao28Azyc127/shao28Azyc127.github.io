#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    LL n;
    scanf("%lld", &n);
    int cnt = 0, ans = -1;
    while(n > 0){
        //printf("%lld\n", n);
        cnt++;
        if(ans == -1){
            if(n % 3 == 1){
                ans = cnt;
            }
        }
        n -= (LL)ceil(1.0 * n / 3.0);
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}