#include<bits/stdc++.h>
using namespace std;
//#define int long long
int cnt[11][11][11][11][11];
bool flg[11][11][11][11][11];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        memset(flg, 0, sizeof(flg));
        // 1
        for (int x = 1; x <= 9; x ++) flg[(a + x) % 10][b][c][d][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][(b + x) % 10][c][d][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][b][(c + x) % 10][d][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][b][c][(d + x) % 10][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][b][c][d][(e + x) % 10] = 1;
        // 2
        for (int x = 1; x <= 9; x ++) flg[(a + x) % 10][(b + x) % 10][c][d][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][(b + x) % 10][(c + x) % 10][d][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][b][(c + x) % 10][(d + x) % 10][e] = 1;
        for (int x = 1; x <= 9; x ++) flg[a][b][c][(d + x) % 10][(e + x) % 10] = 1;

        for (int a = 0; a <= 9; a ++)
            for (int b = 0; b <= 9; b ++)
                for (int c = 0; c <= 9; c ++)
                    for (int d = 0; d <= 9; d ++)
                        for (int e = 0; e <= 9; e ++)
                            cnt[a][b][c][d][e] += flg[a][b][c][d][e];
    }
    int ans = 0;
    for (int a = 0; a <= 9; a ++)
        for (int b = 0; b <= 9; b ++)
            for (int c = 0; c <= 9; c ++)
                for (int d = 0; d <= 9; d ++)
                    for (int e = 0; e <= 9; e ++)
                        if (cnt[a][b][c][d][e] == n)
                            ans ++;
    cout << ans;

    return 0;
}
