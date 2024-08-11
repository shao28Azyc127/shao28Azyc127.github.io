#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("uqe1.in","r",stdin);
    freopen("uqe1.ans","w",stdout);
    freopen("uqe2.in","r",stdin);
    freopen("uqe2.ans","w",stdout);
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= t; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (b == 0 && c == 0) cout << "0" << endl;
        else cout << "NO";
    }
    return 0;
}
