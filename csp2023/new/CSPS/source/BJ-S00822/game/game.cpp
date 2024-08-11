#include <bits/stdc++.h>*
using namespace std;
#define int long long
const int maxn = 2e6+6;
set<int> f[maxn];
string s;
signed main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin>>n>>s;
    f[0].insert(0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        f[i].insert(i);
        for(auto j = f[i-1].begin();j!=f[i-1].end();j++)if(*j != 0 && s[i-1] == s[*j-1])for(auto k = f[*j-1].begin();k!=f[*j-1].end();k++)f[i].insert(*k);
        ans += f[i].size() - 1;
    }
    cout<<ans<<endl;
    return 0;
}
