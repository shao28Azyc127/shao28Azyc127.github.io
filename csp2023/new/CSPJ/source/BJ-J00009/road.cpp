#include <bits/stdc++.h>

using namespace std;

int n;
int d;
int v[100001];
int a[100001];
int pre[100001];
int cost;
double oil;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d ;

    for (int i = 1; i < n; i++) {
        cin >> v[i] ;
        pre[i] = pre[i - 1] + v[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i] ;
    }

    for (int i = 1; i < n; ) {
        int t = i + 1;
        while (a[t] >= a[i] && t < n) t++;
        cost += ceil(1.0 * (pre[t - 1] - pre[i - 1]) / d - oil) * a[i];
        oil += ceil(1.0 * (pre[t - 1] - pre[i - 1]) / d);
        oil -= 1.0 * (pre[t - 1] - pre[i - 1]) / d;
        i = t;
    }

    cout << cost << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
