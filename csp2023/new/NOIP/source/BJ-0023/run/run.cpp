#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int cas, T;
int n, m, k, d;
int px[maxn], py[maxn]; ll pw[maxn];
int tmp[maxn]; int len = 0;
vector<pair<int, ll>> adj[maxn];
struct TreeNode{
    ll mx; ll tag;
    TreeNode(ll mxmx = 0, ll tagtag = 0){
        mx = mxmx; tag = tagtag;
    }
};
const ll inf = 0x3f3f3f3f3f3f3f3fll;
TreeNode t[maxn << 2];
void pushup(int p){
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
    return ;
}
void build(int p, int l, int r){
    t[p].tag = 0;
    if(l == r){
        t[p].mx = -inf; return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
    pushup(p); return ;
}
void lazy(int p, ll k){
    t[p].mx += k; return ;
}
void pushdown(int p){
    t[p << 1].tag += t[p].tag; t[p << 1 | 1].tag += t[p].tag;
    lazy(p << 1, t[p].tag); lazy(p << 1 | 1, t[p].tag);
    t[p].tag = 0; return ;
}
void mdf(int p, int pl, int pr, int l, int r, ll x){
    if(pl <= l && r <= pr){
        t[p].tag += x; lazy(p, x); return ;
    }
    int mid = (l + r) >> 1; pushdown(p);
    if(pl <= mid) mdf(p << 1, pl, pr, l, mid, x);
    if(pr > mid) mdf(p << 1 | 1, pl, pr, mid + 1, r, x);
    pushup(p); return ;
}
void upd(int p, int l, int r, int x, ll v){
    if(l == r){
        t[p].mx = v; return ;
    }
    int mid = (l + r) >> 1; pushdown(p);
    if(x <= mid) upd(p << 1, l, mid, x, v);
    if(x > mid) upd(p << 1 | 1, mid + 1, r, x, v);
    pushup(p); return ;
}
ll g[maxn];
#define fi first
#define sc second
#define mkp make_pair
int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> cas >> T;
    while(T--){
        cin >> n >> m >> k >> d; len = 0;
        for(int i = 1;i <= m;i++){
            cin >> px[i] >> py[i] >> pw[i];
            tmp[++len] = px[i] - py[i] + 1; tmp[++len] = px[i] + 1;
        }
        sort(tmp + 1, tmp + len + 1);
        len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
        // cerr << " ? ";
        // for(int i = 1;i <= len;i++) cerr << tmp[i] << " ";
        // cerr << endl;
        for(int i = 1;i <= len;i++) adj[i].clear();
        for(int i = 1;i <= m;i++){
            int pL = lower_bound(tmp + 1, tmp + len + 1, px[i] - py[i] + 1) - tmp;
            int pR = lower_bound(tmp + 1, tmp + len + 1, px[i] + 1) - tmp;
            // cerr << "add : " << pL << " " << pR << endl;
            adj[pR - 1].emplace_back(pL, pw[i]);
        }
        int now = 1; build(1, 1, len - 1);
        g[0] = 0;
        for(int i = 1;i < len;i++){
            g[i] = max(g[i - 1], t[1].mx);
            // cerr << i << " : " << g[i] << endl;
            upd(1, 1, len - 1, i, g[i - 1]);
            mdf(1, 1, i, 1, len - 1, -1ll * d * (tmp[i + 1] - tmp[i]));
            // cerr << "mx : " << t[1].mx << endl;
            while(now <= i && tmp[i + 1] - tmp[now] > k){
                // cerr << now << endl;
                upd(1, 1, len - 1, now, -inf); now++;
            }
            for(auto pfr : adj[i]){
                mdf(1, 1, pfr.fi, 1, len - 1, pfr.sc);
            }
        }
        // cerr << g[len - 1] << endl;
        cout << max(g[len - 1], t[1].mx) << '\n';
    }
    cout.flush(); return 0;
}
