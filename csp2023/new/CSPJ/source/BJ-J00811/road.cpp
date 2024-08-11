#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, d;
int w[N], dis[N];
ll sum[N];

int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> d;

    for (int i = 1; i < n; i ++ ) {
        cin >> dis[i];
        sum[i] = sum[i - 1] + dis[i];
    }

    for (int i = 1; i <= n; i ++ ) {
        cin >> w[i];
    }

    int l = 1, r = 1;
    ll ans = 0, add = 0;

    while (l < n) {
        while ( r < n && w[l] <= w[r]) r ++ ;
        r -- ;
        ll len = sum[r] - sum[l - 1] - add;
        add = 0;
        ll oil;
        if (len % d == 0) oil = len / d;
        else oil = (len + d) / d, add += oil * d - len;

        //cout << l << " " << r << " " << len << " " << oil << " " << add << endl;
        ans += oil * w[l];
        //cout << ans << endl;

        l = r + 1;
        r ++ ;
    }

    cout << ans << endl;

    return 0;
}

