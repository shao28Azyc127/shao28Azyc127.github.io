#include <bits/stdc++.h>
using namespace std;

// open the freopen!!!
// open the freopen!!!
// open the freopen!!!

int n, a[10][6];

int lockdif(int x, int y)
{
    if(x == 0) return y;
    int num = x;
    x = 0;
    y = (y + num) % 10;
    return y;
}

struct locker
{
    int num, val[10] = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    bool flag = 0;
} spec[6];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    if(n == 1) cout << 81 << endl;
    else if(n == 2)
    {
        int ans = 0, cnt = 0, b[2][5];
        for(int i = 1; i <= 5; i++) cin >> a[1][i];
        for(int i = 1; i <= 5; i++)
        {
            cin >> a[2][i];
            if(a[2][i] == a[1][i]) cnt++;
        }
        if(cnt == 4) cout << 8 << endl;
        if(cnt == 3)
        {
            ans = 2;
            int ndl = 0;
            for(int i = 1; i <= 5; i++)
            {
                if(a[2][i] != a[1][i])
                {
                    b[0][ndl] = a[1][i];
                    b[1][ndl] = a[2][i];
                    ndl++;
                }
            }
            if(lockdif(b[0][0], b[0][1]) == lockdif(b[1][0], b[1][1])) ans += 8;
            cout << ans << endl;
        }
        if(cnt == 2) ;
        else if(cnt == 1) cout << 2 << endl;
    }
    else
    {
        int ans = 0;
        for(int i = 1; i <= 5; i++)
        {
            spec[i].val[1] = a[1][i];
        }
        for(int j = 2; j <= n; j++) // 每一组状态
        {
            for(int i = 1; i <= 5; i++) // 每一位
            {
                for(int k = 1; k <= 10; k++) // 动态数组的每一种
                {
                    if(spec[i].val[k] != 10)
                    {
                        if(spec[i].val[k] == a[j][i])
                        {
                            spec[i].num = a[j][i];
                            spec[i].flag = 1;
                            break;
                        }
                    }
                    else {spec[i].val[k] = a[j][i]; break;}
                }
            }
        }
        for(int i = 1; i <= 5; i++)
        {
            if(!spec[i].flag) ans += (10 - n);
        }
        cout << ans << endl;
    }
    return 0;
}