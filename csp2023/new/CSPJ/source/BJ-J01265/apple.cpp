#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e6+5;
int jieduan = 1, ans, size_;
int a[N];
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    bool flag = true;
    size_ = n;
    while (size_ != 0) {
        int b = size_;
        for (int i = 1; i <= b; i += 3) {
            a[i] = 1e9+5;
            if (i == b && flag) {
                ans = jieduan;
                flag = !flag;
            }
            size_--;
        }
        sort (a + 1, a + size_ + 1);
        jieduan++;
    }
    cout << jieduan - 1 << " " << ans;
    return 0;
}
