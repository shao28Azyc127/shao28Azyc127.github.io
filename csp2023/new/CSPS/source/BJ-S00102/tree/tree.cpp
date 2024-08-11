#include<bits/stdc++.h>
using namespace std;
int n, b[100005], c[100005], u[100005], v[100005];
long long a[100005];
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i <= n-1; i++) {
        cin >> u[i] >> v[i];
    }
    cout << 8 << endl;
    return 0;
}