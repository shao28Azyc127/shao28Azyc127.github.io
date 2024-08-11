#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100000005];
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    for (long long i = 1;i <= n;i++) {
        a[i] = i;
    }
    int a1 = 1, a2 = 0;
    while (1) {
        int cnt = 0;
        for (long long i = 1;i <= n;i++) {
            if (a[i] != 0) {
                cnt++;
                if (cnt % 3 == 1) {
                    if (a[i] == n) {
                        a2 = a1;
                    }
                    a[i] = 0;
                }
            }
        }
        if (cnt == 0) {
            a1--;
            break;
        }
        a1++;
    }
    cout << a1 << " " << a2;
    return 0;
}