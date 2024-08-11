#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int t = n, ans = 0;
    while(t > 0) {
        ans++;
        t -= ceil(t / 3.0);
    }
    int u = 1;
    bool a[n + 1];
    for(int i = 1; i <= n; i++) a[i] = true;
    while(u <= n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] != false) cnt++;
            if(cnt % 3 == 1) {
                a[i] = false;
            }
        }
        if(a[n] == false) {
            cout << ans << " " << u << endl;
            return 0;
        }
        u++;
    }
    return 0;
}