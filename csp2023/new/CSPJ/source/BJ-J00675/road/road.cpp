#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    float dis[100000] = {0};
    float price[100000] = {0};
    for (int i = 0; i < n-1; i++)
    {
        cin >> dis[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        sum += dis[i];
    }
    float l = sum / d;
    float ans = l * price[0];
    cout << ans << endl;
    return 0;
}
