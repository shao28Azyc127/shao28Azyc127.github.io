#include<bits/stdc++.h>

using namespace std;

int n, cnt, ans=1, ans2;

const int MAXN = 1e9+10;
bool vis[MAXN];

bool checker() {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) return false;
    }
    return true;
}

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;
    cnt = 2;

    while(vis[n]!=1 || !checker()) {
        cnt = 2;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                cnt++;
                if(cnt==3) {
                    cnt=0;
                    vis[i] = 1;
                }
            }
        }
        if(vis[n]!=1) ans++;
        ans2++;
    }

    cout << ans2 << " " << ans;

    return 0;
}
