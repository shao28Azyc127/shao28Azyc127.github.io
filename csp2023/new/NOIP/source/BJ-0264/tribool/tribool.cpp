#include <bits/stdc++.h>
using namespace std;

int c, t, n, m;
short x[100010];
// 1 T
// 2 U
// 3 F
int fa[300010];
// 1~n T
// n+1~2n U
// 2n+1~3n F

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> c >> t;
    if (3 <= c <= 4)
    {
        while (t--)
        {
            memset(x, 0, sizeof(x));
            int n, m;
            cin >> n >> m;
            while (m--)
            {
                char v;
                cin >> v;
                if (v == 'T')
                {
                    int i;
                    cin >> i;
                    x[i] = 1;
                }
                if (v == 'U')
                {
                    int i;
                    cin >> i;
                    x[i] = 2;
                }
                if (v == 'F')
                {
                    int i;
                    cin >> i;
                    x[i] = 3;
                }
            }

            int ans = 0;
            for (int i = 1; i <= n; i++)
                if (x[i] == 2) ans++;

            cout << ans << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}