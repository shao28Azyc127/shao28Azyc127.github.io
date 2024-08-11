#include<bits/stdc++.h>
using namespace std;

int n;
int a[10][10];
int chk[10];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >>a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i <= 99999; i++)
    {
        bool flag = true;
        int t = i;
        for(int j = 5; j >= 1; j--)
        {
            chk[j] = t % 10;
            t /= 10;
        }
        for(int j = 1; j <= n; j++)
        {
            int diff[10] = {};
            int cur = 0;
            for(int k = 1; k <= 5; k++)
            {
                if(a[j][k] != chk[k]) diff[++cur] = k;
            }
            if(cur == 0)
            {
                flag = false;
                break;
            }
            if(cur > 2)
            {
                flag = false;
                break;
            }
            if(diff[2] != 0)
            {
                if(diff[2] - diff[1] != 1)
                {
                    flag = false;
                    break;
                }
                int x = diff[1], y = diff[2];
                int xnum = a[j][x] - chk[x] + 10 * (a[j][x] - chk[x] < 0);
                int ynum = a[j][y] - chk[y] + 10 * (a[j][y] - chk[y] < 0);
                if(xnum != ynum)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
