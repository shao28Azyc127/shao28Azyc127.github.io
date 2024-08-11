#include <bits/stdc++.h>
using namespace std;

int n, ans1, ans2;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n){
        ans1++;
        if(n % 3 == 1 && !ans2) ans2 = ans1;
        n -= (n - 1) / 3 + 1;
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}
