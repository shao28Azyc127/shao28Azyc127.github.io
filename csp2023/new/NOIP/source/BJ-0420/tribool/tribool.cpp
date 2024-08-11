#include<bits/stdc++.h>
#define inf -0x7ffffff
using namespace std;
int n, m;
queue<int> q;
stack<int> stck;
int tp[100010];
bool vis[100010];
bool book[100010];
int realf[100010];
int st[100010][20];
//vector<int> edge[100010];
int mp[255];
//-1 T
//-2 F
//-3 U
//-4 +
//-5 -
void init() {
    for(int i=1; i<=n; ++i) {
        tp[i] = 1;
        st[i][1] = i;
        realf[i] = inf;
        book[i] = false;
    }
}
int dfs(int x) {//return 0 = U
    if(realf[x]!=inf) return realf[x];
    if(book[x]) return realf[x]==inf?x:realf[x];
    book[x] = true;
    stck.push(x);
    if(st[x][1]==-1 || st[x][1]==-2) return realf[x] = n+1;
    realf[x] = dfs(st[x][1]);
    if(st[x][tp[x]]==-5) realf[x] = -realf[x];
    if(realf[x]==-x) {
        while(!stck.empty()) {
            int ths = stck.top();
            stck.pop();
            realf[ths] = 0;
            if(ths==x) break;
        }
    }
    return realf[x];
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    mp['T'] = -1;
    mp['F'] = -2;
    mp['U'] = -3;
    mp['+'] = -4;
    mp['-'] = -5;
    int T, opt;
    cin >> opt >> T;
    while(T--) {
        cin >> n >> m;
        init();
        char v;
        for(int i=1; i<=m; ++i) {
            cin >> v;
            if(v=='U' || v=='T' || v=='F') {
                int x;
                cin >> x;
                tp[x] = 0;
                st[x][++tp[x]] = mp[v];
            }else if(v=='+') {
                int x, y;
                cin >> x >> y;
                for(int j=1; j<=tp[y]; ++j) st[x][j] = st[y][j];
                tp[x] = tp[y];
                //if(st[y][1]>0) edge[st[y][1]].push_back(x);
            }else {
                int x, y;
                cin >> x >> y;
                for(int j=1; j<=tp[y]; ++j) st[x][j] = st[y][j];
                tp[x] = tp[y];
                st[x][++tp[x]] = mp['-'];
                while(st[x][tp[x]]==-5 && st[x][tp[x]-1]==-5) tp[x]-=2;
                //if(st[y][1]>0) edge[st[y][1]].push_back(x);
            }
        }
        for(int i=1; i<=n; ++i) {
            while(st[i][tp[i]]==-5 && st[i][tp[i]-1]==-5) tp[i]-=2;
            if(st[i][1]==-3) realf[i] = 0;
        }
        /*for(int i=1; i<=n; ++i) {
            if(st[i][1]==i) {
                if(st[i][tp[i]]==-5) {
                    realf[i] = 'U';
                    q.push(i);
                }
            }
            if(st[i][1]==-3) {
                realf[i] = 'U';
                q.push(i);
            }
        }
        while(!q.empty()) {
            int ths = q.front();
            q.pop();
            if(vis[ths]) continue;
            vis[ths] = true;
            for(int j=0; j<edge[ths].size(); ++j) {
                int to = edge[ths][j];
                if(st[to][1]!=ths) continue;
                if(!vis[to]) {
                    realf[to] = 'U';
                    q.push(to);
                }
            }
        }*/
        for(int i=1; i<=n; ++i) {
            if(!book[i]) dfs(i);
        }
        int ans = 0;
        for(int i=1; i<=n; ++i) {
            if(realf[i]==0) ++ans;
        }
        cout << ans << '\n';
        //for(int i=1; i<=n; ++i) cout << realf[i] << ' ';
        //cout << '\n';
    }
    return 0;
}
