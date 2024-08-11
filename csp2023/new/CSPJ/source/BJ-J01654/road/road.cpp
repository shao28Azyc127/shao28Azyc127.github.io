#include<bits/stdc++.h>
using namespace std;
int n, d, a[100005], b[100005], minx, ans;
int main(){
    freopen("roak.in","r",stdin);
    freopen("roak.out","w",stdout);
    cin >> n >> d;
    for(int i = 0; i < n - 1; i++) scanf("%d", a[i]);
    for(int i = 0; i < n; i++) scanf("%d", b[i]);
    for(int i = 0; i < n-1; i++) {
        minx = min(b[i], b[i + 1]);
    }
    if(b[0] == minx) {
        int k = 0;
        for(int i = 0; i < n-1; i++) k = k + a[i];
        if(k % d == 0) {
            cout << k / d * b[0] << endl;
            return 0;
        }
        else {
            cout << (k / d + d) * b[0] << endl;
            return 0;
        }
    }
    int k;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(b[i] > b[i + 1]) {
                if(a[i] % d == 0) ans = ans + (a[i] / d * b[i]);
                else {
                    ans = ans + ((a[i]/d+d) * b[i]);
                    k = d - (a[i]%d);
                }
            }
            else {
                for(int j = i; j < n; j++) {
                    if(b[i] > b[j]) {
                        int m = 0;
                        for(int r = i; r < j; r++) {
                            m = m + a[r];
                        }
                        if(m % d == 0) ans = ans + (m / d * b[i]);
                        else {
                             ans = ans + ((m/d+d) * b[i]);
                             k = d - (m%d);
                        }
                        i = j - 1;
                        break;
                    }
                }
            }
        }
        else {
            if(b[i] > b[i + 1]) {
                if(a[i] % d  - k == 0) ans = ans + (a[i] / d - k * b[i]);
                else {
                    ans = ans + ((a[i]/d+d-k) * b[i]);
                    k = d - (a[i]%d-k);
                }
            }
            else {
                for(int j = i; j < n; j++) {
                    if(b[i] > b[j]) {
                        int m = 0;
                        for(int r = i; r < j; r++) {
                            m = m + a[r];
                        }
                        if(m % d == 0) ans = ans + (m / d * b[i]);
                        else {
                             ans = ans + ((m/d+d-k) * b[i]);
                             k = d - (m%d-k);
                        }
                        i = j - 1;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}