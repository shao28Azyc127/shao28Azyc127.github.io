#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m; cin >> T >> m; while (T--){
        int a, b, c; cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0){cout << "NO\n"; continue;}
        int num = (-b + int(sqrt(b * b - 4 * a * c) + 0.01)) / (2 * a);
        cout << num << endl;
    }
}
