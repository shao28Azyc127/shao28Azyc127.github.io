#include <bits/stdc++.h>
using namespace std;

int a[100000005];

void init() {
    for (int i = 1; i <= 100005; i++) {
        if (!a[i]) {
            for (int j = i; j <= 100005; j += 3) {
                if (a[j]) {
                    j++;
                }
                a[j] = i;
            }
        }
    }
}

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    init();
    cout << a[n] << ' ';
    sort(a, a + n);
    cout << a[n];

    return 0;
}
