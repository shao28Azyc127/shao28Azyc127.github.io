#include <iostream>
#include <cstdio>
using namespace std;

//int a[10000001];
int used[10000001];

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, cnt = 0;
    cin >> n;
    //for (int i = 1; i <= n; i++) {
    //    a[i] = i;
    //}
    int ans1 = 1, ans2 = 0;
    while (cnt < n) {
        int cur = 2;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                if (cur == 2) {
                    cur = 0;
                    used[i] = true;
                    cnt++;
                    if (i == n) ans2 = ans1;
                }
                else cur++;
            }
        }
        ans1++;
    }
    cout << ans1 - 1 << " " << ans2 << endl;
    return 0;
}
