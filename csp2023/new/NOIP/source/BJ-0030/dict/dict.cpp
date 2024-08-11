// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;

#ifndef RUIER
ifstream fin("dict.in");
ofstream fout("dict.out");
#define cin fin
#define cout fout
#endif

const int N = 3005;

int n, m, mn[N], mx[N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        mn[i] = 27;
        mx[i] = -1;
        for(int j = 0; j < m; ++j) {
            mn[i] = min(mn[i], int(s[j] - 'a'));
            mx[i] = max(mx[i], int(s[j] - 'a'));
        }
    }
    for(int i = 1; i <= n; ++i) {
        bool ok = true;
        for(int j = 1; j <= n; ++j) {
            if(i != j) {
                if(mn[i] >= mx[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << '1';
        else cout << '0';
    }
    cout << '\n';
    cout.flush();
    return 0;
}