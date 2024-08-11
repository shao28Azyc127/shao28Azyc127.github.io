#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5+5;
int t, c;
int n, m, ans;
char vis[N];
bool vi[N];
int in[N];
int f[N];

int dfs56(int i){
    if(vis[i]=='U') return 1;
    if(in[i]&&!vi[i]) {
        vi[i] = true;
        int ret = dfs56(in[i]);
        vis[i] = ret ? 'U' : 0;
        return ret;
    } else return 0;
}

void solve56(){
    cin >> n >> m;
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    memset(vi, 0, sizeof(vi));
    int u, v; char op; ans=0;
    for(int i=1;i<=m;i++){
        cin >> op;
        if(op=='U'){
            cin >> u;
            vis[u] = op;
            in[u] = 0;
        } else {
            cin >> u >> v;
            if(u!=v) vis[u] = 0, in[u] = v;
        }
    }
    for(int i=1;i<=n;i++){
        ans += dfs56(i);
    }
    cout << ans << endl;
}

void solve34(){
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    int u; ans=0;
    char op;
    for(int i=1;i<=m;i++){
        cin >> op >> u;
        if(op=='U'&&vis[u]!='U') ans++;
        vis[u] = op;
    }
    cout << ans << endl;
}

char cal(char v, int op, char self){
    char ret = v;
    if(op&&v=='T') ret = 'F';
    if(op&&v=='F') ret = 'T';
    if(ret != self) return 'U';
    return ret;
}

void dfs2(int i){
    if(!vi[i]||vis[i]=='U') return;
    vis[i] = 'U';
    if(in[i]) vi[i]=false, dfs2(in[i]);
}

char dfs(int i, int pre){
    if(vis[i]=='U') return 'U';
    if(in[i]&&!vi[i]) {
        vi[i] = true;
        f[in[i]] += f[i];
        char res = dfs(in[i], i);
        vis[i] = cal(res, f[i], vis[i]);
        if(vis[i]=='U') dfs2(i);
        return vis[i];
    }
    // cout << i << ' ' << f[i] << endl;
    return f[i]%2==1 ? vis[i]='U' : vis[i];
}

void solve(){
    cin >> n >> m;
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    memset(vi, 0, sizeof(vi));
    memset(f, 0, sizeof(f));
    int u, v; char op; ans=0;
    for(int i=1;i<=m;i++){
        cin >> op;
        if(op!='+'&&op!='-'){
            cin >> u;
            vis[u] = op;
            in[u] = 0;
        } else {
            cin >> u >> v;
            if(u!=v) vis[u] = 0, in[u] = v, f[u] = op=='-';
        }
    }
    for(int i=1;i<=n;i++){
        ans += dfs(i, 0)=='U'? 1 : 0;
    }
    // for(int i=1;i<=n;i++){
    //     cout << dfs(i) << endl;
    // }
    cout << ans << endl;
}

int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        if(c==3||c==4) solve34();
        else if(c==5||c==6) solve56();
        else solve();
    }
}