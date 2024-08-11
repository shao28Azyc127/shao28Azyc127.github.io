#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005], v[100005];
signed main(){
    freopen("road.in", "r",  stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i < n; i++)
        scanf("%lld", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    int sum = 0, cost = a[1], left = 0;
    for (int i = 2; i <= n; i++){
        if (left >= v[i - 1]){
            left -= v[i - 1];
            if (a[i] < cost) cost = a[i];
            continue;
        }
        int D = v[i - 1] - left;
        left = 0;
        int t = D / d;
        if (D % d) t++;
        sum += t * cost;
        left += t * d - D;
        if (a[i] < cost) cost = a[i];
    }
    printf("%lld\n", sum);
    return 0;
}
