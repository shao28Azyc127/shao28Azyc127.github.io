#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, mx[3005], mi[3005], i, j;
char c;
string ma[3005], mn[3005];
inline void cswp(char &x, char &y)
{
    c = x, x = y, y = c;
}
set <string> st;
signed main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (i = 1; i <= n; i++)
    {
        ma[i].resize(3005), mn[i].resize(3005);
        scanf("%s", &ma[i][1]);
        mx[m] = mi[m] = m;
        mn[i] = ma[i];
        for (j = m - 1; j >= 1; j--)
        {
            if (ma[i][j] > ma[i][mx[j + 1]])
                mx[j] = j;
            else
                mx[j] = mx[j + 1];
            if (mn[i][j] < mn[i][mi[j + 1]])
                mi[j] = j;
            else
                mi[j] = mi[j + 1];
        }
        for (j = 1; j <= m; j++)
        {
            if (mx[j] != j)
            {
                cswp(ma[i][j], ma[i][mx[j]]);
                break;
            }
        }
        for (j = 1; j <= m; j++)
        {
            if (mi[j] != j)
            {
                cswp(mn[i][j], mn[i][mi[j]]);
                break;
            }
        }
        st.insert(ma[i]);
    }
    for (i = 1; i <= n; i++)
    {
        st.insert(mn[i]);
        if (*(st.begin()) == mn[i])
            putchar('1');
        else
            putchar('0');
        if (ma[i] != mn[i])
            st.erase(mn[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}