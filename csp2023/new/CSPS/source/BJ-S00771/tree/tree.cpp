#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int d,x;
};
bool operator <(node a,node b){
    return a.d < b.d;
}
const int maxn = 1e5;
vector <int> e[maxn];
long long a[maxn],d[maxn];
int b[maxn],c[maxn];
int n,dis[maxn];
bool flag[maxn];
void f(){
    priority_queue <node> q;
    q.push({d[1],1});
    flag[1] = 1;
    int cnt = 0;
    while (!q.empty()){
        int x = q.top().x;
        dis[x] = ++cnt;
        q.pop();
        for (int y : e[x]){
            if (flag[y]) continue;
            flag[y] = 1;
            q.push({d[y],y});
        }
    }
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    cin >> n;
    bool flag1 = true;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> b[i] >> c[i];
        if (c[i] != 0) flag1 = false;
    }
    for (int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (flag1){
        for (int i = 1;i <= n;i++){
            d[i] = a[i] / max(b[i],1);
            if (a[i] % max(b[i],1) != 0) d[i]++;
        }
        f();
        long long ans = 0;
        for (int i = 1;i <= n;i++){
            ans = max(ans,dis[i] + d[i]);
        }
        cout << ans << endl;
    }
    else{
        int sum = 0;
        for (int i = 1;i <= n;i++){
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}
