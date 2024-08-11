#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 15;

int n, ans;
int a[N][10], b[10], res[10];

bool func1()
{
    int cnt = 0;
    for (int i = 1; i <= 5 && cnt <= 1; i++)
        if (res[i])
            cnt++;
    return cnt == 1;
}
bool func2()
{
    int cnt = 0;
    for (int i = 1; i <= 5 && cnt <= 1; i++)
        if (res[i] && res[i - 1] && res[i] != res[i - 1])
            return 0;
        else if (res[i] && !res[i - 1] && !res[i + 1])
            return 0;
        else if (res[i] && res[i - 1] && res[i] == res[i - 1])
            cnt++;
    return cnt == 1;
}
bool chk()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
            res[j] = (b[j] + 10 - a[i][j]) % 10;
        if (!func1() && !func2())
            return 0;
    }
    return 1;
}
void dfs(int x)
{
    if (x == 6)
    {
        if (chk())
            ans++;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        b[x] = i;
        dfs(x + 1);
    }
}

signed main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    dfs(1);
    cout << ans << endl;
    return 0;
}
