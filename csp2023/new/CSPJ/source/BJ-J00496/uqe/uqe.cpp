#include <iostream>
using namespace std;

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m; cin >> t >> m;
    while (t--){
        int a, b, c; cin >> a >> b >> c;
        if (b == 0 && c == 0) cout << 0 << endl;
        else {
                int maxn = -214748364;
            for (int i = -m; i <= m; i++){
                if (a * i*i + b * i + c == 0) maxn = max(maxn, i);
            }
            if (maxn = -214748364) cout << "NO" << endl;
            else cout << maxn << endl;
        }
    }
return 0;}
