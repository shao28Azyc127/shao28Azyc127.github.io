#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, a[100005], v[100005], s[100005][100005];
    int num = 0, ans = 0;
    map<int, int> m;
    map<int, int> s
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] = i;
    }
    a.sort(a, a + n);
    for(int j = 0; j < n; j++) {
        s[m[a[j]]] = j;
    }
    for(int i = 0; i < n; i += j) {
        int j = 0;
        while(s[a[i]] < s[a[i + j]]) {
            num += v[i];
            j++;
        }
        ans += ceil(num / d) * a[i];
    }
    cout << ans << endl;
    return 0;
}
