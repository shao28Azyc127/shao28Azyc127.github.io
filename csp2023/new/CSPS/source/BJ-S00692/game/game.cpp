#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
int n; char s[maxn];
ll f[maxn];
int a[maxn];
int pf[maxn];
int las[maxn][26];
int b[maxn];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> (s + 1);
    for(int i = 1;i <= n;i++){
        a[i] = s[i] - 'a';
    }
    // cerr << endl;
    for(int i = 0;i < 26;i++) las[n + 1][i] = n + 1;
    for(int i = n;i >= 1;i--){
        int pt = las[i + 1][a[i]];
        // cerr << pt << " ";
        if(pt != n + 1){
            f[i] = 1 + f[pt + 1];
            for(int j = 0;j < 26;j++) las[i][j] = las[pt + 1][j];
            las[i][a[i]] = i; continue;
        }
        for(int j = 0;j < 26;j++) las[i][j] = n + 1;
        las[i][a[i]] = i;
    }
    // cerr << endl;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ans += f[i]; // cerr << f[i] << " ";
    }
    // cerr << endl;
    cout << ans << endl; return 0;
}
