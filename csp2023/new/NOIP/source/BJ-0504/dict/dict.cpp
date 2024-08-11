#include <bits/stdc++.h>
using namespace std;

int c1[30];
string s1[20];
char ma[20][2], mi[20][2];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << 1 << endl;
        }
        return 0;
    }
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            c1[i] = c - 'a';
        }
        int mi = 100, id;
        for (int i = 1; i <= n; i++)
        {
            if (c1[i] < mi)
            {
                mi = c1[i];
                id = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << (id == i);
        }
        cout << endl;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> s1[i];
            ma[i][0] = s1[i][0];
            ma[i][1] = s1[i][1];
            if (ma[i][0] < ma[i][1])
            {
                swap(ma[i][0], ma[i][1]);
            }
            mi[i][0] = ma[i][1];
            mi[i][1] = ma[i][0];
        }
        for (int i = 1; i <= n; i++)
        {
            bool f = 1;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (mi[i][0] > ma[j][0])
                {
                    f = 0;
                    break;
                }
                if ((mi[i][0] == ma[j][0]) && (mi[i][1] >= ma[j][1]))
                {
                    f = 0;
                    break;
                }
            } 
            cout << f;
        }
        cout << endl;
    }
    return 0;
}