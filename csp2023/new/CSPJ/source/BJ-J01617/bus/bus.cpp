#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
vector<int> v[N], g[N];
int n, m, k, cnt[N];
bool f;
struct node{
    int a, b;
};
int bfs1(){
    queue<node> q;
    q.push((node){1, 0}), cnt[1]++;
    while(!q.empty()){
        node d = q.front();
        q.pop();
        if(d.a == n && d.b % k == 0) return d.b;
        if(cnt[d.a] >= 2*max(n, k)){
            return -1;
        }
        for(int i = 0; i < v[d.a].size(); i++){
            int y = v[d.a][i];
            q.push((node){y, d.b+1}), cnt[y]++;
        }
    }
    return -1;
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        v[a].push_back(b), g[a].push_back(c);
        if(c != 0) f = 1;
    }
    if(!f){
        printf("%d", bfs1());
        return 0;
    }
    puts("-1");
    return 0;
}
