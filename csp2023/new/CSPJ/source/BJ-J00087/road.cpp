#include <bits/stdc++.h>

using namespace std;

int n, m, mn = 2e9, x, s, sum;
int a[100009];
int b[100009];

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mn = min (mn, a[i]);
    }

    if (mn == a[1]) {
        if (sum % m == 0) sum /= m;
        else sum = sum / m + 1;
        s = sum * mn;
        cout << s;
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (i == 1) {
            s += b[i] / m * a[i];
            x = a[i];
        }
        else {
            if (a[i] >= a[i - 1] && a[i + 1] >= a[i])
                s += b[i] / m * x;
            if (a[i] >= a[i - 1] && a[i] > a[i + 1])
                s += b[i] / m * x;
            if (a[i] < a[i - 1] && a[i + 1] >= a[i]) {
                s += b[i] / m * a[i];
                x = min (x, a[i]);
            }
            if (a[i] < a[i - 1] && a[i] > a[i + 1])
                s += b[i] / m * a[i];
        }
    }

    cout << s;

    return 0;
}
