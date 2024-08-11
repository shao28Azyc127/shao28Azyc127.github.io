#include<bits/stdc++.h>
using namespace std;

int n, a[1000010];

int check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
            return i;
    return -1;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    if (n <= 3)
    {
        cout << n << " " << n << endl;
        return 0;
    }
    int cnt = 0, ans;
    if (n % 3 == 1)
        ans = 1;
    
    while (check() != -1)
    {
        cnt++;
        int sum = 0;
        for (int i = check(); i <= n; i++)
        {
            if (a[i] == 0)
                sum++;
            if (sum % 3 == 1 && a[i] == 0)
            {
                if (i == n)
                    ans = cnt;
                a[i] = 1;
            }
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}