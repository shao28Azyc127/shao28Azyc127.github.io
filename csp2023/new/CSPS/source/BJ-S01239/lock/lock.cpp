#include <bits/stdc++.h>
using namespace std;
int n, a[10][10], ans = 0, now[10];
int sub(int x, int y) {return (y - x + 10) % 10; }
bool chk (int p)
{
    /*
    printf("Now checking: \n");
    for (int i = 1; i <= 5; i++) cout << now[i] << " ";
    puts("");
    */
    bool f = 1;
    for (int i = 1; i <= 5; i++)
    {
        if (a[p][i] == now[i]) continue;
        f = 1;
        for (int j = 1; j <= 5; j++)
        {
            if (j != i && a[p][j] != now[j])
            {
                f = 0;
                break;
            }
        }
        if (f) return 1;
    }
    for (int i = 1; i < 5; i++)
    {
        //cout << a[p][i] << " " << now[i] << endl;
        //cout << "------------" << endl;
        if (a[p][i] == now[i]) continue;
        //cout << "NO CONTINUE";
        f = 1;
        for (int j = i + 2; j <= 5; j++)
        {
            //cout << a[p][j] << " " << now[j] << endl;
            if (a[p][j] != now[j]) return 0;
        }
        if (sub(a[p][i], now[i]) != sub(a[p][i + 1], now[i + 1])) return 0;
        if (f) return 1;
    }
    return 0;
}
void dfs (int p)
{
    if (p > 5)
    {
        bool ff = 1;
        for (int i = 1; i <= n; i++) if (!chk(i)) {ff = 0; break;}
        /*
        if (ff == 1)
        {
            for (int i = 1; i <= 5; i++) cout << now[i] << " ";
            puts("");
        }
        */
        if (ff) ans++;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        now[p] = i;
        dfs(p + 1);
    }
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 5; j++) cin >> a[i][j];
    dfs(1);
    cout << ans << endl;
    return 0;
}
