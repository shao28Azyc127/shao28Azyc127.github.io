#include <bits/stdc++.h>
using namespace std;

// open the freopen!!!

int n;
long long ans = 0;
char c[2000010];
bool flagans = 0;

int fc[2000010];  // 0 洪水没到，1 洪水中间，2 洪水边缘

long long dfs(int l, int r, bool flood)
{
    // 单一 combo 两边均可，一边多 combo （简称多连）只能向右！
    int ret = 1, nowl = l - 1, nowr = r + 1;
    char now = c[nowr];
    bool floodnow = 0;

    if(now == 0)
    {
        fc[l] = fc[r] = 2;
        return 1;
    }

    if(c[nowl] != now && c[nowr + 1] != now)
    {
        if(flood) fc[l] = fc[r] = 1;
        else fc[l] = fc[r] = 2;
        return 1; // 左右不同直接停
    }

    /****/
    // 左右都仅有 1，下一次 dfs

    if(c[nowl] == now && c[nowr + 1] != now)
    {
        fc[nowl] = fc[nowr] = 1;
        return dfs(nowl, nowr, floodnow) + 1;
    }

    /****/
    // 左有无 1 + 往右拓展

    floodnow = 1;

    fc[nowr] = 1;
    bool flag = 0; // 左边是否有单一
    if(c[nowl] == now)
    {
        fc[nowl] = 1;
        flag = 1;
    }
    else nowl++;

    ret--;
    while(c[nowr + 1] == now) // 开始看右边多连
    {
        nowr++;
        ret++;
        fc[nowr] = 1;
    }

    if(flag) ret *= 2;

    return ret + dfs(nowl, nowr, floodnow);
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if(i != 1 && c[i] == c[i - 1]) flagans = 1;
    }

    if(!flagans) {cout << 0 << endl; return 0;}

    int combo = 1;
    for(int i = 2; i <= n; i++)
    {
        if(c[i] == c[i - 1])
        {
            fc[i - 1] = fc[i] = 1;
            combo++;
        }
        else combo = 1;
        if(c[i] == c[i - 1] && c[i] != c[i + 1])
        {
            int lo = i - combo + 1, ro = i;
            ans += dfs(lo, ro, 0);
            ans += ((combo * (combo - 1)) - 1);
        }
    }
    int cnt2 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(fc[i] == 2) cnt2++;
        if(fc[i] == 0 || i == n)
        {
            cnt2 /= 2;
            if(cnt2 == 0 || cnt2 == 1)
            {
                cnt2 = 0;
                continue;
            }
            ans += ((cnt2 * (cnt2 - 1)) / 2);
        }
    }
    cout << ans << endl;
    return 0;
}