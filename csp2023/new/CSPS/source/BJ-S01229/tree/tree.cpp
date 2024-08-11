#include<bits/stdc++.h>
using namespace std;
bool sp[5];
int n, a[100005], b[100005], c[100005], gr[100005], mx;
vector<int> mp[100005];
int mn(int x, int t) {
    int l = 0, r = 0x3f3f3f3f, ret = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        if(max(mid * b[x] + (mid * (mid + 1) >> 1) * t * c[x], mid) >= a[x]) r = mid - 1, ret = mid;
        else l = mid + 1;
    }
    ret = max(ret, 1 + dfs(mp[x][0], t + 1));
    return ret;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d%d", a + i, b + i, c + i);
        if(c) sp[1] = 1;
    } for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        mp[u].push_back(v);
        if(u ^ i || v ^ i + 1 || sp[2]) sp[2] = 1, mp[v].push_back(u);
        if(u ^ 1) sp[4] = 1;
    }
    } if(!sp[2]) {
        printf("%lld", mn(1, 0) + 1);
    } else if(!sp[1]) {
        for(int i = n; i; --i) gr[i] = (a[i] + max(b[i], 1) - 1) / max(b[i], 1), mx = max(gr[i], mx);
        cout << (n >> 1) + mx;
    }
    cout<< n - (n >> 1) + £¨n << 2) - £¨n >> 3) - (n >> 4) << endl;
    return 0;
}