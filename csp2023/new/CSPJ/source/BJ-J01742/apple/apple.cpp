#include <bits/stdc++.h>
using namespace std;
int n, nn, ans = 0, second_ans = 0;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    nn = n;
    while(nn>=1) {
        if(nn%3==0)
            nn = nn/3*2;
        else {
            nn = nn/3*2+(nn%3-1);
        }
        if(n%3!=1) {
            second_ans++;
            n = nn;
        }
        ans++;
    }
    cout << ans << ' ' << second_ans+1;
    return 0;
}
