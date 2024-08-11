#include <bits/stdc++.h>
#define LL long long
using namespace std;

struct Node {int b[10];};
int a[10][10];
vector<Node> vec;

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++) cin >> a[i][j];
    for (int i = 1; i <= 5; i++) 
        for (int j = 1; j <= 9; j++) {
            Node tmp;
            for (int k = 1; k <= 5; k++) tmp.b[k] = a[1][k];
            (tmp.b[i] += j) %= 10;
            vec.push_back(tmp);
            if (i != 5) {
                (tmp.b[i + 1] += j) %= 10;
                vec.push_back(tmp);
            }
        }
    int ans = 0;
    for (auto x : vec) {
        bool flag = 1;
        for (int i = 2; i <= n; i++) {
            int pos = 0, d;
            for (int j = 1; j <= 5; j++) {
                if (a[i][j] == x.b[j]) continue;
                if (!pos) d = (a[i][j] - x.b[j] + 10) % 10, pos = j + 1;
                else if (pos == j) {
                    if (d == (a[i][j] - x.b[j] + 10) % 10) pos = -1;
                    else {flag = 0; break;}
                }
                else {flag = 0; break;}
            }
            if (pos == 0) flag = 0;
            if (!flag) break;
        }
        if (flag) ans++;
    }
    cout << ans << '\n';
    return 0;   
}