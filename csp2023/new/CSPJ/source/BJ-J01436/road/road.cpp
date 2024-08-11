#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

long long n, d, cnt, m = N;
int a[N], b[N];

int main() {
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        if (m > b[i]) {
            m = b[i];
        }
        cnt += (a[i] + d - 1) / d * m;
        a[i + 1] -= (a[i] + d - 1) / d * d - a[i];
        while (a[i] < 0) {
            a[i + 1] += a[i];
            i++;
        }
    }
    cout << cnt;
    return 0;
}
