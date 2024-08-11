#include <bits/stdc++.h>
/*
    long long
    freopen
*/
using namespace std;

int const N = 30;

int n;

int a[N], b[N], c[N];
int f[N][N];
bool vis[N];

vector <int> q;

bool check(){
    for (int i = 1;i <= n;++i){
        if (vis[i] == 0)
            return 0;
    }
    return 1;
}

void g(){

}

void f(int x){
    if (check() == 1){
        g();
    }
    for (int i = 1;i <= n;++i){
        if (a[x][i] == 1 && vis[i] == 0){
            q.push_back(i);
            vis[i] = 1;
            f(i)
            q.pop_back();
            vis[i] = 0;
        }
    }
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;++i){
        cin >> a[i] >> b[i] >>c[i];
        b[i] = max(b[i], 1);
    }
    for (int i = 1;i < n;++i){
        int u, v;
        cin >> u >> v;
        f[u][v] = 1;
    }
    f(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
