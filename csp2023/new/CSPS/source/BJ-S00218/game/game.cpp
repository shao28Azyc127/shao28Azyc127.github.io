#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double db;
#define fi first
#define se second

const int N = 2e6+5;
const int inf = 1e9;
const int p = 1e9+7;


string s;
int n,f[N][27];
ll ans[N];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> n >> s;
    s = " "+s;

    for (int i = 1; i <= n; i++){
        f[i][s[i]-'a'] = i;

            int p = f[i-1][s[i]-'a'];
            // cout << p << endl;
            if (!p) continue;
            // cout << p << endl;
            ans[i] += ans[p-1]+1;
            if (p > 1) f[i][s[p-1]-'a'] = max(f[i][s[p-1]-'a'], p-1);
            for (int j = 0; j < 26; j++){
                f[i][j] = max(f[i][j],f[p-1][j]);
            }
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++){
        // cout << ans[i] << " ";
        sum += ans[i];
    }
    // cout << endl;
    cout << sum << endl;

    return 0;
}