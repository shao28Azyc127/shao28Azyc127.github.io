#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, ans, ans1, now;
signed main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    now = n;
    while(now){
        ans++;
        int x = (now - 1) / 3 + 1;
        if((now - 1) % 3 == 0 && !ans1)ans1 = ans;
        now -= x;
    }
    cout << ans <<" " << ans1;
    return 0;
}
