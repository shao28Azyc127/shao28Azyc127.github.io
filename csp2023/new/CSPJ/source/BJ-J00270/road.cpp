#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("road1.in","r",stdin);
    freopen("road1.ans","w",stdout);
    freopen("road2.in","r",stdin);
    freopen("road2.ans","w",stdout);
    int n, d, dis[100005], mon[100005], nmax = 100005, diss = 0;
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++) {
        cin >> dis[i];
        diss += dis[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> mon[i];
        if (mon[i] < nmax) nmax = mon[i];
    }

    if (nmax == mon[1]) {
        if (diss % d == 0) {
            cout << mon[1] * diss / d;
        } else cout << mon[1] * (diss / d + 1);
    }
    return 0;
}
