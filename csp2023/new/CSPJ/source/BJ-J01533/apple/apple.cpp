#include <bits/stdc++.h>
using namespace std;

int n;

void f() {
    int m = n, cnt = 0;
    while (m) {
        m -= (m + 2) / 3;
        cnt++;
    }
    cout << cnt << " ";
}

void g() {
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    vector<int> tim(n + 1, -1);
    int ans = 0;
    while (a.size() > 0) {
        int cnt = 0;
        ans++;
        b.clear();
        for (int x: a) {
            if (cnt) b.push_back(x);
            else tim[x] = ans;
            cnt = (cnt + 1) % 3;
        }
        a = b;
    }
    cout << tim[n] << "\n";
}

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    f();
    g();
    return 0;
}

// g++ apple.cpp -o apple && ./apple
// expected 90pts

// Good Luck.