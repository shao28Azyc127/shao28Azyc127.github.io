#include <bits/stdc++.h>
using namespace std;

int a[3005][27];

int first[3010];

int last[3010];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        first[i] = 27;
        for(int j=0; j<m; j++)
        {
            int u = s[j] - 'a' + 1;
            a[i][u] ++;
            first[i] = min(first[i], u);
            last[i] = max(last[i], u);
        }
    }
    /*
    for(int i=1; i<=n; i++)
    {
        cout << first[i] << " " << last[i] << endl;
        for(int j=1; j<=26; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */
    for(int i=1; i<=n; i++)
    {
        int flag = 1;
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(last[j] > first[i]) continue;
            if(last[j] <= first[i])
            {
                cout << 0;
                flag = 0;
                break;
            }
            /*
            if(last[j] == first[i])
            {
                int k = last[j];
                if(a[j][k] > a[i][k]) continue;
                if(a[j][k] <= a[i][k])
                {
                    cout << 0;
                    flag = 0;
                    break;
                }
            }
            */
        }
        if(flag) cout << 1;
    }
}
// 216
