#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n; cin >> n;
    int cnt = 0;
    int ans = 0;
    bool f = 0;
    while (n) {
        if ((n-1)%3 == 0) {
            if (!f)
                ans = cnt;
            f = 1;
        }
        cnt++;
        n -= (n-1)/3+1;
    }
    cout << cnt << " " << ans+1;
    return 0;
}