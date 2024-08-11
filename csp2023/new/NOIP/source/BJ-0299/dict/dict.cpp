#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 10;
int n, m;
char mn[N], mx[N], s[N];

bool chk(int x) {
    for(int i = 1; i <= n; i++) if(i != x && mn[x] >= mx[i]) return false;
    return true;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s + 1;
        sort(s + 1, s + m + 1);
        mn[i] = s[1], mx[i] = s[m];
    }
    for(int i = 1; i <= n; i++) cout << chk(i);
    cout << '\n';
    return 0;
}