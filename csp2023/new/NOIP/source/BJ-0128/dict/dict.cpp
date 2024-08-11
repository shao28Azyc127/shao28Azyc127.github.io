#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a, b, t;
char s[3005][3005];
bool cmp(char a, char b)
{
    return a > b;
}
bool cmp2(int a, int b)
{
    if (b == 0)
        return true;
    for (int i = 1; i <= m; i++)
        if (s[a][i] != s[b][i])
            return s[a][i] < s[b][i];
    return false;
}
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
        sort(s[i] + 1, s[i] + m + 1, cmp);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        t = i;
        if (cmp2(t, a))
            t ^= a ^= t ^= a;
        if (cmp2(t, b))
            t ^= b ^= t ^= b;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == a)
            t = b;
        else
            t = a;
        reverse(s[i] + 1, s[i] + m + 1);
        if (cmp2(i, t))
            cout << 1;
        else
            cout << 0;
        reverse(s[i] + 1, s[i] + m + 1);
    }
    cout << endl;
    return 0;
}
