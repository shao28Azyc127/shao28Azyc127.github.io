#include<bits/stdc++.h>
using namespace std;
long long t, a, b, c, tr, ans;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        tr = b * b - 4 * a * c;
        if (tr < 0) printf("NO");
        else {
			ans = (-1 * b + sqrt(tr)) / (2 * a);
			printf("%lld\n", ans);
		}
    }
    return 0;
}
