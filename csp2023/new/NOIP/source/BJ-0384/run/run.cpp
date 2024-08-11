#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM = 1e5 + 10;
bool vis[20];
int n, m, k, d;
struct Node{
    int x, y, v;
}ch[MAXM];
int maxn = 0;
int calc(){
    int sum = 0, cnt = 0;
    for (int i = 1; i <= m; i++){
        if (vis[i]) cnt++;
        bool flag = true;
        int l = ch[i].x - ch[i].y + 1, r = ch[i].x;
        for (int j = l; j <= r; j++)
            flag &= vis[j];
        if (flag) sum += ch[i].v;
    }
    return sum - cnt * d;
}
void dfs(int day, int cti){
    if (day > n){
        maxn = max(maxn, calc());
        return;
    }
    if (cti == k){
        vis[day] = false;
        dfs(day + 1, 0);
    }
    else{
        vis[day] = true;
        dfs(day + 1, cti + 1);
        vis[day] = false;
        dfs(day + 1, 0);
    }
}
void Work1and2(){
    scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &ch[i].x, &ch[i].y, &ch[i].v);
    maxn = 0;
    dfs(1, 0);
    printf("%lld\n", maxn);
}
void Work17and18(){
    scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
    for (int i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &ch[i].x, &ch[i].y, &ch[i].v);
    int sum = 0;
    for (int i = 1; i <= m; i++){
        int l = ch[i].x - ch[i].y + 1, r = ch[i].x;
        if (r - l + 1 > k) continue;
        int yl = ch[i].v - (r - l + 1) * d;
        if (yl > 0) sum += yl;
    }
    printf("%lld\n", sum);
}
signed main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    scanf("%lld%lld", &c, &t);
    if (1 <= c && c <= 2){
        while (t--){
            Work1and2();
        }
    }
    if (17 <= c && c <= 18){
        while (t--){
            Work17and18();
        }
    }
    return 0;
}
