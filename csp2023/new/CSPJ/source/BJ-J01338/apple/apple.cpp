#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, cnt = 1, ans;
bool flag = 0;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
    scanf("%lld", &n);
    while (n > 0) {
	    if (n % 3 != 1 && !flag) cnt++;
        if (n % 3 == 1) flag = 1;
        n -= ((n - 1) - (n - 1) % 3) / 3 + 1;
        ans++;
    }
    printf("%lld %lld", ans, cnt);
    return 0;
}
