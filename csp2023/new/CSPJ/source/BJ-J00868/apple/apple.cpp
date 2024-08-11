#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long n;
    cin >> n;
    long long days = 0;
    // cout << n << endl;
    bool flag = 0;
    long long res = 0;
    while (n > 0) {
        ++days;
        if (!flag && (n - 1) % 3 == 0) res = days, flag = true;
        n -= 1 + (n - 1) / 3;
        // cout << n << endl;
    }
    cout << days << ' ' << res << endl;
    return 0;
}