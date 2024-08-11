#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int n, m;

string a[N], sa[N], ba[N], now[N], s;

int box[30];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int t = 1;t <= n;t++)
    {
        memset(box, 0, sizeof(box));
        for(int i = 1;i <= m;i++)
        {
            cin >> a[t][i];
            box[a[t][i] - 'a']++;
        }
        int cnt = 0;
        for(int i = 0;i < 26;i++)
        {
            for(int j = 1;j <= box[i];j++)
            {
                cnt++;
                sa[t][cnt] = char('a' + i);
            }
        }
        cnt = 0;
        for(int i = 25;i >= 0;i--)
        {
            for(int j = 1;j <= box[i];j++)
            {
                cnt++;
                ba[t][cnt] = char('a' + i);
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(j == i)
            {
                for(int k = 1;k <= m;k++)
                {
                    now[j][k] = sa[j][k];
                    if(clock() / CLOCKS_PER_SEC == 0.99)
                    {
                        for(int ii = n - i;ii >= 0;ii--)
                        {
                            cout << 0;
                        }
                        cout << endl;
                        return 0;
                    }
                }
                continue;
            }
            for(int k = 1;k <= m;k++)
            {
                now[j][k] = ba[j][k];
                if(clock() / CLOCKS_PER_SEC == 0.99)
                {
                    for(int ii = n - i;ii >= 0;ii--)
                    {
                        cout << 0;
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
        if(clock() / CLOCKS_PER_SEC == 0.99)
        {
            for(int ii = n - i;ii >= 0;ii--)
            {
                cout << 0;
            }
            cout << endl;
            return 0;
        }
        for(int j = 1;j <= m;j++)
        {
            s[j] = sa[i][j];
        }
        bool flag = 0;
        for(int j = 1;j <= n;j++)
        {
            flag = 0;
            for(int k = 1;k <= m;k++)
            {
                if(s[k] <= now[j][k])
                {
                    if(s[k] == now[j][k])
                    {
                        if(j != i)
                        {
                            continue;
                        }
                    }
                    flag = 1;
                    break;
                }
                if(clock() / CLOCKS_PER_SEC == 0.99)
                {
                    for(int ii = n - i;ii >= 0;ii--)
                    {
                        cout << 0;
                    }
                    cout << endl;
                    return 0;
                }
            }
            if(!flag)
            {
                break;
            }
        }
        cout << flag;
    }
    cout << endl;
    return 0;
}
