#include <iostream>
using namespace std;

int a[10][10];
int dif[110];
int cnt = 0;
int f[101];
int ans = 0;
int tr[10];

int dnum(int x[],int y[])
{
    int sum = 0;
    for(int i = 1;i <= 5;i ++)
    {
        if(x[i] != y[i])
        {
            sum++;
        }
    }
    return sum;
}

bool check(int x[],int y[])
{
    int cu = 0;
    int cnt = 0;
    for(int i = 1;i <= 5;i ++)
    {
        if(cnt > 2)
        {
            return false;
        }
        if(x[i] != y[i])
        {
            if(cu== 0)
            {
                cu = x[i] - y[i];
                cnt++;
            }
            else if(x[i] - y[i] == cu)
            {
                cnt++;
                continue;
            }
            else
                return false;
        }

    }
    return true;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 81;
        return 0;
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= 5;j ++)
        {
            cin>> a[i][j];
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = i+1;j <= n;j ++)
        {
            for(int k = 1;k <= 5;k ++)
            {
                if(a[i][k] != a[j][k])
                {
                    dif[k] ++;
                    if(dif[k] == 1)
                    {
                        cnt++;
                        f[cnt] = k;
                    }

                }
            }
        }
    }
    if(cnt == 1 && n == 2)
    {
        int ans = 10;
        cout << ans;
        return 0;
    }
    else
    {
        for(int b = 0;b <= 9;b ++)
        {
            for(int c = 0; c <= 9;c ++)
            {
                for(int k = 0;k <= 9;k ++)
                {
                    for(int x = 0;x <= 9;x ++)
                    {
                        for(int y = 0;y <= 9;y ++)
                        {
                            tr[1] = b;
                            tr[2] = c;
                            tr[3] = k;
                            tr[4] = x;
                            tr[5] = y;
                            bool ff = 1;
                            for(int i = 1;i <= n;i ++)
                            {
                                if(!(dnum(tr,a[i]) == 1 || (dnum(tr,a[i]) == 2 && check(tr,a[i]))))
                                {
                                    ff = 0;
                                    break;
                                }
                            }
                            if(ff)
                                ans++;
                        }
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}
