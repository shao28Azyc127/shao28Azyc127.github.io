#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100005], f[100005], n, d;
long long sumv[100005], v[100005], minn = 9e18;
long long min(long long x, long long y) {return x < y ? x : y;}
long long max(long long x, long long y) {return x > y ? x : y;}
struct Node { int x, y, z; };
bool operator<(Node x, Node y) {
    if (x.x != y.x) return x.x < y.x;
    if (x.y != y.y) return x.y < y.y;
    return x.z < y.z;
} map<Node, bool> mp;
void dfs(int step, int have, int cost) {
    if (have < 0 || cost >= minn) return;
    if (mp.count((Node){step, have, cost})) return;
    mp[(Node){step, have, cost}] = true;
    printf("step : %d; have : %d; cost : %d\n", step, have, cost);
    if (step == n) {
        minn = min(minn, cost);
        return;
    }
    for (int i = max(0, v[step] - have); i <= sumv[n - 1] - sumv[step - 1] - have; ++i)
        dfs(step + 1, have - v[step] + i, cost + i * a[step]);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; ++i) cin >> v[i], sumv[i] = sumv[i - 1] + v[i];
    for (int i = 1; i <= n; ++i) cin >> a[i], minn = min(minn, a[i]);
    if (a[1] == minn) {
        cout << int(ceil(sumv[n - 1] * a[1] * 1.0 / d)) << endl;
        return 0;
    }
    minn = 9e18;
    dfs(1, 0, 0);
    cout << ceil(1.0 * minn / d) << endl;
    return 0;
}

// f[i] = f[k] + v[i - 1] * a[k] - c[k];
// c[i] = v[k] * a[k];
