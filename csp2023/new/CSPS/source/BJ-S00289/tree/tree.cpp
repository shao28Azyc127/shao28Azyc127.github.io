#include<cstdio>
#include<iostream>
using namespace std;
const int N = 100;
int n;
long long a[N], h[N];
int b[N], c[N];//c[i]可能小于0
struct edge{
    int to, nxt;
}e[2 * N];
int head[N] = {}, cnt = 0;
int ans = 1e9 + 10;//完成天数
bool flag[N] = {};
long long read(){
    long long x; int f = 1;
    char ch = getchar();
    while(ch < '0' || '9' < ch){if(ch == '-')f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    return 1ll * x * f;
}
void add(int u, int v){
    e[++cnt] = (edge){v, head[u]};
    head[u] = cnt;
}
bool check(){
    for(int i = 1; i <= n; i++){
        if(h[i] < a[i]) return false;
    }
    return true;
}
bool chos[N], temp[N];
void dfs(int x){
    /*for(int i = 1; i <= n; i++){
        cout << h[i] << ' ';
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << max(b[i] + 1ll * x * c[i], 1ll) << ' ';
    }
    cout << endl;*/
    if(check()){
        ans = min(ans, x);
        return;
    }
    if(x > ans) return;
    for(int i = 1; i <= n; i++){
        if(chos[i]){
            for(int j = 1; j <= n; j++) temp[i] = chos[i];
            chos[i] = 0;
            for(int j = head[i]; j; j = e[j].nxt){
                if(!flag[e[j].to]) chos[e[j].to] = 1;
            }
            flag[i] = 1;
            for(int i = 1; i <= n; i++){
                if(flag[i]) h[i] += max(b[i] + 1ll * x * c[i], 1ll);
            }
            dfs(x + 1);
            for(int i = 1; i <= n; i++){
                if(flag[i]) h[i] -= max(b[i] + 1ll * x * c[i], 1ll);
            }
            flag[i] = 0;
            for(int j = 1; j <= n; j++) chos[i] = temp[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(flag[i]) h[i] += max(b[i] + 1ll * x * c[i], 1ll);
    }
    dfs(x + 1);
    for(int i = 1; i <= n; i++){
        if(flag[i]) h[i] -= max(b[i] + 1ll * x * c[i], 1ll);
    }
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld %d %d", &a[i], &b[i], &c[i]);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        add(u, v); add(v, u);
    }
    /*for(int i = 1; i <= n; i++){
            cout << i << endl;
        for(int j = head[i]; j; j = e[j].nxt){
            cout << e[j].to << ' ';
        }
        cout << endl;
    }*/
    flag[1] = true;
    for(int i = head[1]; i; i = e[i].nxt){
        chos[e[i].to] = 1;
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
