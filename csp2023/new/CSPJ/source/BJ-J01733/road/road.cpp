#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;
int n, d, v[N], a[N], st[N], tmp = 0, ans = 0, s[N], dis, li = 0;

void F(int x)
{
    int minn = N, mini;
    for(int i = 1; i < x; i++)
    {
        if(minn > a[i])
        {
            minn = a[i];
            mini = i;
        }
    }
    st[++tmp] = mini;
    if(mini == 1) return;
    F(mini);
    return;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    s[1] = 0;
    for(int i = 1; i <= n - 1; i++) 
    {
        cin >> v[i];
        s[i + 1] = s[i] + v[i];
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    F(n);
    st[0] = n;
    for(int i = tmp - 1; i >= 0; i--)
    {
        dis = s[st[i]] - s[st[i + 1]] - li;
        if(dis % d == 0)
        {
            ans += (dis / d) * a[st[i + 1]];
        }
        else
        {
            ans += (dis / d + 1) * a[st[i + 1]];
            li = (dis / d + 1) * d - dis;
        }
    }
    cout << ans << endl;
    return 0;
}