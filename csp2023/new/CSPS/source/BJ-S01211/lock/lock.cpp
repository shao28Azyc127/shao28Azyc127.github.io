#include<bits/stdc++.h>
using namespace std;

int n, ans;
int a[10][10];
int po[10];
bool awa[100005];
bool flag;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 5; j++)
            cin >> a[i][j];
    if(n == 1)
    {
        cout << "81" << endl;
        return 0;
    }
    for(int i = 1; i <= 5; i++)
        for(int j = i; j <= 5; j++)
        {
            for(int x = 1; x <= 5; x++)
                if(x != i && x != j) po[x] = a[1][x];
            for(int p = 0; p <= 9; p++)
                for(int q = 0; q <= 9; q++)
                {
                    flag = 1;
                    po[i] = p;
                    po[j] = q;
                    int num = po[1] * 10000 + po[2] * 1000 + po[3] * 100 + po[4] * 10 + po[5];
                    for(int u = 1; u <= n; u++)
                    {
                        int cnt = 0;
                        int dif[5];
                        for(int v = 1; v <= 5; v++)
                        {
                            if(po[v] != a[u][v])
                            {
                                cnt++;
                                dif[cnt] = v;
                            }
                        }
                        if(cnt == 0)
                        {
                            flag = 0;
                            break;
                        }
                        if(cnt == 1) continue;
                        if(cnt > 2)
                        {
                            flag = 0;
                            break;
                        }
                        if(dif[1] - dif[2] != 1 && dif[1] - dif[2] != -1)
                        {
                            flag = 0;
                            break;
                        }
                        if(po[dif[1]] - po[dif[2]] != a[u][dif[1]] - a[u][dif[2]])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag && awa[num] == 0)
                    {
                        ans++;
                        awa[num] = 1;
                    }
                }
        }
    cout << ans << endl;
    return 0;
}
