#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[10][10], diff[10][2], x, y;

bool cango(int a1, int a2, int b1, int b2)
{
    if(a1 <= a2) x = a2 - a1;
    else x = 10 - a1 + a2;
    if(b1 <= b2) y = b2 - b1;
    else y = 10 - b1 + b2;
    return x == y;
}

bool cangoto(int a1, int a2, int a3, int a4, int a5, int b1, int b2, int b3, int b4, int b5)
{
    int cnt = 0;
    int last = 0;
    if(a1 != b1)
    {
        if(last != 0 && last != 0) return 0;
        diff[++cnt][0] = a1, diff[cnt][1] = b1, last = 1;
    }
    if(a2 != b2)
    {
        if(last != 0 && last != 1) return 0;
        diff[++cnt][0] = a2, diff[cnt][1] = b2, last = 2;
    }
    if(a3 != b3)
    {
        if(last != 0 && last != 2) return 0;
        diff[++cnt][0] = a3, diff[cnt][1] = b3, last = 3;
    }
    if(a4 != b4)
    {
        if(last != 0 && last != 3) return 0;
        diff[++cnt][0] = a4, diff[cnt][1] = b4, last = 4;
    }
    if(a5 != b5)
    {
        if(last != 0 && last != 4) return 0;
        diff[++cnt][0] = a5, diff[cnt][1] = b5, last = 5;
    }
    if(cnt == 1) return 1;
    if(cnt == 2 && cango(diff[1][0], diff[2][0], diff[1][1], diff[2][1])) return 1;
    return 0;
}

signed main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    //cout << cango(1, 3, 5, 6) << endl;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    int ans = 0;
    for(int a1 = 0; a1 <= 9; a1++)
    for(int a2 = 0; a2 <= 9; a2++)
    for(int a3 = 0; a3 <= 9; a3++)
    for(int a4 = 0; a4 <= 9; a4++)
    for(int a5 = 0; a5 <= 9; a5++)
    {
        bool flag = 1;
        for(int i = 1; i <= n; i++) flag &= cangoto(a1, a2, a3, a4, a5, a[i][1], a[i][2], a[i][3], a[i][4], a[i][5]);
        ans += flag;
        //if(flag) cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << endl;
    }
    cout << ans;
    return 0;
}
