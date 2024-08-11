#include <bits/stdc++.h>
using namespace std;
long long n,a[10000005] = {0},ans = 0,ansn = 0,sum,cnt = 1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld", &n);
    sum = n;
    while(sum){
        cnt = 1;
        if(a[n] == 0){
            ansn++;
        }
        for(long long i = 1;i <= n;i++){
            if(a[i] == 0){
                if(cnt == 1){
                    a[i] = -1;
                    sum--;
                }
                cnt++;
                if(cnt == 4){
                    cnt = 1;
                }
            }
        }
        ans++;
    }
    printf("%lld %lld", ans,ansn);
    return 0;
}