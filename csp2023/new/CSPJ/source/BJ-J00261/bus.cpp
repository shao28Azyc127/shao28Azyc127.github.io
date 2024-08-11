#include <cstdio>
#include <vector>
using namespace std;

long long main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    long long n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<long long> v[10005];
    for (long long i = 0; i < m; i++) {
        long long x, y, t;
        scanf("%lld%lld%lld", &x, &y);
        v[x].push_back(y);
    }
    long long start_time = k;
    long long now_time = k;
    long long now_node = 1;
    printf("-1\n");

    return 0;
}