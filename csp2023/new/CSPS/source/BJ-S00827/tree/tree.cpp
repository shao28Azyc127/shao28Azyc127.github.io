#include <bits/stdc++.h>
using namespace std;
const int N = 805;
int n;
int a[805],b[805],c[805];
int jt[805];
int vis[805];
int d[N];
vector <int> G[N];
void add(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int u,int fa){
    for(int i = 0; i < G[u].size(); i++){
        if(G[u][i] == fa){
            continue;
        }
        int v = G[u][i];
        d[v] =d[u]+1;
        dfs(v,u);
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
        jt[i] = a[i]/b[i];
        if(a[i]%b[i]!=0) jt[i]++;
    }
    for(int i = 1; i <= n-1; i++){
        int u,v;
        cin >> u >> v;
        add(u,v);
    }
    d[1] = 1;
    dfs(1,0);
    int id = 0;
    int mid = -100005;
    for(int i =  1; i <= n; i++){
        if(jt[i]+d[i]>mid)mid = jt[i]+d[i];
    }
    cout << mid-1;
    return 0;
}
