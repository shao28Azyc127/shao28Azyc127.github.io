#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;
int c, t;
int n, m, k, d;
struct task {
    int l, r, v;
} task[maxn];

int ans = 0;

void dfs(int id, string now) {
    if (id == n) {
        int nowans = 0;
        int maxcontinue = 0;
        for (int i = 1;i <= n + 1;i++) {
            if (i == n + 1) {
                if (maxcontinue > k) {
                    return;
                }
                break;
            }
            if (now[i - 1] == '1') {
                maxcontinue++;
            }
            else {
                if (maxcontinue > k) {
                    return;
                }
                maxcontinue = 0;
            }
        }
        for (int i = 1;i <= m;i++) {
            bool flag = 1;
            if (task[i].l <= 0) continue;
            for (int j = task[i].l;j <= task[i].r;j++) {
                if (now[j - 1] == '0') {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                nowans += task[i].v;
            }
        }
        for (int i = 1;i <= n;i++) {
            if (now[i - 1] == '1') {
                nowans--;
            }
        }
        ans = max(ans, nowans);
        return;
    }
    for (char i = '0';i <= '1';i++) {
        dfs(id + 1, now + i);
    }
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m >> k >> d;
        for (int i = 1;i <= m;i++) {
            int x, y, v;
            cin >> x >> y >> v;
            int l, r;
            l = x - y + 1, r = x;
            task[i].l = l, task[i].r = r, task[i].v = v;
        }
        dfs(0, "");
        cout << ans << endl;
    }
    return 0;
}
