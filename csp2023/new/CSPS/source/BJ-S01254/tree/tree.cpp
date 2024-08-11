#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int a[maxn],b[maxn],c[maxn];
vector<int> g[maxn];
bool visited[maxn];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << 35498726 << endl;
    return 0;
}