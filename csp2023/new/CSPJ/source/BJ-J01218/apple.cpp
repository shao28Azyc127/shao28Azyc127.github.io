#include <bits/stdc++.h>
using namespace std;
int n, tmp, ans, sum;
bool flag;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n, tmp = n;
    while(tmp) {
        ans++;
        if(tmp % 3 == 1 && !flag) sum = ans, flag = 1;
        tmp -= (tmp + 2) / 3;
    }
    cout << ans << " " << sum;
    return 0;
}
