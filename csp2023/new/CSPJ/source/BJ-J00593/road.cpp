#include <cstdio>
#include <iostream>

using namespace std;

const int NR = 1e5 + 10;
long long v[NR];
int a[NR];

int st[NR];
int tt = -1;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    if(n == 1) {
        printf("0");
        return 0;
    }
    for(int i = 1; i < n; i++) {
        scanf("%lld", &v[i]);
        v[i] += v[i - 1];
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)
        if(tt < 0 || a[i] < a[st[tt]]) {
           // printf("# %d\n", i);
            st[++tt] = i;
        }
    // cout << tt << endl;
    long long ty = 0;
    long long ans = 0;
    for(int i = 0; i < tt; i++) {
        ty -= v[st[i] - 1] - v[st[i - 1] - 1];
        int temp = ((v[st[i + 1] - 1] - v[st[i] - 1] - ty) + d - 1) / d;
        // printf("!%d %d\n", st[i], temp);
        ans += temp * a[st[i]];
        ty += temp * d;
    }
    ty -= v[st[tt] - 1] - v[st[tt - 1] - 1];
    // printf("!%d %d\n", st[tt], ((v[n - 1] - v[st[tt] - 1] - ty) + d - 1) / d);
    ans += ((v[n - 1] - v[st[tt] - 1] - ty) + d - 1) / d * a[st[tt]];
    printf("%lld", ans);
    return 0;
}
