#include <iostream>
#include <cstdio>
using namespace std;

const int NR = 2e6 + 10;
char a[NR];

long long ans = 0;
char x[NR];

void dfs(int l, int r)
{
    if(l > r) return;
    if(l == r - 1)
    {
        ans++;
        return;
    }
    int cnt = 0, mid = (l + r) / 2, pos_l, pos_r;
    for(int i = l; i <= mid; i++)
    {
        pos_l = i;
        if(a[i] == a[l]) cnt++;
        else break;
    }
    for(int i = r; i > mid; i--)
    {
        pos_r = i;
        if(a[i] == a[l]) cnt++;
        else break;
    }
    if(cnt >= 2)
    {
        ans += 1ll * cnt * cnt / 4;
        if(pos_l == pos_r - 1 && a[pos_l] == a[l]) return;
        dfs(pos_l, pos_r);
        return;
    }
    int st = 1, ed = 1;
    x[st] = a[l];
    for(int i = l + 1; i <= r; i++)
    {
        if(x[ed] == a[i]) ed--;
        else
        {
            ed++;
            x[ed] = a[i];
        }
        if(st > ed && i != r)
        {
            ans++;
            //cout << l << ' ' << r << endl;
            dfs(l, i);
            dfs(i + 1, r);
            return;
        }
    }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    scanf("%s", a + 1);
    int st = 1, ed = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[x[ed]] == a[i]) ed--;
        else
        {
            ed++;
            x[ed] = i;
        }
    }
    if(st > ed) dfs(1, n);
    else
    {
        dfs(1, x[st] - 1);
        for(int i = st; i <= ed - 1; i++)
        {
            dfs(x[i] + 1, x[i + 1] - 1);
        }
        dfs(x[ed] + 1, n);
    }
    cout << ans << endl;
    return 0;
}
