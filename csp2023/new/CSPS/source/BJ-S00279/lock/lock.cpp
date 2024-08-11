#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

int n;
int a[10][6];

bool check(int aa[],int x)
{
    int cnt = 0;
    bool flag[6];
    for(int i = 1;i <= 5;i++)
        flag[i] = true;
    for(int i = 1;i <= 5;i++)
    {
        if(a[x][i] == aa[i])
            cnt++,flag[i] = false;
    }
    if(cnt == 4)
        return true;
    else if(cnt == 3)
    {
        for(int i = 1;i <= 4;i++)
        {
            if(flag[i] && flag[i + 1] && (aa[i] + 10 - a[x][i]) % 10 == (aa[i + 1] + 10 - a[x][i + 1]) % 10)
                return true;
        }
    }
    return false;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= 5;j++)
        {
            cin >> a[i][j];
        }
    int ans = 0;
    for(int i1 = 0;i1 <= 9;i1++)
        for(int i2 = 0;i2 <= 9;i2++)
            for(int i3 = 0;i3 <= 9;i3++)
                for(int i4 = 0;i4 <= 9;i4++)
                    for(int i5 = 0;i5 <= 9;i5++)
                    {
                        int aa[6] = {0,i1,i2,i3,i4,i5};
                        bool f = true;
                        for(int i = 1;i <= n;i++)
                            if(!check(aa,i))
                            {
                                f = false;
                            }
                        if(f)
                            ans++;
                    }
    cout << ans << endl;
    return 0;
}
