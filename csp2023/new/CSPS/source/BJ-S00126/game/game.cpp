#include<iostream>
#include<memory.h>
using namespace std;
const int maxn = 2e6+10;
char s[maxn];
bool vis[maxn];
int n;

int main()
{
    ios::sync_with_stdio(false);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin.get();
    cin >> s;
    unsigned long long ans = 0;
    bool flag = true;
    memset(vis, 0, sizeof(vis));
    while(flag)
    {
        flag = false;
        for (unsigned i = 0;i<n-1;i++)
        {
            if (vis[i]) continue;
            int first = i, second;
            ++i;
            while(vis[i] && i < n) ++i;
            if (i == n) break;
            second = i;
            while(s[first] != s[i])
            {
                ++i;
                while(vis[i] && i < n) ++i;
                if (i == n) break;
            }
            if (i == n) continue;
            vis[first] = vis[i] = true;
            flag = true;
            ans++;
        }
    }
    flag = true;
    for (unsigned i = 0;i<n;i++)
    {
        if (!vis[i])
        {
            flag = false;
            break;
        }
    }
    if (flag) ans++;
    cout << ans << endl;
    return 0;
}
