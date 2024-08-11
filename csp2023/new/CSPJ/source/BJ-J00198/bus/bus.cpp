#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int g[10001][10001];
int len, n, m, k, minn = 1e9;
struct q{
    int x, len;
};
void print_queue(queue<q> s){
    while(!s.empty()){
        q x = s.front();
        printf("%d %d, ", x.x, x.len);
        s.pop();
    }
    printf("\n");
}
void bfs(){
    queue<q> s;
    s.push((q){1, 0});
    while(!s.empty()){
        q x = s.front();
        if(x.x == n){
            minn = min(minn, x.len);
        }
        s.pop();
        int l = x.len + 1;
        for(int i = 1; i <= n; i++){
            if(x.x != i && g[x.x][i] != -1){
                s.push((q){i, l});
            }
        }
    }
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    memset(g, -1, sizeof(g));
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        g[u][v] = a;
    }
    bfs();
    printf("%d", minn);
    return 0;
}