/*
2
2 8 3 5 5
2 8 3 5 1
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
int g[N][10];
int g2[N][10];
int a[110][10];
int cnt = 0;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= 5; j ++) 
            cin >> g[i][j];
    if(n == 1) cout << 81 << endl;
    else
    {
        for(int i = 1;  i<= 9; i ++)
            for(int j = 1; j <=5; j ++)
                a[cnt ++][j] = i; 
        for(int i = 1; i <= 9; i ++)
            for(int j = 1;j < 5; j ++)
                a[cnt][j] = a[cnt][j + 1] = i, cnt ++ ;
        if(n == 2)
        {
            int ans = 0;
            for(int i = 0; i < cnt; i ++)
            {
                for(int j = 1; j <= 5; j ++)
                {
                    g2[1][j] = (g[1][j] + a[i][j]) % 10;
                }
                bool chk = 1;
                for(int b = 0; b < cnt; b ++)
                {
                    for(int c = 1; c <= 5; c ++)
                    {
                        g2[2][c] = (g[2][c] + a[b][c]) % 10;
                    }
                    bool flag = 1;
                    for(int p = 1; p <= 5; p ++)
                    {
                        if(g2[1][p] != g2[2][p])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1)
                    {
                        ans ++ ;
                        chk = 0;
                        break;
                    }
                }  
            }
            cout << ans << endl;
        }
        else
        {
            int ans = 0;
            for(int i = 0; i < 45; i ++)
            {
                bool fff = 1;
                for(int j = 1; j <= 5; j ++) g2[1][j] = (g[1][j] + a[i][j]) % 10;
                for(int j = 2; j <= n; j ++)
                {
                    int cnt = 0;
                    for(int k = 1; k <= 5; k ++)
                        if(g[j][k] != g2[1][k])
                            cnt++ ;
                    if(cnt != 1) 
                    {
                        fff = 0;
                        break;
                    }
                }
                if(fff == 1) ans += 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}