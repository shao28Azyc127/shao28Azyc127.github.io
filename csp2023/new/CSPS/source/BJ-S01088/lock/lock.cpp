#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<cstring>
#include<map>
using namespace std;

int a[10];

int main()
{
    map<string, int> m;
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> a[j];
        }
        for(int j = 1; j <= 5; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                a[j]++;
                a[j] %= 10;
                string s = "";
                for (int q = 1; q <= 5; q++)
                {
                    s += '0' + a[q];
                }
                m[s]++;
            }
            a[j]++;
        }
        for(int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                a[j]++, a[j + 1]++;
                a[j] %= 10, a[j + 1] %= 10;
                string s = "";
                for (int q = 1; q <= 5; q++)
                {
                    s += '0' + a[q];
                }
                m[s]++;
            }
            a[j]++, a[j + 1]++;
        }
    }
    int cnt = 0;
    for (char _1 = '0'; _1 <= '9'; _1++)
        for (char _2 = '0'; _2 <= '9'; _2++)
            for (char _3 = '0'; _3 <= '9'; _3++)
                for (char _4 = '0'; _4 <= '9'; _4++)
                    for (char _5 = '0'; _5 <= '9'; _5++)
                    {
                        string s = "";
                        s += _1;
                        s += _2;
                        s += _3;
                        s += _4;
                        s += _5;
                        if (m[s] == n) cnt++;
                    }
    cout << cnt << endl;

    return 0;
}
