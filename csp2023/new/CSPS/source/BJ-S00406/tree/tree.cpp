#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Edge{
    int to, nxt;
};
struct tree{
    int num, ned;
};
int n, ce, ans;
int a[10010];
int b[10010];
int c[10010];
int fa[10010];
int ned[10010];
int sze[10010];
tree tre[10010];
int deep[10010];
int head[10010];
bool vis[10010];
bool book[10010];
Edge edge[20010];
stack<int> st;
void Add_edge(int u, int v) {
    edge[ce].to = v;
    edge[ce].nxt = head[u];
    head[u] = ce++;
}
bool cmp(tree x, tree y) {
    return x.ned > y.ned;
}
void dfs_init(int x) {
    for(int i=head[x]; ~i; i=edge[i].nxt) {
        int y = edge[i].to;
        if(y==fa[x]) continue;
        fa[y] = x;
        //deep[y] = deep[x] + 1;
        dfs_init(y);
    }
}
int countday(int x, int s) {
    int high = 0;
    for(int i=0; ;++i) {
        high += max(b[x]+(s+i)*c[x], 1ll);
        if(high>=a[x]) return i;
    }
}
void dfs(int x, int maxx) {
    if(x==n+1) {
        cout << "reach" << '\n';
        ans = min(ans, maxx); return;
    }
    for(int i=1; i<=n; ++i) {
        if(book[i] &&!vis[i]) {
            for(int j=head[i]; ~j; j=edge[j].nxt) if(edge[j].to!=fa[i]) book[edge[j].to] = true;
            vis[i] = true;
            dfs(x+1, max(maxx, x+countday(i, x)));
            vis[i] = false;
            for(int j=head[i]; ~j; j=edge[j].nxt) if(edge[j].to!=fa[i]) book[edge[j].to] = false;
        }
    }
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    memset(head, -1, sizeof(head));
    cin >> n;
    ans = 0x7fffffff;
    bool flag = true;
    bool flag1 = true;
    for(int i=1; i<=n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        if(c[i]!=0) flag = false;
        ned[i] = (a[i]+max(1ll, b[i])-1)/max(1ll, b[i]);
    }
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        if(u!=i || v!=i+1) flag1 = false;
        Add_edge(u, v);
        Add_edge(v, u);
    }
    dfs_init(1);
    if(flag1) {
        for(int i=1; i<=n; ++i) ans = max(ans, countday(i, i-1)+i);
        cout << ans;
        return 0;
    }
    if(flag) {
        for(int i=1; i<=n; ++i) tre[i].ned = ned[i], tre[i].num = i;
        book[1] = true;
        ans = ned[1];
        int cnt = 0;
        sort(tre+1, tre+n+1, cmp);
        for(int i=1; i<=n; ++i) {
            int ths = tre[i].num;
            while(!book[ths]) {
                st.push(ths);
                ths = fa[ths];
            }
            while(!st.empty()) ans = max(ans, ned[st.top()]+(++cnt)), st.pop();
        }
        cout << ans;
        return 0;
    }
    book[1] = 1;
    dfs(1, 0);
    //cout << n << '\n';
    cout << ans;
    return 0;
}
