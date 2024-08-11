#include <bits/stdc++.h>
using namespace std;

int a[100005], n;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    int lock[10][10];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cout << lock[i][j];
        }
    }
    int cnt = 0, temp = 5, cuo[10];
    while(temp--)
    {
        for(int i = 2; i <= n; i++)
        {
            if(lock[i][temp] != lock[i-1][temp])
            {
                cnt++;
                cuo[cnt] = temp;
                break;
            }
        }
    }
    bool vis = false;
    sort(cuo+1, cuo+cnt+1);
    for(int i = 1; i <= cnt; i++)
    {
        if(cuo[i+1] - cuo[i] > 1)
        {
            cout << 0;
            return 0;
        }
    }
    if(cnt == 5)
        cout << 0;
    if(cnt == 1)
        cout << 10;
    if(cnt == 2)
        cout << 4;
    if(cnt == 3)
        cout << 2;
    if(cnt == 4)
        cout << 1;
    return 0;
}
