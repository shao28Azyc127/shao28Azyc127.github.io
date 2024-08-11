#include<iostream>

using namespace std;

int f[1005][1005];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(s[i] == s[i + 1])
        {
            f[i][i + 1] = true;
            cnt++;
        }
    while(true)
    {
        bool flag = true;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if(f[i][j] == true)
                {
                    if(s[i - 1] == s[j + 1] && f[i - 1][j + 1] == false)
                    {
                        f[i - 1][j + 1] = true;
                        flag = false;
                        cnt++;
                    }
                    for(int k = j + 1; k <= n; k++)
                        if(f[j + 1][k] == true && f[i][k] == false)
                        {
                            f[i][k] = true;
                            flag = false;
                            cnt++;
                        }
                }
        if(flag == true) break;
    }
    cout << cnt << endl;
    return 0;
}
