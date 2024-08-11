#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, res, st[N], ed[N];
char s[N];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", s + 1);
    if(n >= 2e5)
    {
        int ans = 0;
        for(int i = 1; i < n; ++ i)
        {
            if(s[i] == s[i + 1]) ++ ans;
        }
        printf("%d\n", ans);
        return 0;
    }
    for(int i = 1; i < n; ++ i)
    {
        if(s[i] == s[i + 1])
        {
            ++ res;
            int l = i, r = i + 1;
            ed[i + 1] = i;
            st[i] = i + 1;
            while(l >= 1 && r <= n)
            {
                if(l - 1 == 0 || r + 1 == n + 1) break;
                if(s[l - 1] == s[r + 1])
                {
                    ++ res;
                    st[l - 1] = r + 1;
                    ed[r + 1] = l - 1;
                    -- l, ++ r;
                }
                else break;
            }
        }
    }
    for(int i = 1; i <= n; ++ i)
    {
        if(ed[i] && st[i + 1] && st[ed[i]] != st[i + 1])
        {
            ++ res;
            ed[st[i + 1]] = ed[i];
            st[ed[i]] = st[i + 1];
        }
    }
    printf("%d\n", res);
    return 0;
}