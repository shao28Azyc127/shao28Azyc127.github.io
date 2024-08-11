#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define _mp make_pair
#define _pb push_back
#define _1 first
#define _2 second

using namespace std;

ll read()
{
    ll x = 0;
    char c = 0, v = 0;
    do
    {
        c = getchar();
        if(c == '-')
            v = 1;
    } while(c < '0' || c > '9');
    do
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    } while(c >= '0' && c <= '9');
    return v ? -x : x;
}

bool check(int t)
{
    int cnt = 0, mx = -1, mn = 10, fpos = -1, lpos = -1;
    for(int i = 0; i < 5; i++, t /= 10)
        if(t % 10)
        {
            cnt++, mx = max(mx, t % 10), mn = min(mn, t % 10), lpos = i;
            if(fpos == -1)
                fpos = i;
        }
    if(cnt != 1 && cnt != 2)
        return 0;
    if(cnt == 2)
        return mx == mn && fpos == lpos - 1;
    return 1;
}

bool check(int x, int y)
{
    int t = 0;
    for(int i = 0; i < 5; i++, x /= 10, y /= 10)
        t = (t << 3) + (t << 1) + ((y - x) % 10 + 10) % 10;
    return check(t);
}

bool ok[100007];
int n;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    n = read();
    for(int i = 0; i < 100000; i++)
        ok[i] = 1;
    for(int i = 1; i <= n; i++)
    {
        int x = 0;
        for(int j = 0; j < 5; j++)
            x = (x << 3) + (x << 1) + read();
        for(int j = 0; j < 100000; j++)
            if(!check(j, x))
                ok[j] = 0;
    }
    int ans = 0;
    for(int i = 0; i < 100000; i++)
        if(ok[i])
            ans++;
    printf("%d\n", ans);
    return 0;
}
