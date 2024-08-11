#include <bits/stdc++.h>
using namespace std;
const int N = 1E5;
int v[N + 1];
int a[N + 1];
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, d;
    cin >> n >> d;
    int V;
    for(int i = 1; i <= n - 1; i++) {
        cin >> V;
        v[i + 1] = v[i] + V;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int preoil = 0;
    int pre = 1;
    int prev = 0;
    int D;
    while(pre <= n - 1) {
        if(pre == 1) {
            int minn = a[1];
            int j;
            for(j = 2; j <= n; j++) {
                if(a[j] < minn) {
                    minn = a[j];
                }
            }
            D = (v[j] - v[1]) / d;
            if(D * d < v[j] - v[1]) {
                D += 1;
            }
            ans += minn * D;
            pre = j;
            preoil = a[j];
            prev = D * d;
        }
        else {
            if(a[pre + 1] < preoil) {
                D = (v[pre + 1] - v[pre] - prev) / d;
                if(D * d < v[pre + 1] - v[pre] - prev) {
                    D += 1;
                }
                prev = D * d;
                ans += peroil * D;
                preoil = a[pre + 1];
                pre++;
            }
            else {
                D = (v[pre + 1] - v[pre] - prev) / d;
                if(D * d < v[pre + 1] - v[pre] - prev) {
                    D += 1;
                }
                prev = D * d;
                ans += peroil * D;
                pre++;
            }
        }
    }
    cout << ans;
    return 0;
}
