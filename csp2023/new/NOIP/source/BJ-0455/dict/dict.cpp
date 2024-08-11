#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string mins[3010], maxs[3010];

string ma(string s)
{
    if (s.length() == 1) return s;
    for (int i = 0; i <= s.length() - 2; i++)
    {
        char maxn = 'a' - 1;
        int maxid;
        for (int j = i + 1; j <= s.length() - 1; j++)
        {
            if (s[j] > maxn)
            {
                maxn = s[j];
                maxid = j;
            }
        }
        if (maxn > s[i])
        {
            swap(s[i], s[maxid]);
            return s;
        }
    }
    return s;
}

string mi(string s)
{
    if (s.length() == 1) return s;
    for (int i = 0; i <= s.length() - 2; i++)
    {
        char minn = 'z' + 1;
        int minid;
        for (int j = i + 1; j <= s.length() - 1; j++)
        {
            if (s[j] < minn)
            {
                minn = s[j];
                minid = j;
            }
        }
        if (minn < s[i])
        {
            swap(s[i], s[minid]);
            return s;
        }
    }
    return s;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        mins[i] = mi(s);
        maxs[i] = ma(s);
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= n; j++)
        {
            if (j == i) continue;
            if (mins[i] >= maxs[j])
            {
                flag = false;
                break;
            }
        }
        cout << flag;
        //cout << maxs[i] << endl;
    }
    return 0;
}
