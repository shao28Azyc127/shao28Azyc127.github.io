#include<bits/stdc++.h>
using namespace std;
int v[100010], a[100010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    int sum = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    cnt += sum / d;
    if(sum % d != 0)cnt++;
    cout << cnt * a[1];
    return 0;
}