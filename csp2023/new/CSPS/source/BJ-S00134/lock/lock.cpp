#include<bits/stdc++.h>
using namespace std;

const int NR = 8;
const int AR = 1e5;

int n, ans;
int a[NR + 5][5], cnt[AR + 5];
vector<int> b[NR + 5];

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 1; k <= 9; k++) {
                a[i][j] = (a[i][j] + 1) % 10;
                int x = 0;
                for(int l = 0; l < 5; l++) {
                    x = x * 10 + a[i][l];
                }
                b[i].emplace_back(x);
            }
            a[i][j] = (a[i][j] + 1) % 10;
        }
        for(int j = 0; j < 4; j++) {
            for(int k = 1; k <= 9; k++) {
                a[i][j] = (a[i][j] + 1) % 10;
                a[i][j + 1] = (a[i][j + 1] + 1) % 10;
                int x = 0;
                for(int l = 0; l < 5; l++) {
                    x = x * 10 + a[i][l];
                }
                b[i].emplace_back(x);
            }
            a[i][j] = (a[i][j] + 1) % 10;
            a[i][j + 1] = (a[i][j + 1] + 1) % 10;
        }
        sort(b[i].begin(), b[i].end());
        unique(b[i].begin(), b[i].end());
        for(int x : b[i]) {
            cnt[x]++;
        }
    }
    for(int i = 0; i < AR; i++) {
        if(cnt[i] == n) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}