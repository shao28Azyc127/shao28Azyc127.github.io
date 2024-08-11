#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, d, a[maxn], pos = 1, km, u;
long long prise, sum[maxn];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    //cout << (sizeof(prise)) << "\n";
    for (int i = 1; i < n; i++) {
        cin >> u;
        sum[i] = sum[i - 1] + u;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; ) {
        while (a[pos] >= a[i] && pos < n) pos++;
        int addoil = (sum[pos - 1] - sum[i - 1] - km + d - 1) / d;
        //if (addoil <= 0) addoil = 0;
        prise += addoil * a[i];
        km = addoil * d + km - sum[pos - 1] + sum[i - 1];
        //cout << "pos: " << pos << " i: " << i << " addoil: " << addoil << " km: " << km << "\n";
        i = pos;
    }
    cout << prise << "\n";
    return 0;
}