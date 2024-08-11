// hope i can have tg1= <3
// zyc ak ioi, ranger_cw ak ioi, gaochunzhen ak ioi, 2338bitexplo ak ioi,
// end1esssummer ak ioi, yuanjiabao ak ioi, baka24 ak ioi, 12345600k akioi,
// liyuqiao11 ak ioi, tsaizhetorg ak ioi, moyunallgorithm ak ioi,
// y2y7m ak ioi, _masppy_ ak ioi, terryhansu ak ioi, yywd ak ioi
// if you are reading this, you ak ioi!
// and hope me, Br00k5xx to ak ioi!
// please wish me have tg1=!!!!!!!!!!!!!
// ZYC AK IOI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11111
// if i have tg1=, i will tell my girlfriend ayt(not oier) i like her.
// by the way, wish you have tg1= and happy everyday!!!!
//yours, br00k5xx.
#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
set <string> st;
int cnt[100];
bool check(string x)
{
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < x.size(); i++)
    {
        cnt[x[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (cnt[i] & 1)
            return 0;
    for (int i = 0; i < x.size() - 1 && x.size(); i++)
    {
        if (x[i] == x[i + 1])
        {
            string h = x.substr(0, i);
            if (i + 2 < x.size())
                h = h + x.substr(i + 2);
            x = h;
            i = -1;
        }
    }
    if (x.size())
        return 0;
    else
        return 1;
}
signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, ans = 0;
    scanf("%lld", &n);
    cin >> s;
    for (int i = 2; i <= n - (n & 1); i += 2)
    {

        for (int j = 0; j < n - (i - 1); j++)
        {
            if (check(s.substr(j, i)))
                ans++;
        }
    }
    printf("%lld", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
