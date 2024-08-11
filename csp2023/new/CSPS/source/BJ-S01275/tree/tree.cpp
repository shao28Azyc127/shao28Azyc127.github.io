#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
#define int long long
using namespace std;
ll b[MAXN];
ll c[MAXN];
ll a[MAXN];
ll chk_day(int id, int i, int t){
    if(c[id] < 0){
        int hig = (b[id] - 1) / -c[id];
      //  if(id == 4 && i == 3 && t == 5) cout << "y" << hig << endl;
        if(i > hig){
            return t - i + 1;
        }
        if(t > hig){
            ll ans = b[id] * (hig - i + 1) + c[id] * (i + hig) * (hig - i + 1) / 2 + t - hig;
            return ans;
        }
    }
    __int128 x = (__int128)b[id] * (t - i + 1) + (__int128)c[id] * (i + t) * (t - i + 1) / 2;
    if(x >= a[id]) return a[id] + 1;
    return b[id] * (t - i + 1) + c[id] * (i + t) * (t - i + 1) / 2;
}
int ask_day(int id, int ed){
    int L = 1, R = ed;
    int ans = 0;
    while(L <= R){
        int mid = (L + R) / 2;
        if(chk_day(id, mid, ed) >= a[id]){
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return ans;
}
int need = 0;
struct Node{
    int id, tim;
};
Node cnt[MAXN];
int vis[MAXN];
int anc[MAXN];
int cmp(Node a, Node b){
    return a.tim < b.tim;
}
int find_fa(int u){
    int cost_tim = 0;
    while(vis[u] == 0){
        cost_tim++;
        vis[u] = 1;
        u = anc[u];
    }
    return cost_tim;
}
    int n;
int check(int mid){
    for(int i = 1; i <= n; i++){
        cnt[i].tim = ask_day(i, mid);
        cnt[i].id = i;
        vis[i] = 0;
    }
    sort(cnt + 1, cnt + 1 + n, cmp);
    int ctime = 0;
    vis[0] = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        int u = cnt[i].id, tim = cnt[i].tim;
        int tf = find_fa(u);
   //     if(mid == 5) cout << u << "jump to" << tf << endl;
        if(tf + ctime > tim){
      //      if(mid == 5) cout << u << "wrong" <<" " << tim<< endl;
            return 0;
        }
        ctime += tf;
    }
    return 1;
}
struct Edge{
    int next, v;
};
Edge edge[MAXN * 2];
int head[MAXN];
int tot = 0;
void add_edge(int u, int v){
    ++tot;
    edge[tot].next = head[u];
    edge[tot].v = v;
    head[u] = tot;
}
//vector<int> adj[MAXN];
void dfs(int u, int fa){
    anc[u] = fa;
  //  cout << u << "-" << fa << endl;
    for(int i = head[u]; i; i = edge[i].next){
        int v = edge[i].v;
        if(v == fa) continue;
        dfs(v, u);
    }
}
signed main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    int L = 1, R = 1e9;
    int ans = 0;
  //  cout <<"x" <<  chk_day(4, 3, 5) << endl;
  //  cout << check(33577724) << endl;
    while(L <= R){
        int mid = (L + R) / 2;
        if(check(mid)){
            ans = mid;
            R = mid - 1;
        } else {
          //  cout << mid << "=np" << endl;
            L = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
