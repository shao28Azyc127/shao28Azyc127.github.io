#include <bits/stdc++.h>
using namespace std;

double v[100000], m[100000];

int main ()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    double n, money = 0, oil = 0;
    int cnt, num = 0, d, tmp;

    cin >> n >> d;
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < n; i += cnt) {
        num = v[i];
        cnt = 1;
        while (m[i + cnt] > m[i] || i + cnt >= n) {
            cnt++;
            num += v[i + cnt];
        }

        tmp = num - oil * d;

        if (tmp <= 0) {
            oil -= num * 1.0 / d;
        } else {
            money += ceil(tmp * 1.0 / d) * m[i];
            oil = (d - tmp % d) * 1.0 / d;
        }
    }

    cout << money;

    return 0;
}
//want to get 50~100pts
//oh my god,the freopen was wrong!