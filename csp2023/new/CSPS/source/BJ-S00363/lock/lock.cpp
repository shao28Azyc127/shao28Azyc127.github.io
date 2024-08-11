#include<bits/stdc++.h>
#pragma GCC(2)
using namespace std;
int a[10][10] , n , ans[100005] = {} , anstmp = 0 , cnt = 0;
bool isn(int a1 , int a2 , int a3 , int a4 , int a5)
{
    int tmp = 10000 * a1 + 1000 * a2 + 100 * a3 + 10 * a4 + a5;
    for(int i = 0 ; i < anstmp ; i++)
    {
        if(ans[i] == tmp)
        {
            return false;
        }
    }
    ans[anstmp] = tmp;
    anstmp++;
    return true;
}
bool isnn(int a1 , int a2 , int a3 , int a4 , int a5)
{
    int tmp = 10000 * a1 + 1000 * a2 + 100 * a3 + 10 * a4 + a5;
    for(int i = 0 ; i < anstmp ; i++)
    {
        if(ans[i] == tmp)
        {
            return true;
        }
    }
    ans[anstmp] = tmp;
    anstmp++;
    return false;
}
int main()
{
    freopen("lock.in" , "r" , stdin);
    freopen("lock.out" , "w" , stdout);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 1 ; j < 6 ; j++)
        {
            cin >> a[i][j];
        }
        ans[anstmp]= a[i][1] * 10000 + a[i][2] * 1000 + a[i][3] * 100 + a[i][4] * 10 + a[i][5];
        anstmp++;
    }
    if(n == 1)
    {
        int tmp[6];
        for(int j = 1 ; j <= 5 ; j++)
        {
            tmp[j] = a[0][j];
        }
        for(int j = 1 ; j <= 5 ; j++)
        {
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp1 = tmp[j];
                tmp[j] = (tmp[j] + k) % 10;
                if(isn(tmp[1] , tmp[2] , tmp[3] , tmp[4] , tmp[5]))
                {
                    cnt++;
                }
                tmp[j] = tmp1;
            }
        }
        for(int j = 1 ; j <= 5 ; j++)
        {
            tmp[j] = a[0][j];
        }
        for(int j = 1 ; j <= 4 ; j++)
        {
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp1 = tmp[j] , tmp2 = tmp[j + 1];
                tmp[j] = (tmp[j] + k) % 10;
                tmp[j + 1] = (tmp[j + 1] + k) % 10;
                if(isn(tmp[1] , tmp[2] , tmp[3] , tmp[4] , tmp[5]))
                {
                    cnt++;
                }
                tmp[j] = tmp1;
                tmp[j + 1] = tmp2;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    else
    {
        int tmp[6];
        for(int j = 1 ; j <= 5 ; j++)
        {
            tmp[j] = a[0][j];
        }
        for(int j = 1 ; j <= 5 ; j++)
        {
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp1 = tmp[j];
                tmp[j] = (tmp[j] + k) % 10;
                isn(tmp[1] , tmp[2] , tmp[3] , tmp[4] , tmp[5]);
                tmp[j] = tmp1;
            }
        }
        for(int j = 1 ; j <= 5 ; j++)
        {
            tmp[j] = a[0][j];
        }
        for(int j = 1 ; j <= 4 ; j++)
        {
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp1 = tmp[j] , tmp2 = tmp[j + 1];
                tmp[j] = (tmp[j] + k) % 10;
                tmp[j + 1] = (tmp[j + 1] + k) % 10;
                isn(tmp[1] , tmp[2] , tmp[3] , tmp[4] , tmp[5]);
                tmp[j] = tmp1;
                tmp[j + 1] = tmp2;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    for(int i = 1 ; i < n ; i++)
    {
        int tmp[6];
        for(int j = 1 ; j <= 5 ; j++)
        {
            tmp[j] = a[i][j];
        }
        for(int j = 1 ; j <= 5 ; j++)
        {
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp1 = tmp[j];
                tmp[j] = (tmp[j] + k) % 10;
                if(!isn(tmp[1] , tmp[2] , tmp[3] , tmp[4] , tmp[5]))
                {
                    cnt++;
                }
                tmp[j] = tmp1;
            }
        }
        for(int j = 1 ; j <= 5 ; j++)
        {
            tmp[j] = a[i][j];
        }
        for(int j = 1 ; j <= 4 ; j++)
        {
            for(int k = 1 ; k <= 9 ; k++)
            {
                int tmp1 = tmp[j] , tmp2 = tmp[j + 1];
                tmp[j] = (tmp[j] + k) % 10;
                tmp[j + 1] = (tmp[j + 1] + k) % 10;
                if(!isn(tmp[1] , tmp[2] , tmp[3] , tmp[4] , tmp[5]))
                {
                    cnt++;
                }
                tmp[j] = tmp1;
                tmp[j + 1] = tmp2;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
