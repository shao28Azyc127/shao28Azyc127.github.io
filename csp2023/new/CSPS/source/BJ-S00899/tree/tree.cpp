#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5 + 5;
int a[N], b[N], c[N];
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i < n; i ++)
    {
        int u, v; cin >> u >> v;
    }
    int mx = 0;
    for (int i = 1; i <= n; i ++)
    {
        int tot = 0, cnt = i;
        while (tot < a[i])
            cnt ++, tot += max(1, b[i] + c[i] * (cnt - i + 1));
        mx = max(mx, cnt);
    }
    cout << mx;

    return 0;
}
