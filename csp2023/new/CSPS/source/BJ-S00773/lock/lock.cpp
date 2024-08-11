#include <bits/stdc++.h>
using namespace std;

int n;

int a[10][6];
int num[10][82][6];
int nu[6] = {0, 10000, 1000, 100, 10, 1};
int box[100000];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 81;j++)
        {
            for(int k = 1;k <= 5;k++)
            {
                num[i][j][k] = a[i][k];
            }
        }
    }
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    for(int t = 1;t <= n;t++)
    {
        int cnt = 0;
        for(int j = 1;j <= 5;j++)
        {
            for(int i = 1;i <= 9;i++)
            {
                ++cnt;
                num[t][cnt][j] = (a[t][j] + i) % 10;
            }
        }
        for(int j = 1;j <= 4;j++)
        {
            for(int i = 1;i <= 9;i++)
            {
                ++cnt;
                num[t][cnt][j] = (a[t][j] + i) % 10;
                num[t][cnt][j + 1] = (a[t][j + 1] + i) % 10;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 81;j++)
        {
            int sum = 0;
            for(int k = 1;k <= 5;k++)
            {
                sum += num[i][j][k] * nu[k];
            }
            box[sum]++;
        }
    }
    int ans = 0;
    for(int i = 0;i <= 99999;i++)
    {
        if(box[i] >= n)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
