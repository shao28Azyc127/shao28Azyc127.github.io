#include<bits/stdc++.h>
using namespace std;
const int N = 8010;
int n;
char s[N];
int st[N][N];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    for(int i =1; i <= n; i ++) cin >> s[i];
    memset(st, 0, sizeof st);
    for(int i = 2; i <= n; i ++)    
        for(int l = 1; l <= n - i + 1; l ++)
        {
            if(i == 2 && s[l] == s[l + 1]) st[l][l + 1] = st[l + 1][l] =  5;
            else
            {
                int r = l + i - 1;
                if(s[l] == s[r] && st[l + 1][r - 1] != 0) st[l][r] = 3;
                else
                {
                    for(int k = l + 1; k < r - 1; k ++)
                    {
                        if(st[l][k] != 0 && st[k + 1][r] != 0)
                        {
                            st[l][r] = 1;
                            break;
                        }
                    }
                }
            }
        }
    int cnt =0 ;
    /*
    for(int i = 1; i <= n; i ++, cout << endl)
        for(int j = 1; j <= n; j ++)
            cout << st[i][j] << ' ';
    */
    for(int i = 1 ;i <= n; i ++)
        for(int j = i + 1; j <= n; j ++)
            if(st[i][j] != 0)
                cnt ++ ;
    cout << cnt << endl;
    return 0;
}