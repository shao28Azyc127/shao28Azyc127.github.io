#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int a[100005], v[100005], l[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d; cin >> n >> d;
    for (int i = 1; i < n; i++){
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {l[i] = l[i-1] + v[i];}
    long long ans = 0, y = 0;
    // y = sheng yu oil
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        bool flag = false;
        for (int j = i; j < n; j++){
            if (a[j] < a[i]) {
                    //cout << ceil(1.0 * (l[j-1] - l[i-1] - y) / d) << endl;
                ans += ceil(1.0*(l[j-1] - l[i-1] - y) / d) * a[i];
                y += ceil(1.0*(l[j-1] - l[i-1] - y) / d) * d - (l[j-1] - l[i-1]);
                //printf("%d %d %d %d\n", n, i, ans, y);
                flag = true;
                i = j-1;
                break;
            }
        }
        if (!flag) {ans += ceil(1.0*(l[n-1] - l[i-1] - y) / d) * a[i]; break;}
    }
    cout << ans << endl;
return 0;}
