#include <iostream>
#include <map>

using namespace std;

int n;

struct node {
    int a[6];
    string ot() {
        string res = "";
        for (int i = 1; i <= 5; i ++ ) {
            res += char(a[i] + '0');
        }
        return res;
    }
};

map<string, int> sd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        node x;
        for (int j = 1; j <= 5; j ++ ) {
            cin >> x.a[j];
        }
        for (int j = 1; j <= 4; j ++ ) {
            for (int k = 1; k <= 9; k ++ ) {
                node ne = x;
                ne.a[j] += k;
                ne.a[j] %= 10;
                ne.a[j + 1] += k;
                ne.a[j + 1] %= 10;
                sd[ne.ot()] ++;
                res += (sd[ne.ot()] == n);
            }
        }
        for (int j = 1; j <= 5; j ++ ) {
            for (int k = 1; k <= 9; k ++ ) {
                node ne = x;
                ne.a[j] += k;
                ne.a[j] %= 10;
                sd[ne.ot()] ++;
                res += (sd[ne.ot()] == n);
            }
        }
    }
    cout << res << '\n';
    cout.flush();
    return 0;
}