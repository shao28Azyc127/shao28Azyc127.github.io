#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int sta[20];
int a[20][20];

bool check()
{
    for(int i = 1; i <= n; i++)
    {
        int last = 0, cnt = 0;
        for(int j = 1; j <= 5; j++)
        {
            if(sta[j] - a[i][j] == 0)
            {
                last = 0;
                continue;
            }
            cnt++;
            if(cnt > 2) return 0;
            if(cnt == 2 && last == 0) return 0;
            if(cnt == 2 && sta[j] - a[i][j] != last && sta[j] - a[i][j] - last != 10 && sta[j] - a[i][j] - last != -10) return 0;
            last = sta[j] - a[i][j];
        }
        if(cnt == 0) return 0;
    }
    return 1;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    /*
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }*/
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int a1 = 0; a1 <= 9; a1++)
    {
        sta[1] = a1;
        for(int a2 = 0; a2 <= 9; a2++)
        {
            sta[2] = a2;
            for(int a3 = 0; a3 <= 9; a3++)
            {
                sta[3] = a3;
                for(int a4 = 0; a4 <= 9; a4++)
                {
                    sta[4] = a4;
                    for(int a5 = 0; a5 <= 9; a5++)
                    {
                        sta[5] = a5;
                        if(check()) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    /*
    int dif = 0, pos = 0;
    for(int i = 1; i <= 5; i++)
    {
        if(a[1][i] != a[2][i])
        {
            dif++;
            pos = i;
        }
    }
    if(dif == 1)
    {
        int ans = 0;
        for(int i = 1; i <= 5; i++) sta[i] = a[1][i];
        for(int i = 0; i <= 9; i++)
        {
            sta[pos] = i;
            if(check()) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    if(dif == 2)*/
    return 0;
}
