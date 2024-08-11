#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 3010;

int n, m;
string s[N];
int cnt[N][26];
char a[N], b[N];

int cmp(char a[], char b[])
{
    for (int i = 0; i < m; i ++ )
    {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    scanf("%d%d", &n, &m);
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        for (int j = 0; j < m; j ++ )
        {
            cnt[i][s[i][j] - 'a'] ++ ;
        }
    }
    for (int i = 1; i <= n; i ++ )
    {
        bool flag = true;
        int idx = 0;
        for (int k = 0; k < 26; k ++ )
        {
            for (int t = 0; t < cnt[i][k]; t ++ )
            {
                a[idx ++ ] = (char)(k + 'a');
            }
        }
        for (int j = 1; j <= n; j ++ )
        {
            if (i == j) continue;
            bool st = true;
            for (int k = 0; k < m; k ++ )
            {
                if (s[i][k] > s[j][k])
                {
                    st = false;
                    break;
                }
            }
            if (st) continue;
            // if (cmp(s[i], s[j]) < 0) continue;
            idx = 0;
            for (int k = 25; k >= 0; k -- )
            {
                for (int t = 0; t < cnt[j][k]; t ++ )
                {
                    b[idx ++ ] = (char)(k + 'a');
                }
            }
            /*
            puts("debug");
            cout << i << " " << j << endl;
            for (int c = 0; c < m; c ++ ) cout << a[c] ;
            cout << endl;
            for (int c = 0; c < m; c ++ ) cout << b[c] ;
            cout << endl;
            puts("debug");
            */
            if (cmp(a, b) >= 0)
            {
                flag = false;
                break;
            }
        }
        if (flag) cout << 1;
        else cout << 0;
    }

    return 0;
}