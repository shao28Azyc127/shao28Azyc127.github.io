#include <bits/stdc++.h>
#define N 100005
using namespace std;
struct apple {
    int id;
    bool del = false;
} a[N];
int n, cnt = 0, nn, cnt2 = 0;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n; nn = n;
    for (int i = 1; i <= n; i++) a[i].id = i;
    while (n) {
        n -= ceil(n/3.0);
        cnt++;
    }
    if (nn % 3 == 1) {
        cout << cnt << ' ' << 1;
        return 0;
    }
    n = nn;
    while (n) {
        n -= ceil(n/3.0);
        int tmp = 0;
        for (int i = 1; i <= nn; i++) {
            if (a[i].del == 0) {
                if (tmp == 3) tmp = 0;
                if (tmp == 0) a[i].del = 1;
                tmp++;
            }
        }
        cnt2++;
        if (a[nn].del) break;
    }
    cout << cnt << ' ' << cnt2;
    return 0;
}
