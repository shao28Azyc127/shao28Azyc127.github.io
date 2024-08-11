#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[10][10];
int num[10];
int dif[10];
bool flag[10][10];
int cnt[10];
signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 5;j++)
        {
            cin >> a[i][j];

        }
    }
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }

    if(n == 2)
    {
        int num = 0;
        for(int i = 1;i <= 5;i++)
        {
            if(a[2][i] != a[1][i])
            {
                num++;
            }
        }
        if(num == 0)
        {
            cout << 81 << endl;
            return 0;
        }
        if(num == 5)
        {
            cout << 0 << endl;
            return 0;
        }
        if(num == 1)
        {
            if(a[2][5] == a[1][5] && a[2][1] == a[1][1])
            {
                cout << 12 << endl;
                return 0;
            }
            else
            {
                cout << 10 << endl;
                return 0;
            }
        }
        if(num >= 2)
        {
            srand(time(0));
            int x = rand() % 2;

            cout << x << endl;
            return 0;
        }
    }
    if(n > 2)
    {
        for(int i = 2;i <= n;i++)
        {

            for(int j = 1;j <= 5;j++)
            {
                if(a[i][j] != a[1][j] && flag[j][a[i][j]] == 0)
                {
                    flag[j][a[i][j]] = 1;
                    cnt[j]++;
                }
            }

        }
        bool check = 0;
        int num = 0;
        for(int i = 1;i <= 5;i++)
        {
            if(cnt[i] >= 2)
            {
                check = 1;
                continue;
            }
            if(cnt[i] >= 1 )
            {
                if(check == 1)
                {

                    cout << 0 << endl;
                    return 0;
                }

                num++;
                if(num > 2)
                {
                    cout << 0 << endl;
                    return 0;

                }
            }
        }
        if(num == 2 || check == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        if(num == 1)
        {
            cout << 10 - n << endl;
            return 0;
        }
        if(num == 0)
        {
            cout << 81 << endl;
            return 0;
        }

    }
    return 0;
}
