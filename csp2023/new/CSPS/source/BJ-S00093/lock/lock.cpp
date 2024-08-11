#include <bits/stdc++.h>
#define ll long long
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;
int n, cnt = 0, a;
vector<int> v[10];
bool test(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
    int lcnt = 0;
    if (a == f) {
        ++lcnt;
    }
    if (b == g) {
        ++lcnt;
    }
    if (c == h) {
        ++lcnt;
    }
    if (d == i) {
        ++lcnt;
    }
    if (e == j) {
        ++lcnt;
    }
    if (lcnt == 4) {
        return true;
    } else {
        return false;
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &a);
            v[i].push_back(a);
        }
        //scanf("%d%d%d%d%d", &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5]);
    }
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            for (int c = 0; c <= 9; ++c) {
                for (int d = 0; d <= 9; ++d) {
                    for (int e = 0; e <= 9; ++e) {
                        bool f = true;
                        for (int i = 1; i <= n; ++i) {
                            if (!test(a, b, c, d, e, v[i][0], v[i][1], v[i][2], v[i][3], v[i][4])) {
                                f = false;
                                break;
                            }
                        }
                        if (f) {
                            ++cnt;
                        }
                    }
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
