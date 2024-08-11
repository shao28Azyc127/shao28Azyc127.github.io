#include<iostream>
#include<cstdio>
#include<string>
#define maxn 2000005 //2e6+5
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int n, l[maxn][30], r[maxn]; int f[maxn]; long long ans; 
string s;

signed main() {
    fopen("game");
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    cin >> s;
    s = " " + s;
    l[1][s[1] - 96] = 1;
    for(int i = 2; i <= n; i++) {
        r[i] = l[i - 1][s[i] - 96];
        if(r[i]) {
            f[i] = f[r[i] - 1] + 1;
            for(int j = 1; j <= 26; j++) {
                l[i][j] = l[r[i] - 1][j];
            }
        }
        l[i][s[i] - 96] = i;
        ans += f[i];
    }
    cout << ans << '\n';
}