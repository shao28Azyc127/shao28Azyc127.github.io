#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int N = 3005;
inline void read(int &x) {
    x = 0; int f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f *= -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    x *= f;
}
string S[N], T[N];
int pMin[N], sMin[N];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> S[i], T[i] = S[i];
    if (n == 1) { cout << "1" << '\n'; return 0; }
    for (int i = 1; i <= n; i++) sort(S[i].begin(), S[i].end()), T[i] = S[i], reverse(S[i].begin(), S[i].end());
    // for (int i = 1; i <= n; i++) {
    //     cout << S[i] << ' ' << T[i] << endl;
    // }
    pMin[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (S[i] < S[pMin[i - 1]]) pMin[i] = i;
        else pMin[i] = pMin[i - 1];
    }
    sMin[n] = n;
    for (int i = n - 1; i; i--) {
        if (S[i] < S[sMin[i + 1]]) sMin[i] = i;
        else sMin[i] = sMin[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 && T[i] < S[sMin[i + 1]]) cout << '1';
        else if (i == n && T[i] < S[pMin[i - 1]]) cout << '1';
        else if (1 < i && i < n && T[i] < min(S[sMin[i + 1]], S[pMin[i - 1]])) cout << '1';
        else cout << '0';
    }
    cout << '\n';
    return 0;
}