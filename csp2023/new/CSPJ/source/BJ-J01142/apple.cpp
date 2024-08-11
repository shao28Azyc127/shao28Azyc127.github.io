#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9 + 5;
bool a[MAXN];
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    bool flag = true;
    while(flag) {
        ans1++;
        flag = false;
        int cnt = 0;
        bool sum = false;
        for(int i = 1; i <= n; i++) if(!a[i]) {
            if(sum) {
                cnt++;
                if(i == n) ans2 = ans1;
                if(cnt == 3) {
                    a[i] = true;
                    cnt = 0;
                }
            } else {
                if(i == n) ans2 = ans1;
                a[i] = true;
                sum = true;
            }
        }
        for(int i = 1; i <= n; i++) if(!a[i])
            flag = true;
    }
    cout << ans1 << " " << ans2;
    return 0;
}