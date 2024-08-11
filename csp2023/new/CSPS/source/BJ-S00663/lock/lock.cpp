#include <bits/stdc++.h>

using namespace std;

map <int, int> mp;

int a[15][15];

int i_5_1(int g, int wz, int zhi)
{
    int i, j, k;
    int x = 0;
    for(i=1; i<=5; i++)
    {
        x *= 10;
        if(wz == i)
        {
            x += zhi;
        }
        else
        {
            x += a[g][i];
        }
    }
    return x;
}

int i_5_2(int g, int wz, int zhi)
{
    int i, j, k;
    int x = 0;
    for(i=1; i<=5; i++)
    {
        x *= 10;
        if(wz == i || wz + 1 == i)
        {
            x += (a[g][i] + zhi) % 10;
        }
        else
        {
            x += a[g][i];
        }
    }
    return x;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int i, j, k;
    int n;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=5; j++)
        {
            cin >> a[i][j];
        }
        mp[i_5_1(i, 0, 0)] = -1;
    }
    int ans = 0;
    for(i=1; i<=n; i++)
    {
        // 1
        // a[i][]
        for(j=1; j<=5; j++)
        {
            for(k=0; k<=9; k++)
            {
                if(k == a[i][j]) continue;
                int x = i_5_1(i, j, k);
                if(mp[x] != -1) mp[x]++;
                if(mp[x] == n)
                {
                    ans++;
                }
            }
        }
        // 2

        for(j=1; j<=4; j++)
        {
            for(k=0; k<=9; k++)
            {
                int x = i_5_2(i, j, k);
                if(mp[x] != -1)
                {
                    mp[x]++;
                }
                if(mp[x] == n) ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
