#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e6 + 5;
int a[N], tmp[N], key, tot, cnt, ans;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n; cin >> n; key = n;
    for (int i = 1; i <= n; i ++)
        a[i] = i;
    while (n)
    {
        tot ++; cnt = 0;
        for (int i = 1; i <= n; i ++)
            tmp[i] = a[i];
        for (int i = 1; i <= n; i ++)
            if (i % 3 != 1)
                tmp[++ cnt] = a[i];
            else if (a[i] == key)
                ans = tot;
        for (int i = 1; i <= cnt; i ++)
            a[i] = tmp[i];
        n = cnt;
    }
    cout << tot << " " << ans;

    return 0;
}
