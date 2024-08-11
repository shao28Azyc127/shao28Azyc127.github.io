#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<utility>
#include<map>
#include<queue>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans = 0, cnt = 0;
    cin >> n;
    int t = n;
    while (t)
    {
        cnt++;
        if (ans == 0 && t % 3 == 1)
        {
            ans = cnt;
        }
        t = t - (t + 2) / 3;
    }
    cout << cnt << " " << ans;
    return 0;
}
