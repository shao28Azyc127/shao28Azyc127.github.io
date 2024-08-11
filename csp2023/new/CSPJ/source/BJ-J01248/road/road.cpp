#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long a[N], b[N], sum[N];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    long long n, d;
    scanf("%lld%lld", &n, &d);
    for(int i = 1; i <= n - 1; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    for(int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
    long long ans = 0, cnt = 0;
    if(a[1] % d == 0)ans += (a[1] / d * b[1]), cnt = a[1];
    else ans += ((a[1] / d + 1) * b[1]), cnt = (a[1] / d + 1) * d;
    long long tmp = b[1];
    for(int i = 2; i <= n - 1; i++){
        if(tmp > b[i]){
            if((sum[i] - cnt) % d == 0){
                ans += ((sum[i] - cnt) / d * b[i]);
                cnt = sum[i];
            }else{
                ans += (((sum[i] - cnt) / d + 1) * b[i]);
                cnt = cnt + ((sum[i] - cnt) / d + 1) * d;
            }
            tmp = b[i];
        }else{
            if((sum[i] - cnt) % d == 0){
                ans += ((sum[i] - cnt) / d * tmp);
                cnt = sum[i];
            }else{
                ans += (((sum[i] - cnt) / d + 1) * tmp);
                cnt = cnt + ((sum[i] - cnt) / d + 1) * d;
            }
        }
    }
   printf("%lld", ans);
   return 0;
}
