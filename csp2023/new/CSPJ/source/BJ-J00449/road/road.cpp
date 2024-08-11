// The writer CANNOT prove this method is right, but it passed all of the data.

#include <cstdio>
using namespace std;

int n, d;
int v[100010], a[100010];
long long sum[100010];

int cur = 0;
int stats[100010]; // stop at these stations

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + v[i];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int last = 2e9;
    for (int i = 1; i <= n; i++)
        if (a[i] < last) {
            stats[++cur] = i;
            last = a[i];
        }

    stats[++cur] = n;
    long long dist = 0, cost = 0;
    for (int i = 1; i < cur; i++) {
        long long db = sum[stats[i + 1]] - sum[stats[i]];
        long long add = (db - dist + d - 1) / d;
        dist += add * d - db;
        cost += add * a[stats[i]];
    }
    printf("%lld\n", cost);
    return 0;
}
