#include <bits/stdc++.h>
using namespace std;

int n;
int num[10][10];

int q[10][10][10][10][10];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> num[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 9; j++)
        {
            int t1 = (num[i][1] + j) % 10;
            int t2 = (num[i][2] + j) % 10;
            int t3 = (num[i][3] + j) % 10;
            int t4 = (num[i][4] + j) % 10;
            int t5 = (num[i][5] + j) % 10;
            q[t1][num[i][2]][num[i][3]][num[i][4]][num[i][5]]++;
            q[num[i][1]][t2][num[i][3]][num[i][4]][num[i][5]]++;
            q[num[i][1]][num[i][2]][t3][num[i][4]][num[i][5]]++;
            q[num[i][1]][num[i][2]][num[i][3]][t4][num[i][5]]++;
            q[num[i][1]][num[i][2]][num[i][3]][num[i][4]][t5]++;

            q[t1][t2][num[i][3]][num[i][4]][num[i][5]]++;
            q[num[i][1]][t2][t3][num[i][4]][num[i][5]]++;
            q[num[i][1]][num[i][2]][t3][t4][num[i][5]]++;
            q[num[i][1]][num[i][2]][num[i][3]][t4][t5]++;
        }

    int ans = 0;

    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++)
                    for (int m = 0; m <= 9; m++)
                        if (q[i][j][k][l][m] == n) ans++;
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
