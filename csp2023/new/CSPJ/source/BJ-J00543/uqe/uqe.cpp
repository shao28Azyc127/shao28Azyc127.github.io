#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    for (int i = 1;i <= t;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        double delta = 1.0 * b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO" << endl;
            continue;
        }
        if (delta == 0) {
            double ans = (-b) / (2 * a) * 1.0;
            if (ans == ceil(ans)) {
                cout << (int)ans << endl;
            }
            else {
                cout << -b << "/" << (2 * a) << endl;
            }
        }
        if (delta > 0) {
            double x1 = ((-b) + sqrt(delta)) / (2 * a);
            double x2 = ((-b) + sqrt(delta)) / (2 * a);
            if (x1 > x2) {
                double ans = (-b) / (2 * a) * 1.0;
                if (ans == ceil(ans)) {
                    cout << (int)ans << "+";
                }else {
                    cout << -b << "/" << (2 * a) << "+";
                }
                cout << sqrt(delta) << "/" << (2 * a) << endl;
            }
            else {
                double ans = (-b) / (2 * a) * 1.0;
                if (ans == ceil(ans)) {
                    cout << (int)ans << "-";
                }else {
                    cout << -b << "/" << (2 * a) << "-";
                }
                cout << sqrt(delta) << "/" << (2 * a) << endl;
            }
        }
    }
    return 0;
}