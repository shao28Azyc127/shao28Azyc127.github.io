#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long ll;
int n; string s; ll ans;
// pair<ll, bool> Solve(int l, int r) {
//     // divide and conquere!!!
//     // bbccaabba
//     if(l >= r) return 0;
//     int mid = (l + r) / 2;
//     pair<ll, bool> L = Solve(l, mid), R = Solve(mid + 1, r);
//     ll ret = L.first + R.first;
//     int i = mid, j = mid + 1; ll cnt = 0; string t = s;
    
//     while(l <= i && j <= r && t[i] == t[j]) i--, j++;
//     ret += cnt;
// }
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n); cin >> s;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            string t = s.substr(i, j - i + 1);
            while(true) {
                bool flag = false;
                for(int k = 0; k + 1 < t.size(); k++) {
                    if(t[k] == t[k+1]) {
                        t.erase(k, 1);
                        t.erase(k, 1);
                        flag = true;
                    }
                }
                if(!t.size()) ans++;
                if(!t.size() || !flag) break;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}