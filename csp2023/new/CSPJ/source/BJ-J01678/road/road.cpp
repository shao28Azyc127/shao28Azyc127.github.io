#include <bits/stdc++.h>
using namespace std;
long long n,d,v[100005] = {0},a[100005];
long long ans = 0,L = 0,minn = 100005,sum = 0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld", &n,&d);
    for(long long i = 1;i < n;i++){
        scanf("%lld", &v[i]);
        sum += v[i];
    }
    for(long long i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        if(a[i] < minn){
            minn = a[i];
        }
    }
    for(long long i = 1;i < n;i++){
        if(sum <= 0){
            break;
        }
        if(a[i] == minn){
            long long x = sum - L;
            if(x%d == 0){
                ans += (x/d)*a[i];
                printf("%lld", ans);
            }else{
                ans += (x/d+1)*a[i];
                printf("%lld", ans);
            }
            return 0;
        }
        long long cnt = v[i];
        for(long long j = i+1;j <= n;j++){
            if(a[j] <= a[i]){
                sum -= cnt;
                long long y = (cnt-L)/d;
                if((cnt-L)%d == 0){
                    ans+=y*a[i];
                }else{
                    ans+=(y+1)*a[i];
                    L = (y+1)*d-cnt+L;
                }
                i = j-1;
                break;
            }else{
                cnt+=v[j];
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
