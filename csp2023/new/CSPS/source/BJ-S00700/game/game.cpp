#include <iostream>
using namespace std;
string s;
long long n, cnt, ans, now;
struct Edge
{
    int c, fa, cnt = 0;
} a[2000005];
int e[2000005][26];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    a[0] = {0, 0, 1};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == a[now].c)
        {
            now = a[now].fa;
            ans += a[now].cnt;
            a[now].cnt++;
        }
        else
        {
            int &son = e[now][s[i] - 'a'];
            if (son == 0)
            {
                son = ++cnt;
                a[cnt] = {s[i], now};
            }
            now = son;
            ans += a[now].cnt;
            a[now].cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
