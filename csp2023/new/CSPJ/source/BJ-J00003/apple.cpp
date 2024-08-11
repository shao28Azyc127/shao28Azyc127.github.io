#include <bits/stdc++.h>
using namespace std;
const int N = 1E9;
bool a[N];
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    int ans;
    int a = 1;
    if(n == 1) {
        cout << 1 << ' ' << 1;
        return 0;
    }
    int sum = 0;
    int t = n;
    while(sum < n) {
        if(t % 3 == 0) {
            sum += n / 3;
            t -= n / 3;
        }
        else {
            sum += n / 3 + 1;
            t -= n / 3 + 1;
        }
        cnt++;
    }
    cout << cnt << ' ';
    if((n - 1) % 3 == 0) {
        cout << 1;
        return 0;
    }
    int x;
    int x1 = 1;
    for(int i = 1; i <= cnt; i++) {
        x = x1;
        while(a[x - 1] != 0 && x <= n) {
            x++;
        }
        x1 = x;
        while(x <= n) {
            if(x == n) {
                cout << i;
                return 0;
            }
            a[x - 1] = 1;
            x += 3;
        }
    }
    return 0;
}
