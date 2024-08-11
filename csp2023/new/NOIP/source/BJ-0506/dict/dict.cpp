#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[3005][3005]; //maxn
int c[3005][3005]; //minn
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
        {
            char s;
            cin >> s;
            b[i][j] = s - 'a';
            c[i][j] = b[i][j];
        }
    //b-maxn;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < m;j++)
        {
            bool flag = 1; int place = j; 
            for(int k = j+1;k <= m;k++)
                if(b[i][k] > b[i][place])
                {
                    place = k;
                    flag = 0;
                }
            if(flag) continue;
            swap(b[i][j],b[i][place]);
//            cout << j << " " << place << endl;
            break;
        }
    }
/*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
*/
    //c-minn;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < m;j++)
        {
            bool flag = 1; int place = j; 
            for(int k = j+1;k <= m;k++)
                if(c[i][k] <= c[i][place])
                {
                    place = k;
                    flag = 0;
                }
            if(flag) continue;
            swap(c[i][j],c[i][place]);
            break;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        bool flagn = 1;
        for(int j = 1;j <= n;j++)
        {
            if(i == j) continue;
            int flag = 1;
            for(int k = 1;k <= m;k++)
            {
                if(c[i][k] > b[j][k])
                {
                    flag = 0;
                    break;
                }
                if(c[i][k] < b[j][k])
                {
                    flag = 2;
                    break;
                }
            }
            if(flag != 2)
            {
                flagn = 0;
                break;
            }
        }
        if(flagn) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return 0;
}