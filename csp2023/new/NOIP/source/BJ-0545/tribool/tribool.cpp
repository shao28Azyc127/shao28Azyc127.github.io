#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 1e5 + 10;
int c, t;
int n, m;

char op[N];
int a[N], b[N];
int ans = 1e9;
int d[N], d2[N];
int no(int x){
    if(x == 0) return 1;
    if(x == 1) return 0;
    return 2;
}
bool test(){
    for(int i = 1; i <= n; i++) d2[i] = d[i];
    for(int i = 1; i <= m; i++){
        if(op[i] == '+'){
            d2[a[i]] = d2[b[i]];
        }
        else if(op[i] == '-'){
            d2[a[i]] = no(d2[b[i]]);
        }
        else{
            if(op[i] == 'F') d2[a[i]] = 0;
            if(op[i] == 'T') d2[a[i]] = 1;
            if(op[i] == 'U') d2[a[i]] = 2;
        }
    }
    for(int i = 1; i <= n; i++){
        if(d2[i] != d[i]) return false;
    }
    return true;
}
void dfs(int x, int sum){
    if(x > n){
        if(test()) ans = min(ans, sum);
        return;
    }
    d[x] = 0;
    dfs(x + 1, sum);
    d[x] = 1;
    dfs(x + 1, sum);
    d[x] = 2;//U
    dfs(x + 1, sum + 1);
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d %d", &c, &t);
    if(c == 1 || c == 2){
        while(t--){
            ans = 1e9;
            scanf("%d %d", &n, &m);
            for(int i = 1; i <= m; i++){
                cin >> op[i];
                scanf("%d", &a[i]);
                if(op[i] == '+' || op[i] == '-') scanf("%d", &b[i]);
            }
            dfs(1, 0);
            printf("%d\n", ans);
        }
    }
    if(c == 3 || c == 4){
        while(t--){
            ans = 0;
            memset(d, 0, sizeof(d));
            scanf("%d %d", &n, &m);
            for(int i = 1; i <= m; i++){
                char opt; cin >> opt;
                int ta; scanf("%d", &ta);
                if(opt == 'F') d[ta] = 0;
                if(opt == 'T') d[ta] = 1;
                if(opt == 'U') d[ta] = 2;
            }
            for(int i = 1; i <= n; i++) if(d[i] == 2) ans++;
            printf("%d\n", ans);
        }
    }
    return 0;
}
