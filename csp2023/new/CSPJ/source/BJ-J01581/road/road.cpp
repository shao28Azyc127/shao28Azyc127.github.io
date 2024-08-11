#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("road2.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d %d", &n, &d);
    int v[n-1 + 15], a[n + 15];
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int cost[n + 15];
    for (int i = 1; i <= n-1; i++) {
        cost[i] = v[i] / d * a[i];
    }
    int lastcost = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cost[i] > cost[i+1]) {
            ans += cost[i];
        }
        else {
            int next;
            for (int j = i; j <= n; j++) {
                if (cost[j] < cost[i]) {
                    next = j;
                }
            }
            for (int j = i; j < next; j++) {
                ans += v[j] / d * a[i];
            }
        }
    }
    printf("%d", ans);
    return 0;
}