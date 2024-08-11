#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;

#define int long long

const int maxn = 10;

int n;
int a[maxn][10];

int ans1 = 0;
int ans2 = 0;

set<int> cnt[100010];

int fixnum(int x) {
    if (x >= 10) return x % 10;
    if (x < 0) return x + 10;
}

signed main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= 5;j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= 5;j++) {
            for (int k = 0;k <= 9;k++) {
                if (k == a[i][j]) continue;
                int now = 0;
                for (int m = 1;m <= 5;m++) {
                    if (m != j) {
                        now = now * 10 + a[i][m];
                    }
                    else {
                        now = now * 10 + k;
                    }
                }
                cnt[now].insert(i);
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= 4;j++) {
            for (int dlt = -9;dlt <= 9;dlt++) {
                if (dlt == 0) continue;
                int x = fixnum(a[i][j] + dlt), y = fixnum(a[i][j + 1] + dlt);
                int now = 0;
                for (int m = 1;m <= 5;m++) {
                    if (m == j) {
                        now = now * 10 + x;
                    }
                    else if (m == j + 1) {
                        now = now * 10 + y;
                    }
                    else {
                        now = now * 10 + a[i][m];
                    }
                }
                cnt[now].insert(i);
            }
        }
    }
    int ans=0;
    for (int i = 0;i <= 99999;i++) {
        if (cnt[i].size() == n) {
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

