#include<bits/stdc++.h>
using namespace std;
//CSP-J 2023 RP ++ !!!;
int n, d, v[100010], a[100010], p[100010], minp, tot;
long long sum[100010], cnt, last, zc, ans;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; i ++){
        scanf("%d", &v[i]);
        sum[i + 1] = sum[i] + v[i];
    }
//   for(int i = 1; i <= n; i ++){
//       cout << sum[i] << " ";
//   }
//   cout << endl;
    minp = 100010;
    for(int i = 1; i < n; i ++){
        scanf("%d", &a[i]);
        if(a[i] < minp){
            p[++ tot] = i;
            minp = a[i];
        }
    }
    scanf("%d", &a[n]);
    p[++ tot] = n;
//   for(int i = 1; i <= tot; i ++){
//       cout << p[i] << " ";
//   }
//   cout << endl;
    for(int i = 1; i < tot; i ++){
        cnt = sum[p[i + 1]] - sum[p[i]];
        zc = ceilf((cnt - last) / float(d));
        ans += a[p[i]] * zc;
        last += zc * d - cnt;
//        cout << "last" << last << " cnt" << cnt << " zc" << zc << " ans" << ans << endl;
    }
    printf("%lld", ans);
    return 0;
}
