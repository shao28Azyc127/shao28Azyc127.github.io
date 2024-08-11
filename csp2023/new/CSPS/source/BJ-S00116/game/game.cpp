#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define int long long
using namespace std;
int n,ans;
string s;
signed main(void) {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    if (n<=8000) {
        s="%"+s;
        for (int i=1;i<=n;i++) {
            vector<int> stk;
            for (int j=i;j<=n;j++) {
                if (stk.empty()) {
                    stk.push_back(s[j]);
                    continue;
                }
                if (s[j]==stk.back()) stk.pop_back();
                else stk.push_back(s[j]);
                if (stk.empty()) ans++;
            }
        }
        cout << ans;
    } else {
        s="%"+s;
        for (int i=1;i<=n;i++) {
            vector<int> stk;
            for (int j=i;j<=i+100;j++) {
                if (stk.empty()) {
                    stk.push_back(s[j]);
                    continue;
                }
                if (s[j]==stk.back()) stk.pop_back();
                else stk.push_back(s[j]);
                if (stk.empty()) ans++;
            }
        }
        cout << ans;
    }
    return 0;
}
