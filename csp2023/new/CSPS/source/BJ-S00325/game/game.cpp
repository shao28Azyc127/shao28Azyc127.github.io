#include <bits/stdc++.h>
using namespace std;
//35pts?
int n;
long long ans;
string s;
stack<char> a;
inline void check(int x, int y) {
    while(a.size()) a.pop();
    for (int i = x; i < y; i++) {
        if (a.size() && a.top() == s[i]) a.pop();
        else a.push(s[i]);
    }
    if (!a.size()) ans++;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            check(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}