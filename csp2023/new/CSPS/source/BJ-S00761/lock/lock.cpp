#include<bits/stdc++.h>
using namespace std;
const int MX = 10;
typedef long long LL;
int n, a[MX][5], b[5], d[5], pos[5], cnt, ans;
int f(int x) {return (x + 10) % 10;}
bool chk()
{
    for (int i = 1; i <= n; i++)
    {
        cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            d[j] = a[i][j] - b[j];
            if (d[j]) pos[++cnt] = j;
        }
        if (cnt == 0 || cnt > 2 || (cnt == 2 && (pos[2] - pos[1] != 1 || f(d[pos[1]]) != f(d[pos[2]])))) return 0;
    }
    return 1;
}
void dfs(int p)
{
    if (p > 4)
    {
        if (chk()) ans++;
        return;
    }
    for (b[p] = 0; b[p] <= 9; b[p]++) dfs(p + 1);
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++) cin >> a[i][j];
    dfs(0);
    cout << ans << endl;
    return 0;
}
