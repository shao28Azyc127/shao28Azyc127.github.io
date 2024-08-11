#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, f[N][N], ans1, ans2, num[N], same[N][N];
int can(int idx, int cnt)
{
    bool flag = 0;
    for (int i=1;i<=5;i++)
    {
        if ((i<idx||i>idx+cnt-1)&&same[i][0]>1)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        return 0;
    else
        return 1;
}
int main (){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=5;j++)
        {
            cin >> f[i][j];
            same[j][f[i][j]]=1;
        }

    }
    for (int i=0;i<10;i++)
    {
        for (int j=1;j<=5;j++)
            same[j][0]+=same[j][i];
    }

    if (n==1)
    {
        cout << 81 <<endl;
        return 0;
    }
    for (int i=1;i<=5;i++)
    {
        if(!can(i, 1))
            continue;
        ans1+=10-same[i][0];
    }
    for (int i=1;i<5;i++)
    {
        bool flag = 0;
        if (!can(i, 2))
            continue;
        for (int j=0;j<=9;j++)
        {
            for (int k=0;k<=9;k++)
            {
                bool flag1=0;
                for (int z=1;z<=n;z++)
                {
                    if (abs(f[z][i]-j)!=abs(f[z][i+1]-k))
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (!flag1)
                    ans2++;
            }
            if (flag)
                break;
        }
    }
    cout << ans1+ ans2 <<endl;
    return 0;
}