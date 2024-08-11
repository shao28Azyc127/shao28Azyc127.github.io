#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
vector<int> v[10005], c[10005];
int dis[10005][105]; //dis[i][j] : 走到i点，此时的时间%k=j，最小时间是多少
bool vis[10005][105];
int n, m, k;
struct St{
    int id, d;
    bool operator <(const St &b) const{
        return d > b.d;
    }
};
void dij(){
    memset(dis, 0x3f, sizeof(dis));
    priority_queue <St> q;
    q.push({1, 0}); dis[1][0] = 0;
    while (!q.empty()){
        St now = q.top(); q.pop();
        if (vis[now.id][now.d % k]) continue;
        vis[now.id][now.d % k] = 1;
        for (int i = 0; i < v[now.id].size(); i++){
            int j = v[now.id][i];
            int nowdis = now.d + max((c[now.id][i] - now.d + k - 1) / k * k, 0) + 1;
            if (nowdis < dis[j][nowdis % k]){
                dis[j][nowdis % k] = nowdis;
                q.push({j, nowdis});
            }
        }
    }
    if (dis[n][0] == 0x3f3f3f3f) cout << "-1";
    else cout << dis[n][0];
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while (m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].pb(b); c[a].pb(cost);
    }
    dij();
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
char name[25];
int Rand(){
    if (RAND_MAX == 32767) return (rand() << 15) + rand();
    else return rand();
}
int p[10005];
int main(){
    srand(time(0));
    for (int i = 1; i <= 20; i++){
        sprintf(name, "bus%d.in", i);
        freopen(name, "w", stdout);
        int n, m, k = 100 - rand() % 10;
        if (i >= 6 && i <= 10) k = 1;
        if (i <= 5) n = 10 - rand() % 2, m = 15 - rand() % 2;
        else n = 10000 - rand() % 100, m = 20000 - rand() % 200;
        cout << n << ' ' << m << ' ' << k << '\n';
        if (i == 14 || i == 15){
            for (int i = 2; i <= n; i++){
                cout << Rand() % (i - 1) + 1 << ' ' << i << ' ' << Rand() % (int)1e6 << '\n';
            }
            for (int i = 0; i < m - (n - 1); i++){
                int a = rand() % n + 1, b = rand() % n + 1;
                while (a >= b) a = rand() % n + 1, b = rand() % n + 1;
                cout << a << ' ' << b << ' ' << Rand() % (int)1e6 << '\n';
            }
            continue;
        }
        for (int i = 1; i <= n; i++) p[i] = i;
        random_shuffle(p + 2, p + n);
        for (int j = 1; j < n; j++){
            int a;
            if (i == 1 || i == 2 || i == 6 || i == 7 || i == 11 || i == 12 || i == 13) a = 0;
            else a = Rand() % (int)1e6;
            cout << p[j] << ' ' << p[j + 1] << ' ' << a << '\n';
        }
        for (int j = 0; j < m - (n - 1); j++){
            int u = rand() % n + 1, v = rand() % n + 1;
            int a;
            if (i == 1 || i == 2 || i == 6 || i == 7 || i == 11 || i == 12 || i == 13) a = 0;
            else a = Rand() % (int)1e6;
            cout << u << ' ' << v << ' ' << a << '\n';
        }
        fclose(stdout);
    }
}

*/
