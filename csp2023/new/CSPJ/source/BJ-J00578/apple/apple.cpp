#include <bits/stdc++.h>
using namespace std;

int t[1010];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    memset(t, -1, sizeof t);
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        bool flag = true;
        for (int j = 1; j <= n; ++j)
        {
            if (t[j] == -1)
            {
                ++cnt;
                if (cnt == 3)
                {
                    cnt = 0;
                }
                if (cnt == 1)
                {
                    t[j] = i;
                }
                else
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << i << " " << t[n] << endl;
            break;
        }
    }
    return 0;
}
