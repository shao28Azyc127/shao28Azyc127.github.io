#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, d, v[N], a[N]; ll cost;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; i++) scanf("%d", &v[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mn = a[1]; double oil = 0;
    for(int i = 1; i <= n; i++) {
        mn = min(mn, a[i]);
        double newcost = v[i] * 1.0 / d;
        if(newcost < oil) oil -= newcost;
        else newcost -= oil, oil = ceil(newcost) - newcost, cost += ceil(newcost) * mn;
    }
    printf("%lld\n", cost);
    return 0;
}