#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        int tmp;
        tmp = b * b - 4 * a * c;
        if (tmp < 0) cout << "NO" << "\n";
        if (tmp == 0) cout << -1 * b * 1.0 / (2 * a) << "\n";
    }
    return 0;
}
