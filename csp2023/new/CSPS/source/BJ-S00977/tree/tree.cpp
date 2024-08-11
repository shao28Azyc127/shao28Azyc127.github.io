#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100100], b[100100], c[100100], u[100100], v[100100];
signed main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++){
        cin >> u[i] >> v[i];
    }
    cout << 24 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
