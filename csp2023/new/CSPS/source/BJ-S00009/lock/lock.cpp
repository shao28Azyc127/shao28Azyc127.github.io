#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int a[10][10], ans;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
        scanf("%d", &a[i][j]);
    }
    int k[10];
    for(k[1] = 0;k[1] <= 9;k[1]++)
    {
    for(k[2] = 0;k[2] <= 9;k[2]++)
    {
    for(k[3] = 0;k[3] <= 9;k[3]++)
    {
    for(k[4] = 0;k[4] <= 9;k[4]++)
    {
    for(k[5] = 0;k[5] <= 9;k[5]++)
    {
        bool flag = 0;
        for(int i = 1;i <= n;i++)
        {
            int cha = 0;
            for(int j = 1;j <= 5;j++)
            {
                if(a[i][j] != k[j])
                {
                    if(cha)
                    {
                        if(cha != j-1 || (a[i][cha] - k[cha] + 10) % 10 != (a[i][j] - k[j] + 10) % 10)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    else
                    {
                        cha = j;
                    }
                }
            }
            if(!cha) flag = 1;
            if(flag) break;
        }
        if(flag) continue;
        ans++;
    }
    }
    }
    }
    }
    cout << ans;
    return 0;
}
