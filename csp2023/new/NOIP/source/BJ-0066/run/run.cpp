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

const int N = 2e5 + 5;
const ll inf = 1e16;

struct SegT {
    #define ls id << 1
    #define rs id << 1 | 1
    #define mid (l + r >> 1)
    
    ll t[N << 2], tag[N << 2];

    void pu(int id) { t[id] = max(t[ls], t[rs]); }
    void pd(int id) {
	if(tag[id]) {
	    t[ls] += tag[id], t[rs] += tag[id];
	    tag[ls] += tag[id], tag[rs] += tag[id];
	    tag[id] = 0;
	}
    }

    void upd(int id, int l, int r, int x, int y, ll v) {
	if(x <= l && r <= y) {
	    tag[id] += v;
	    t[id] += v;
	    return ;
	}
	pd(id);
	if(mid >= x) upd(ls, l, mid, x, y, v);
	if(mid < y) upd(rs, mid + 1, r, x, y, v);
	pu(id);
    }

    ll qry(int id, int l, int r, int x, int y) {
	if(x <= l && r <= y) return t[id];
	pd(id); ll res = -inf;
	if(mid >= x) res = max(res, qry(ls, l, mid, x, y));
	if(mid < y) res = max(res, qry(rs, mid + 1, r, x, y));
	return res;
    }
} t;

int testnumber, T;
int n, m, k, d;
vector<pii > mis[N];

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> testnumber >> T;

    if(testnumber == 17 || testnumber == 18) {
	while(T--) {
	    cin >> n >> m >> k >> d;
	    ll ans = 0;
	    rep(i, 1, m) {
		int x, y, v;
		cin >> x >> y >> v;
		ll nw = -1ll * d * y + v;
		if(y <= k) ans += max(0ll, nw);
	    }
	    cout << ans << '\n';
	}
	return 0;
    }
    
    while(T--) {
	cin >> n >> m >> k >> d;
	memset(t.t, 0, sizeof t.t);
	memset(t.tag, 0, sizeof t.tag);
	rep(i, 1, n) mis[i].clear();
	rep(i, 1, m) {
	    int x, y, v;
	    cin >> x >> y >> v;
	    mis[x].pb(mp(y, v));
	}
	rep(i, 1, n) sort(mis[i].begin(), mis[i].end());
	t.upd(1, 0, n + k, n + 1, n + k, -inf);
	rep(i, 1, n) {
	    int nl = n - i, nr = nl + k;
	    // rep(j, nl + 1, nr + 1) cout << t.qry(1, 0, n + k, j, j) << ' ';
	    // cout << '\n';
	    ll mx = t.qry(1, 0, n + k, nl + 1, nr + 1);
	    t.upd(1, 0, n + k, nl, nl, mx);
	    t.upd(1, 0, n + k, nl + 1, nr, -d);
	    ll sum = 0; int las = 0;
	    for(pii x : mis[i]) {
		if(nl + las > nr) break;
		if(las == x.fi) {
		    sum += x.se;
		    continue;
		}
		if(sum) t.upd(1, 0, n + k, nl + las, min(nr, nl + x.fi - 1), sum);
		las = x.fi;
		sum += x.se;
	    }
	    if(nl + las <= nr) t.upd(1, 0, n + k, nl + las, nr, sum);
	}
	cout << t.qry(1, 0, n + k, 0, k) << '\n';
    }
    return 0;
}
