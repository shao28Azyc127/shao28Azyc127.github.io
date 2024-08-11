#include <bits/stdc++.h>
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)

using namespace std;

const int N = 1e6 + 5;

int n;
int a[10], pw[] = {0, 1, 10, 100, 1000, 10000, 100000};
bool v[N];

int g(int x, int y) { return (x + y) % 10; }
int gn(int x, int y) { return x / pw[y] % 10; }

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    rep(i, 1, n) {
	rep(j, 1, 5) {
	    int x; cin >> x;
	    a[i] = a[i] * 10 + x;
	}
    }
    int ans = 0;
    rep(i, 0, 99999) {
	rep(j, 1, 5) rep(k, 1, 9) v[i + pw[j] * (g(gn(i, j), k) - gn(i, j))] = 1;
	rep(j, 1, 4) rep(k, 1, 9) v[i + pw[j] * (g(gn(i, j), k) - gn(i, j)) + pw[j + 1] * (g(gn(i, j + 1), k) - gn(i, j + 1))] = 1;
	int f = 1;
	rep(j, 1, n) if(!v[a[j]] || i == a[j]) f = 0;
	rep(j, 1, 5) rep(k, 1, 9) v[i + pw[j] * (g(gn(i, j), k) - gn(i, j))] = 0;
	rep(j, 1, 4) rep(k, 1, 9) v[i + pw[j] * (g(gn(i, j), k) - gn(i, j)) + pw[j + 1] * (g(gn(i, j + 1), k) - gn(i, j + 1))] = 0;
	ans += f;
    }
    cout << ans << '\n';
    return 0;
}
