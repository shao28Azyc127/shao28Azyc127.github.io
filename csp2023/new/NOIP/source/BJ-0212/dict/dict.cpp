#include<bits/stdc++.h>
#define N 3010
using namespace std;

int n, m, alp[27];
string smax[N], smin[N];
char s[N][N];
int ans[N];
char tmp[N];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i]);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < 26; ++j) alp[j] = 0;
        for(int j = 0; j < m; ++j) alp[s[i][j] - 'a']++;
        int p = 0;
        for(int j = 0; j < 26; ++j)
        {
            int cnt = alp[j];
            char c = j + 'a';
            while(cnt) {tmp[p] = c; cnt--; p++;}
        }
        smin[i] = tmp;
        p = 0;
        for(int j = 25; j >= 0; --j)
        {
            int cnt = alp[j];
            char c = j + 'a';
            while(cnt){ tmp[p] = c; cnt--; p++;}
        }
        smax[i] = tmp;
    }
    sort(smax + 1, smax + n + 1);
    for(int i = 1; i <= n; ++i)
    {
        if(smin[i] <= smax[1]) ans[i] = 1;
        else ans[i] = 0;
    }
    for(int i = 1; i <= n; ++i) printf("%d", ans[i]);
    return 0;
}