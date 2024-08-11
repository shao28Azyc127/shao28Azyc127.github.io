#include<bits/stdc++.h>
using namespace std;

const int NR = 2e6;

int n;
long long ans;
int a[NR + 5], fa[NR + 5], dep[NR + 5], mx[NR + 5][26];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - 'a';
    }
    for(int i = 1; i <= n; i++) {
        int j = mx[i - 1][a[i]];
        if(j > 0) {
            fa[i] = j - 1;
            dep[i] = dep[j - 1] + 1;
            for(int c = 0; c < 26; c++) {
                mx[i][c] = mx[j - 1][c];
            }
        }
        mx[i][a[i]] = i;
        ans += dep[i];
    }
    cout << ans << '\n';

    return 0;
}