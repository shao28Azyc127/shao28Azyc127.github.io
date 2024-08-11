#include <bits/stdc++.h>
using namespace std;
int n, a[10][10];
int check(int tmp[], int a1, int a2, int a3, int a4, int a5)
{
    int cnt = 0;
    if (tmp[1] != a1) cnt++;
    if (tmp[2] != a2) cnt++;
    if (tmp[3] != a3) cnt++;
    if (tmp[4] != a4) cnt++;
    if (tmp[5] != a5) cnt++;
    if (cnt >= 3) return 0;
    if (cnt == 1) return 1;
    if (cnt == 0) return 0;
    int b1 = tmp[1] - a1, b2 = tmp[2] - a2, b3 = tmp[3] - a3, b4 = tmp[4] - a4, b5 = tmp[5] - a5;
    b1 = (b1 + 10) % 10, b2 = (b2 + 10) % 10, b3 = (b3 + 10) % 10, b4 = (b4 + 10) % 10, b5 = (b5 + 10) % 10;
    if (b1 && b1 == b2) return 1;
    if (b2 && b2 == b3) return 1;
    if (b3 && b3 == b4) return 1;
    if (b4 && b4 == b5) return 1;
    return 0;
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 5; j++) cin >> a[i][j];
    int ans = 0;
    for (int a1 = 0; a1 <= 9; a1++) for (int a2 = 0; a2 <= 9; a2++) for (int a3 = 0; a3 <= 9; a3++) for (int a4 = 0; a4 <= 9; a4++) for (int a5 = 0; a5 <= 9; a5++)
    {
        int x = 1;
        for (int i = 1; i <= n; i++) x &= check(a[i], a1, a2, a3, a4, a5);
        ans += x;
    }
    cout << ans << endl;
    return 0;
}