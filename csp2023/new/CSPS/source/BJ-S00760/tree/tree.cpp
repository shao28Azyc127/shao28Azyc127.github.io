#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, inf = 1e9;
int n, a[N], b[N], c[N];
bool check(int mid) {
    for(int i = 1; i <= n; i++) {
        ll days = mid - i;
        long long up = max(b[i] * days + (ll)(i + n - 1) * (n - i - 1) * c[i] / 2, days);
        if(up < a[i]) return false;
    }
    return true;
}
int BinarySearch(int l, int r) {
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
    printf("%d\n", BinarySearch(n + 1, (int)1e9)); 
    return 0;
}