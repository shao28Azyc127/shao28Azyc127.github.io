#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int N = 3005;

int n, m;
string s[N], t[N];

bool check(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (i == j) continue;
        if (s[i] >= t[j]) return false;
    }
    return true;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        t[i] = s[i];
        reverse(t[i].begin(), t[i].end());
    }
    for (int i = 1; i <= n; i++)
    {
        putchar(check(i) ? '1' : '0');
    }
    return 0;
}
