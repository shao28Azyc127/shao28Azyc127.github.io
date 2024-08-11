#include <bits/stdc++.h>
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 3005;

int n, m;
int cnt[N][30];
int mn[N], mx[N];

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) {
	char c; cin >> c;
	++cnt[i][c - 'a'];
    }
    rep(i, 1, n) {
	rep(j, 0, 25) if(cnt[i][j]) {
	    mn[i] = j;
	    break;
	}
	per(j, 25, 0) if(cnt[i][j]) {
	    mx[i] = j;
	    break;
	}
    }
    rep(i, 1, n) {
	int f = 1;
	rep(j, 1, n) {
	    if(i == j) continue;
	    if(mn[i] >= mx[j]) {
		f = 0;
		break;
	    }
	}
	cout << f;
    }
    cout << '\n';
    return 0;
}
