#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N] = {1};
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int x = 0, v = 0, h = n;
    while (h > 0) {
        int y = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (y >= 1 && y < 4) {
                y++;
                continue;
            }
            if (l == 0) {
                a[i] = 0;
                y++;
                l++;
                h--;
            }
            else {
                a[i] = 0;
                y = 1;
                h--;
            }
            if (i == n - 1 && a[i] == 0) {
                v = x;
            }
        }
        x++;
        sort(a, a + n, cmp);
    }
    cout << x << ' ' << v;
    return 0;
}