#include<bits/stdc++.h>
using namespace std;
string mi[3005];
int k[30];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    string mxmi;
    for(int i = 1;i <= 3000;i++) mxmi += 'z';
    for(int l = 1;l <= n;l++)
    {
        memset(k, 0, sizeof(k));
        string s;
        cin >> s;
        for(int i = 0;i < m;i++)
        {
            k[s[i] - 'a' + 1]++;
        }
        string t1 = "";
        for(int i = 1;i <= 26;i++)
        {
            for(int j = 1;j <= k[i];j++)
            {
                mi[l] += char('a' + i - 1);
            }
        }
        for(int i = 26;i >= 1;i--)
        {
            for(int j = 1;j <= k[i];j++)
            {
                t1 += char('a' + i - 1);
            }
        }
        mxmi = min(mxmi, t1);
    }
    for(int i = 1;i <= n;i++)
    {
        if(mi[i] <= mxmi) cout << "1";
        else cout << "0";
    }
    return 0;
}
