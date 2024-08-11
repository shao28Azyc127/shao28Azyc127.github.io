#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans;
int t[30];
char c[2000100];
int cnt;
signed main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 1; i < n; i++){
        if (c[i] != c[i + 1]) cnt++;
    }
    if (cnt == 0){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            sum += i;
        }
        cout << sum - n << endl;
        return 0;
    }
    cout << 0 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
