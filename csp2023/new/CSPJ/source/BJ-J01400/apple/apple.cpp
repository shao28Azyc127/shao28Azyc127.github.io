#include <cstdio>
#define ll long long
using namespace std;

ll n;
ll fir, tot;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    while (n) {
        tot++;
        if (!fir && ((n - 1) % 3 == 0)) fir = tot;
        n -= (n - 1) / 3 + 1;
    }
    printf("%lld %lld\n", tot, fir);
    return 0;
}
