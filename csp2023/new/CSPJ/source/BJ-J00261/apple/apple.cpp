#include <cstdio>
#include <vector>
using namespace std;

long long n;
vector<long long> v;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    long long cnt, ans;
    for (long long i = 1; i <= n; i++) {
        v.emplace_back(i);
    }
    for (cnt = 1; !v.empty(); cnt++) {
        // printf("day%lld\n    ", cnt);
        for (long long i = 0; i < v.size(); i += 2) {
            if (v[i] == n) {
                ans = cnt;
            }
            // printf("%lld ", v[i]);
            v.erase(v.begin() + i);
        }
        // printf("\n");
    }
    printf("%lld %lld\n", cnt - 1, ans);

    return 0;
}