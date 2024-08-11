#include<bits/stdc++.h>
using namespace std;
struct node {int x, t; };
int n, m, k, ans, mx;
bool cc;
queue<node> q;
vector<node> mp[10004];
bool bfs(int tm) {
    while(!q.empty()) q.pop();
    q.push({1, tm});
    while(!q.empty()) {
        node a = q.front();
        q.pop();
        int rx = a.x, zx = a.t;
        if(zx - tm >= 1000 & cc) break;
        else if(zx >= 10000) break;
        for(int i = mp[rx].size() - 1; ~i; --i) {
            node b = mp[rx][i];
            if(b.t > zx) continue;
            q.push({b.x, zx + 1});
            if(b.x == n && !((zx + 1) % k)) {
                ans = zx + 1;
                return 1;
            }
        }
    }
    return false;
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = m; i; --i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        mp[a].push_back({b, c});
        mx = mx > c ? mx : c;
        if(c) cc = 1;
    }
    //cout<<111111<<endl;
    for(int i = 0; i - k < mx; i += k) {
        //cout<<i<<endl;
        if(bfs(i)) {
            printf("%d", ans);
            return 0;
        }
    }
    printf("-1");
    return 0;
}