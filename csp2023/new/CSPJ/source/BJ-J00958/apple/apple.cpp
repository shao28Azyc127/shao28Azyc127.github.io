#include <cstdio>
using namespace std;
typedef long long LL;
LL r1 = 0, r2 = -1, n;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 0; n; i ++ ) {
        if (n % 3 == 1 && r2 == -1) r2 = i + 1;
        n = n - ((n - 1) / 3 + 1);
        r1++;
    }

    printf("%lld %lld\n", r1, r2);
    return 0;
}
