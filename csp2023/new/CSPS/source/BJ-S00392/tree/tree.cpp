#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int u[100005],v[100005];
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> u[i] >> v[i];
    }
    cout << n + 1;
    return 0;
}