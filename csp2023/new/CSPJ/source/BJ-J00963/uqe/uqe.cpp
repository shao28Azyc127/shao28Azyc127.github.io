#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in", "r" ,stdin);
    freopen("uqe.out", "w" ,stdout);
    int T,M, X[5005][5], ans[5005];
    cin >> T >> M;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> X[i][j];
        }
    }
    for (int i = 1; i <= T; i++)
    {
        if (X[i][2] * X[i][2] - 4 * X[i][1] * X[i][3] < 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
