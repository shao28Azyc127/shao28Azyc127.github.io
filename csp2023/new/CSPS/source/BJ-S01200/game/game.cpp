#include <bits/stdc++.h>
using namespace std;

inline string strread()
{
    register char c;
    scanf("%c", &c);
    register string s = "";
    while (c != ' ' && c != '\n')
    {
        s = s + c;
        scanf("%c", &c);
    }
    return s;
}

inline int intread()
{
    register bool flag = false;
    register int n = 0;
    register char c;
    scanf("%c", &c);
    if (c == '-')
    {
        flag = true;
        scanf("%c", &c);
    }
    while (c != ' ' && c != '\n')
    {
        n = n * 10 + c - '0';
        scanf("%c", &c);
    }
    if (flag) n *= -1;
    return n;
}

inline void strprint(string s)
{
    for (register int i = 0; i < s.length(); i++)
        printf("%c", s[i]);
    printf("\n");
}

const int NR = 2e6 + 10;
char stk[NR] = {};
int sz = 0;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n = intread();
    string s = strread();
    s = " " + s;

    long long ans = 0;
    for (int l = 1; l <= n; l++)
    {
        sz = 0;
        for (int i = l; i <= n; i++)
        {
            if (s[i] == stk[sz]) sz--;
            else stk[++sz] = s[i];
            if (sz == 0) ans++;
        }
    }
    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
