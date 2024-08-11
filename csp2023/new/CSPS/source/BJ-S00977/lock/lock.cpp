#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10][10];
int sum[10];
int ans, cnt;
signed main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }
    if (n == 1){
        ans += 45;
        ans += 36;
        cout << ans << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= 5; j++){
            if (a[i][j] != a[i - 1][j]){
                sum[i] += 9;
                cnt++;
            }
        }
        ans += sum[i];
    }
    cout << ans + cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
