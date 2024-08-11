#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3e3 + 5;
int n, m, a[N][N], b[N][50], c[N][50], mn1, mn2;
string s;

bool check_1(int x, int y)
{
    if(y == 0)
        return true;
    for(int i = 26;i >= 1;i--)
    {
        if(b[x][i] < b[y][i])
            return true;
        else if(b[x][i] > b[y][i])
            return false;
    }
    return false;
}

bool check_2(int x, int y)
{
    if(y == 0)
        return true;
    for(int i = 0;i <= 26;i++)
        c[x][i] = b[x][i], c[y][i] = b[y][i];
    int l = 0, r = 26;
    while(l < r)
    {
        while(c[x][l] == 0 && l <= 26)
            l++;
        while(r >= 0 && c[y][r] == 0)
            r--;
        //printf("%d %d\n", l, r);
        if(l > 26 || r < 0)
            return false;
        if(l < r)
            return true;
        else if(l > r)
            return false;
        if(c[x][l] > c[y][r])
            c[x][l] -= c[y][r], c[y][r] = 0;
        else
            c[y][r] -= c[x][l], c[x][l] = 0;
    }
    return false;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        cin >> s;
        s = "#" + s;
        for(int j = 1;j <= m;j++)
            a[i][j] = s[j] - 'a';
        for(int j = 1;j <= m;j++)
            b[i][a[i][j]]++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(check_1(i, mn1))
            mn2 = mn1, mn1 = i;
        else if(check_1(i, mn2))
            mn2 = i;
    }
    //printf("%d %d\n", mn1, mn2);
    for(int i = 1;i <= n;i++)
    {
        if(i == mn1)
            printf(check_2(i, mn2) ? "1" : "0");
        else
            printf(check_2(i, mn1) ? "1" : "0");
    }
    return 0;
}
