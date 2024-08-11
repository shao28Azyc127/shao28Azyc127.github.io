#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 17e3;
string s;
int n, f[N][N], res = 0;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> s;
    for (int r = 0; s[r]; ++ r )
    {
        for (int l = 0; l < r; ++ l )
        {
            if (s[l] == s[r] && (l == (r - 1) || f[l + 1][r - 1] == 1))
            {
                f[l][r] = 1;
                continue;
            }
        }
        for (int l = r - 1, i = -1; l >= 0; -- l )
        {
            if (f[l][r] == 1) i = l;
            else if (i != -1) f[l][r] = f[l][i - 1];
        }
    }

    for (int l = 0; s[l]; ++ l )
        for (int r = l; s[r]; ++ r)
            res += f[l][r];
    printf("%d\n", res);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
