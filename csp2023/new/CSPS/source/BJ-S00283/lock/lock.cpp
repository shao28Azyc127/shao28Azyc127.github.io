# include <iostream>
# include <cstdio>
using namespace std;
int n, ans;
int a[10][10];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    if (n == 1)
    {
        cout << "81";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
            cin >> a[i][j];
    int to[10] = {0};
    int cnt = 0, flag = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= n; j++)
            if (a[j][i] != a[1][i])
                to[i]++;
    for (int i = 1; i <= 5; i++)
        if (to[i] != 0)
        {
            cnt++;
            if (to[i + 1] != 0)
                flag = 1;
        }
    if (cnt >= 3 || cnt == 2 && flag == 0)
    {
        cout << "0";
        return 0;
    }
    else if (cnt == 0)
    {
        cout << "81";
        return 0;
    }
    else
    {
        cout << "10";
        return 0;
    }
}