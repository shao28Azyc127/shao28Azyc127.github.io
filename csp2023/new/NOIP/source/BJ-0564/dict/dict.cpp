#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
char big[3000][3000], small[3000][3000];

bool cmp(char a, char b)
{
    return a > b;
}

bool cmp1(int a, int b, int p)
{
    if (p >= m)
    {
        return false;
    }

    if (small[a][p] < big[b][p])
    {
        return true;
    }
    else if (small[a][p] > big[b][p])
    {
        return false;
    }
    else
    {
        return cmp1(a, b, p + 1);
    }
}

bool check(int a)
{
    for (int i = 0; i < n; i++)
    {
        if (i != a)
        {
            if (!cmp1(a, i, 0))
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> big[i][j];
            small[i][j] = big[i][j];
        }
        sort(big[i], big[i] + m, cmp);
        sort(small[i], small[i] + m);
    }

    if (n == 1)
    {
        cout << 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (check(i))
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
    cout << endl;

    return 0;
}