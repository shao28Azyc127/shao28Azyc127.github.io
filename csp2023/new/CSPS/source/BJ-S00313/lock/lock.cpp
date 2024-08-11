#include <bits/stdc++.h>
using namespace std;
int n, a[10][5], b[5], cnt = 0;
inline bool turn(int t)
{
    int cnt = 0;
    vector<int> diff;
    for (int i = 0; i < 5; i++)
    {
        if (a[t][i] != b[i])
        {
            cnt++;
            diff.push_back(i);
        }
    }
    if (cnt >= 3 || cnt <= 0) return false;
    else if (cnt == 1) return true;
    else
    {
        if (diff[0] + 1 == diff[1])
        {
            int d1 = a[t][diff[0]] - b[diff[0]];
            int d2 = a[t][diff[1]] - b[diff[1]];
            d1 = (d1 + 10) % 10;
            d2 = (d2 + 10) % 10;
            if (d1 == d2) return true;
            else return false;
        }
        else return false;
    }
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
    for (b[0] = 0; b[0] <= 9; b[0]++)
        for (b[1] = 0; b[1] <= 9; b[1]++)
            for (b[2] = 0; b[2] <= 9; b[2]++)
                for (b[3] = 0; b[3] <= 9; b[3]++)
                    for (b[4] = 0; b[4] <= 9; b[4]++)
                    {
                        bool good = 1;
                        for (int i = 1; i <= n; i++)
                            if (!turn(i)) good = 0;
                        if (good) cnt++;
                    }
    printf("%d\n", cnt);
    return 0;
}
