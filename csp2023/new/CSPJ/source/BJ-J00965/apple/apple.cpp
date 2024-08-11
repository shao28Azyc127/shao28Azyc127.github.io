#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int n, ans = 0, ans1;
bool a[1000000005] = {1};

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int i = 1, f = 0;
    while (i <= n) {
        if (!a[i]) continue;
        for (int j = i, cnt = 0; j <= n;) {
            if (a[j] == true) cnt++ ;
            if (cnt == 3) {
                a[cnt] = false;
                break;
            }
        }
        ans++;
        i++;
        if (a[n] == false && f == 0) {
            ans1 = ans - 1;
            f = 1;
        }

    }
    cout << ans - 1 << " " << ans1;
    return 0;
}