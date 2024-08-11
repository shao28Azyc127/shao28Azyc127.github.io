#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const size_t S = 100009;
const size_t R = 0x3c3c3c3c;

long long ceildiv(long long a, long long b) {
    if (a <= 0) return 0;
    if (a % b == 0) return a / b;
    return a / b + 1;
}

int main() {freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    int n, d, u[S], a[S];
    cin >> n >> d;
    for (int i = 0; i < n - 1; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long use_num[S] = {0};
    int x = n - 1;
    while (x > 0) {
        int minn = R;  // 0 ～ x 的最小油价
        long long cnt = 0;  // 最小油价处 ～ x 需要的油量
        int idx = -1;
        for (int i = x - 1; i >= 0; i--) {
            cnt += u[i];
            if (a[i] < minn) {
                minn = a[i];
                use_num[i] = cnt;
                x = i;
                if (idx != -1) {
                    use_num[idx] = 0;
                }
                idx = i;
            }
        }
    }

    long long ans = 0;
    long long tt = 0;  // 剩下的油长度
    for (int i = 0; i < n; i++) {
        long long cur = use_num[i];
        long long oil = ceildiv(cur - tt, d);
        // cout << "step=" << i + 1 << "  oil=" << oil << "  tt=" << tt << "  use_num[i]=" << use_num[i] << endl;
        ans += oil * a[i];
        tt += oil * d - cur;
    }

    cout << ans;
}
