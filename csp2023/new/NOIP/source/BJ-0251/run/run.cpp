#include <iostream>
using namespace std;
const int NR = 100010;
int n, m, k, d, ans;
int x[NR], y[NR], v[NR];
void dfs(int step, int kk, int dd)
{
    if (step > n) {ans = max(ans, dd); return;}
    if (kk < k)
    {
        int tmp = 0;
        for (int i = 1; i <= m; i++)
            if (x[i] == step && kk + 1 >= y[i])
                tmp += v[i];
        dfs(step + 1, kk + 1, dd - 1 + tmp);
    }
    dfs(step + 1, 0, dd);
}
int main()
{
     freopen("run.in", "r", stdin);
     freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; i++)
            cin >> x[i] >> y[i] >> v[i];
        dfs(1, 0, 0);
        cout << ans << '\n';
    }
    return 0;
}
