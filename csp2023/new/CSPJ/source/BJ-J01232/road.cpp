#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

ll a[N];
ll v[N];
ll n, d;
ll mi = LONG_LONG_MAX;
ll now1, now2;
int num;
ll ans;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%lld%lld", &n, &d);
    for(int i=2; i<=n; i++){
        scanf("%lld", &v[i]);
        v[i] += v[i-1];
    }
    for(int i=1; i<=n; i++)
        scanf("%lld", &a[i]);
    a[n] = -1;

    for(int i=1; i<=n; i++){
        if(a[i]<mi){
            now1 = v[i] / d + (v[i] % d != 0);
            ans += (now1 - now2) * a[num];
            now2 = now1;
            num = i;
            mi = a[i];
        }
    }

    printf("%lld", ans);

    return 0;
}
