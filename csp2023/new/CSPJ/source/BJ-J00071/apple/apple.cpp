#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    cin >> n;
    int cnt = 0, dn = 0, t = n, ls = n;
    if((ls - 1) % 3 == 0 && dn == 0){
        dn = 1;
    }
    while(t){
        if(t <= 3){
            cnt += t;
            if(dn == 0) dn = cnt;
            break;
        }
        int k = (t - 1) / 3 + 1;
        t -= k;
        cnt++;
        if((ls - 1) % 3 == 0 && dn == 0){
            dn = cnt;
        }
        ls -= k;
    }
    cout << cnt << ' ' << dn;
    return 0;
}
