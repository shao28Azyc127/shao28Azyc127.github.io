#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int n, m, a[N];
char ch[N];
string s[N], mx[N], mi[N];
string t[20];

struct node
{
    string s;
    int id;
}b[20];

bool cmp(node x, node y)
{
    return x.s < y.s;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> s[i];
    }
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if(m == 1)
    {
        int mi = 30;
        for(int i = 1; i <= n; ++ i)
        {
            mi = min(mi, s[i][0] - 'a');
        }
        for(int i = 1; i <= n; ++ i)
        {
            if((s[i][0] - 'a') == mi)
            {
                cout << 1;
            }
            else cout << 0;
        }
        return 0;
    }
    string tmp = s[1];
    int pos = 1;
    for(int i = 2; i <= n; ++ i)
    {
        if(s[i] < tmp)
        {
            pos = i;
            tmp = s[i];
        }
    }
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = 0; j < m; ++ j)
        {
            ch[j] = s[i][j];
        }
        sort(ch, ch + m);
        mi[i] = s[i];
        mx[i] = s[i];
        for(int j = 0; j < m; ++ j) mi[i][j] = ch[j];
        for(int j = 0; j < m; ++ j) mx[i][j] = ch[m - j - 1];
    }
    for(int i = 1; i <= n; ++ i)
    {
        bool ag = 1;
        string tt = mi[i];
        for(int j = 1; j <= n; ++ j)
        {
            if(j == i) continue;
            if(tt > mx[j])
            {
                ag = 0;
                break;
            }
        }
        if(ag || i == pos) cout << 1;
        else cout << 0;
    }
    return 0;
}