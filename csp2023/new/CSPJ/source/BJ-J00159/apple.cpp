#include <iostream>
#include <cstdio>
using namespace std;

int vis[10000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    for (int len = 1;; ++len)
    {
        int cnt = 2;
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i] != 0) continue;
            cnt++;
            if (cnt == 3) vis[i] = len, sum++, cnt = 0;
        }
        if (sum == n)
        {
            cout << len << " " << vis[n] << endl;
            return 0;
        }
    }
    return 0;
}
