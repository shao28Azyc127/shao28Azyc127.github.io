#include <bits/stdc++.h>
using namespace std;

struct l {
    int id, day;
};
vector <l> v;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, days = 1, ans;
    bool flag = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        l t;
        t.id = i;
        t.day = 0;
        v.push_back(t);
    }
    while (flag) {
        //cout << "day " << days << ": ";
        flag = false;
        for (int i = 0, i2 = -1; i < n; i++) {
            if (v[i].day > 0) {
                //cout << "c(" << v[i].day << ") ";
            }
            else {
                i2++;
                flag = true;
                if (i2 % 3 == 0) v[i2].day = days;
                if (i == n - 1) ans = days;
                //cout << v[i2].day << " ";
            }
        }
        cout << endl;
        days++;
    }
    cout << days << " " << ans << endl;
    return 0;
}
