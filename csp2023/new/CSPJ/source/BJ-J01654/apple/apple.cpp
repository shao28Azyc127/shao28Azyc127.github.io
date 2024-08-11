#include<bits/stdc++.h>
using namespace std;
long long n, ans, k;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    bool flag = false;
    cin >> n;
    while(n != 0) {
        if(n == 2) {
            n = 1;
            ans++;
        }
        if(n == 1) {
            n = 0;
            ans++;
        }
        if(n % 3 == 0) {
            n = n / 3 * 2;
            ans++;
        }
        if(n % 3 == 1) {
            n = (n-1) / 3 * 2;
            ans++;
            if(flag == false) {
                k = ans;
                flag = true;
            }
        }
        if(n % 3 == 2) {
            n = (n-2) / 3 * 2 + 1;
            ans++;
        }
    }
    if(k == 0) k = ans;
    cout << ans << " " << k << endl;
    return 0;
}