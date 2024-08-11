#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * w;
}
int n;
string s;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    s.push_back(0);
    vector<ll> siz (n+2), f(n+2), cnt(n+2), misiz(n+2);
    for (int i=n-1;i>=0;i--) {

        cnt[i] = (s[i] == s[i+1]) ? cnt[i+1] + 1 : 1; //cout << "i: " << i << " cnt: " << cnt[i] << endl;
        siz[i] = (s[i] == s[i+1]) ? 2 : 0;
        if (!siz[i]) siz[i] = max(siz[i], (s[i] == s[i+siz[i+1]+1]) ? siz[i+1] + 2 : 0);
        if (s[i] == s[i+siz[i+1]+1]) siz[i] = max(siz[i], siz[i+1] + 2);
        if (!siz[i]){
            if (s[i] == s[i+misiz[i+1]+1]) misiz[i] = misiz[i+1] + 2;
            if (misiz[i] % 2 == 0 && misiz[i] != siz[i]) f[i] += f[misiz[i] + i + 1] ;
            if (misiz[i] % 2 == 0) siz[i] = misiz[i];
            continue;
        }
        misiz[i] = siz[i];
        f[i] = 1;
        ll sum = 0, t = i + siz[i];
        if (cnt[i] >= 2) {
            sum += f[i + 2];
            misiz[i] = cnt[i];
        }
        else if (siz[t] != 0) {
            sum += f[t];
            if (s[i] == s[i+misiz[i+1]+1]) misiz[i] = misiz[i+1] + 2;
            if (misiz[i] % 2 == 0 && misiz[i] != siz[i]) sum += f[misiz[i] + i + 1] + 1;

        }

        f[i] += sum;
        cout << "i: " << i << " f[i]:" << f[i] << " siz[i]:" << siz[i] << " cnt[i]: " << cnt[i] << " mis: " << misiz[i] << endl;
    }
    ll ans = 0;
    //for (int i=0;i<=n-1;i += max (1LL, siz[i])) {
      //ans += f[i];
      //  if (siz[i]) ans += f[i+1];
   // }
    for (int i=0;i<n;i++) ans += f[i];
    //
    for (int i=0;i<n;i++) cout << f[i] << ' '; cout << endl;
    cout << ans << endl;

    return 0;
}
