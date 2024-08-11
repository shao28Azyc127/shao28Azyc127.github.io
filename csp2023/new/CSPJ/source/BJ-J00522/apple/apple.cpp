#include<bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x*10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int days = 0, ansn = n;
    while (n > 0) {
        n = n - (n+2) / 3;
        days++;
    }
    n = ansn, ansn = 0;
    while (n % 3 != 1) {
        n = n - (n+2) / 3;
        ansn++;
    }
    cout << days << ' ' << ansn + 1<< endl;
    return 0;
}
