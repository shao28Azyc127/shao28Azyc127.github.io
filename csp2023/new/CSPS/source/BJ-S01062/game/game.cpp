#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 2e6 + 5;

int n;
int ans = 0;
char str[NR];
int level[NR];
char t[NR];
int sz = 0;

void f(int fl)
{
    ans += max((level[fl] - 1) * level[fl] / 2, 1);
    level[fl] = 0;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    cin >> str;

    int p = 0;
    for (int i = 1;i < n;i ++)
    {
        if (sz > 0 && str[i] == t[sz - 1])
        {
            f(p + 1);
            level[p] ++;
            p --;
            sz --;
        }
        else
        {
            t[sz ++] = str[i];
            p ++;
        }
    }
    f(1);
    f(0);
    cout << ans;
    return 0;
}
