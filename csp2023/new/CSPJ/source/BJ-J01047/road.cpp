#include <bits/stdc++.h>
using namespace std;

const int MAXN = 114514;
int n, d, ans = 1 << 30;
int v[MAXN], a[MAXN], ta[MAXN], dis[MAXN];

void dfs(int pos, int cost, int ds) {
    //cout << "pos:" << pos << " cost:" << cost << " ldis:" << ds << endl;
    if (pos == n-1){
        if (cost < ans)
            ans = cost;

        //cout << ans << endl;
        return;
    }

    for (int i = pos + 1; i < n; i ++){
        int ndis = dis[i] - dis[pos] - ds;
        //cout << ndis << endl;
        int ncost;
        int ldis;
        if (ndis % d == 0){
            ncost = ndis / d * a[pos];
            ldis = 0;
        } else {
            ncost = (ndis / d + 1) * a[pos];
            ldis = (ndis / d + 1) * d - ndis;
        }
        dfs(i, cost + ncost, ldis);
    }

    return;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for (int i = 0; i < n-1; i ++){
        cin >> v[i];
        dis[i+1] += v[i]+dis[i];
    }
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        ta[i] = a[i];
    }

    //cout << dis[n-1] << endl;
    sort(ta, ta + n);
    if (a[0] == ta[0]){
        if (dis[n-1] % d == 0){
            cout << dis[n-1] / d;
        } else {
            cout << dis[n-1] / d + 1;
        }
        return 0;
    }

    dfs(0,0,0);
    cout << ans;

    return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
