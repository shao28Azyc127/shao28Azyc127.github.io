#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000010;

int n;
string s;
int stk[N], tt;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> s;

    int res = 0;
    for (int len = 2; len <= n; len ++ )
    {
        if (len & 1) continue;

        for (int i = 0; i + len - 1 < n; i ++ )
        {
            tt = 0;
            for (int k = i; k <= i + len - 1; k ++ )
            {
                if (!tt)
                    stk[ ++ tt] = s[k] - 'a';
                else if (s[k] - 'a' == stk[tt])
                    tt -- ;
                else if (s[k] - 'a' != stk[tt])
                    stk[ ++ tt] = s[k] - 'a';
            }

            if (!tt) res ++ ;
        }
    }

    cout << res << endl;

    return 0;
}