#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    ll ans = 0, k = -1;
    while (n) {
        ans++;
        if (n % 3 == 1 && k == -1) k = ans;
        n -= (n + 2) / 3;
    }
    printf("%lld %lld\n", ans, k);
    return 0;
}
