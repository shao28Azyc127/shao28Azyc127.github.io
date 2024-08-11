#include <bits/stdc++.h>
using namespace std;
int n; bool vis[1000005];
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    int cnt = 0, last = 0, ans = 0;
    while(true) {
        int mod = 0; ans++;
        for(int i = 1; i <= n; i++)  {
            if(vis[i]) continue ;
            if(mod == 0) vis[i] = true, cnt++;
            if(mod == 0 && i == n) last = ans;
            if(cnt == n) {
                printf("%d %d\n", ans, last);
                return 0;
            }
            mod = (mod + 1) % 3;
        }
    }
    return 0;
}