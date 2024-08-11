#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int v[N], a[N], mina[N];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; i ++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        mina[i] = 0;
        for (int j = 1; j < i; j ++) {
            if (mina[j] == 0 && a[i] < a[j]) {
                for (int k = j; k < i; k ++) {
                    mina[j] += v[k];
                }
            }
        }
    }
    // for (int i = 1; i <= n; i ++) printf("%d ", mina[i]);
    // printf("\n");
    int mon = 0, lu = 0, next = mina[1];
    for (int i = 1; i <= n; i ++) {
        if (i != 1) lu -= v[i - 1];
        if (lu < v[i]) {
            int t = ceil((mina[i] - lu) * 1.0 / d) * a[i];
            // printf("%d %d\n", i, lu);
            mon += t;
            lu += ceil((mina[i] - lu) * 1.0 / d) * d;
            // printf("%d %d %d\n", mon, lu, t);
        }
    }
    printf("%d", mon);
    return 0;
}