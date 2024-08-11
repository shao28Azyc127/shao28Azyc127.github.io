#include <bits/stdc++.h>
using namespace std;
int indexx[32];
int gcd(int x, int y) {
    int ans;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    for (int i = 1;i <= min(x, y);i++) {
        if (x %i == 0&& y % i == 0) ans = i;
    }
    return ans;
}
int main() {
    freopen("uqe.in","r", stdin);
    freopen("uqe.out", "w", stdout);
    for (int i = 1;i <= 31;i++) {
        indexx[i] = i * i;
    }
    int t, q;
    cin >> t >> q;
    for (int z = 1;z <= t;z++) {
        int delta = 0;
        int a, b, c;
        cin >> a >> b >> c;
        delta = b * b - 4 * a * c;
        //cout << delta << " ";
        if (delta < 0) {
            cout << "NO" << endl;
            continue;
        } else {
            double deltta = sqrt(delta);
            int delttta = sqrt(delta);
            if (deltta == delttta) {
                int xxx = (sqrt(delta) - b);
                int xx = 2 * a;
                int dcg = gcd(xxx, xx);
                cout << xxx / dcg << "/" << xx / dcg << endl;
                //cout << xxx << " " << xx << " " << dcg;
                continue;
            } else {
                a *= 2;
                if (b != 0) {
                    cout << b << "+";
                }
                int deltime = 1;
                bool flag = false;
                for (int i = 2;i <= 31;i++) {
                    if (delta % indexx[i] == 0) {
                        delta /= i * i;
                        deltime *= i;
                        flag = 1;
                    }
                }
                bool flag2 = 0;
                if (flag == 1 && deltime % a == 0) {
                    deltime /= a;
                    flag2 = 1;
                } else flag = 0;
                if (flag) {
                    cout << deltime << "*sqrt(" << delta << ")";
                } else if (flag2) {
                    cout << deltime << "*sqrt(" << delta << ")/" << a;
                } //else
                cout << endl;
            }
        }
    }
}
