#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, M[100005], X[100005], ans = 0 , dis = 0, num = 0;
    freopen("road.in", "r", stdin);
    freopen("road.out" , "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> M[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }
    for (int i = 1; i <= n; i += num)
    {
        if (M[i] > M[i + 1])
        {
            ans += M[i] / d * X[i];
            dis += M[i];
            num += 1;
        }
        else
        {
            while (M[i] < M[i + 1])
            {
                dis += M[i];
                num += 1;
            }
            ans += dis / d * X[i];
        }

    }
    cout << ans;
    return 0;
}