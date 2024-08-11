#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

const int N = 1e9+5;
bool vis[N];
int n;

bool checkE()
{
    for (int i = 0; i < n; i ++)
    {
        if (vis[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);

    memset(vis, 1, sizeof(vis));

    for (int i = 0; i < n; i ++)
    {
        vis[i] = 0;
    }

    int ans = 0, round = 0;
    while (!checkE())
    {
        round ++;
        int cnt = 0;
        for (int i = 0; i < n; i ++)
        {
            if (vis[i])
            {
                continue;
            }
            if (cnt % 3 == 0)
            {
                if (i == n-1)
                {
                    ans = round;
                }
                vis[i] = 1;
            }
            cnt ++;
        }
    }

    printf("%d %d", round, ans);

    return 0;
}
