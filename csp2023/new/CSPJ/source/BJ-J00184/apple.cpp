# include <bits/stdc++.h>
using namespace std;

long long n;
const long long MAXN = 1e8 + 10;
int a[MAXN];

long long f(int x)
{
    int cnt = 2;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
        {
            cnt ++;
            if (cnt == 3)
            {
                cnt = 0;
                a[i] = 0;
                if (i == n)
                    return x;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    long long day = 0;
    for (long long i = 1; i <= n; i++)
        a[i] = i;
    long long ans = 0;

    while (true)
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
                flag = false;
        }
        if (flag) break;
        day ++;
        if (f(day) != 0) ans = day;
    }
    cout << day << " " << ans;
    return 0;
}
