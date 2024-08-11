#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
int t, c, n, m, sized;
int didnum[MAXN], didc[MAXN], start[MAXN];
bool done[MAXN];
bool flag = 0;
vector<pair<int, int> > Adj[MAXN];

void dfs(int u, int num) {
    int sz = Adj[u].size();
    for(int i = 0; i < sz; i++) {
        int v = Adj[u][i].first;
        int w = Adj[u][i].second;
        if(done[v]) continue;
        done[v] = 1;
        start[v] = w * num;
        dfs(v, w * num);
    }
}

int dfs2(int u, int num) {
    int cnt = 1;
    int sz = Adj[u].size();
    for(int i = 0; i < sz; i++) {
        int v = Adj[u][i].first;
        int w = Adj[u][i].second;
        if(done[v]) {
            if(w * num != start[v]) flag = 1;
            continue;
        }
        done[v] = 1;
        start[v] = w * num;
        cnt += dfs2(v, w * num);
    }
    return cnt;
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d ", &c, &t);
    while(t--) {
        cin >> n >> m;
        memset(didc, 0, sizeof(didc));
        memset(done, 0, sizeof(done));
        memset(start, 0x3f, sizeof(start));
        for(int i = 1; i <= n; i++) {
            didnum[i] = i;
            Adj[i].clear();
        }
        for(int i = 1; i <= m; i++) {
            char c;
            cin >> c;
            if(c == '+') {
                int a, b;
                cin >> a >> b;
                didnum[a] = didnum[b];
                didc[a] = didc[b];
            } else if(c == '-') {
                int a, b;
                cin >> a >> b;
                didnum[a] = -didnum[b];
                didc[a] = -didc[b];
            } else {
                int a;
                cin >> a;
                didnum[a] = 0;
                if(c == 'T') didc[a] = 1;
                if(c == 'F') didc[a] = -1;
                if(c == 'U') didc[a] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(didnum[i] == 0) continue;
            Adj[i].push_back(make_pair(abs(didnum[i]), didnum[i] / abs(didnum[i])));
            Adj[abs(didnum[i])].push_back(make_pair(i, didnum[i] / abs(didnum[i])));
        }
        for(int i = 1; i <= n; i++) {
            if(done[i] == 0 && didnum[i] == 0) {
                done[i] = 1;
                start[i] = didc[i];
                dfs(i, didc[i]);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n ;i++)
            if(start[i] == 0) ans++;
        for(int i = 1; i <= n; i++) {
            if(done[i] == 0) {
                sized = 0;
                done[i] = 1;
                start[i] = -1;
                flag = 0;
                int a = dfs2(i, -1);
                if(flag == 1) ans += a;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
