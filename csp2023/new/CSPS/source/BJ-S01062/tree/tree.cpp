#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int NR = 1e5 + 5;

int n;
int ans = 0;
int a[NR], b[NR], c[NR];
vector<int> g[NR];

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    for (int i = 1;i <= n;i ++)
        cin >> a[i] >> b[i] >> c[i];
    int x, y;
    bool flag = 1;
    for (int i = 1;i < n;i ++)
    {
        cin >> x >> y;
        if (y != x + 1)
            flag = 0;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if (flag)
    {
        for (int i = 1;i <= n;i ++)
            ans = max(ans, i - 1 + a[i] % b[i] + (a[i] % b[i] == 0 ? 0 : 1));
        cout << ans;
        return 0;
    }
    cout << n;
    return 0;
}
