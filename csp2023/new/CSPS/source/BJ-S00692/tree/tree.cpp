#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
vector<int> adj[maxn];
int ff[maxn];
bool pfl[maxn];
void dfs(int now, int fa){
    ff[now] = fa; pfl[now] = 1;
    for(auto t : adj[now]){
        if(t == fa) continue;
        dfs(t, now); pfl[now] = 0;
    }
    return ;
}
ll a[maxn], b[maxn], c[maxn];
ll tt[maxn];
priority_queue<pair<ll, int>> pq;
typedef long double ldb;
ll cal(int id, ll lim){
    ll pans = 0;
    if(c[id] == 0){
        pans = lim - ((a[id] + b[id] - 1) / b[id]) + 1;
        if(pans <= 0) return -1;
        return pans;
    }
    if(c[id] > 0){
        if(n > 30000){
            ldb ka = c[id]; ldb kb = -c[id] * (2ll * lim + 1) - 2ll * b[id]; ldb kc = 2ll * a[id];
            ldb dt = kb / (2.0 * ka);
            dt = dt * dt;
            dt = dt - kc / ka;
            if(dt < 0) return -1;
            dt = -sqrtl(dt);
            dt = dt - (kb / (2.0 * ka));
            dt = ceil(dt);
            // if(dt <= lim) cerr << fixed << setprecision(1) << dt << endl;
            if(dt > lim) return -1;
            return lim - dt + 1;
        }
        ll pl = 1, pr = lim; ll ret = -1;
        while(pl <= pr){
            ll mid = (pl + pr) >> 1;
            if(2ll * b[id] + c[id] * (2ll * lim - mid + 1) >= (2ll * a[id] + mid - 1) / mid){
                ret = mid; pr = mid - 1;
            } else {
                pl = mid + 1;
            }
        }
        if(ret == -1) return -1;
        pans = lim - ret + 1;
    } else if(c[id] < 0){
        ll pct = (b[id] - 1) / (-c[id]);
        if(lim - pct >= a[id]){
            pans = lim - a[id] + 1;
        } else {
            if(n > 30000){
                ldb ka = -c[id]; ldb kb = c[id] * (2ll * pct + 1) + 2ll * b[id]; ldb kc = -2ll * a[id];
                ldb dt = kb / (2.0 * ka);
                dt = dt * dt;
                dt = dt - kc / ka;
                if(dt < 0) return -1;
                dt = -sqrtl(dt);
                dt = dt - (kb / (2.0 * ka));
                dt = ceil(dt);
                // if(dt <= lim) cerr << fixed << setprecision(1) << dt << endl;
                if(dt > pct) return -1;
                return pct - dt + 1;
            }
            ll pm = a[id] - (lim - pct);
            ll pl = 1, pr = pct; ll ret = -1;
            while(pl <= pr){
                ll mid = (pl + pr) >> 1;
                if(2ll * b[id] + c[id] * (2ll * pct - mid + 1) >= (2ll * pm + mid - 1) / mid){
                    ret = mid; pr = mid - 1;
                } else {
                    pl = mid + 1;
                }
            }
            if(ret == -1) return -1;
            pans = pct - ret + 1;
        }
    }
    return pans;
}
bool chk(ll lim){
    if(cal(1, lim) == -1) return 0;
    while(!pq.empty()) pq.pop();
    for(int i = 1;i <= n;i++){
        if(pfl[i]){
            ll pans = cal(i, lim);
            if(pans == -1) return 0;
            pq.push(make_pair(pans, i));
        }
    }
    for(int i = n;i >= 2;i--){
        pair<ll, int> pfr = pq.top();
        int pu = pfr.second;
        pq.pop();
        if(pfr.first < i) return 0;
        if(ff[pu] != 1){
            ll pans = cal(ff[pu], lim);
            if(pans == -1) return 0;
            pq.push(make_pair(pans, ff[pu]));
        }
    }
    return 1;
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1;i < n;i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    int l = n, r = 1000000000; int res = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)){
            res = mid; r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}
