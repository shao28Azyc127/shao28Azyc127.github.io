#include <bits/stdc++.h>
using namespace std;

int a[100003] = {};
long long s[100003] = {} , ans = 0 , sum = 0;

int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    int n , m , k , p , q , v;
    cin >> n >> m;
    for (int i = 1 ; i < n ; i++)
    {
        cin >> v;
        s[i] = v + s[i - 1];
    }
    for (int i = 1; i <= n ; i++) cin >> a[i];
    if (s[1] % m) k = s[1] / m + 1;
    else k = s[1] / m;
    p = 1;
    for (int i = 2 ; i < n ; i++)
    {
        if (a[i] < a[p])
        {
            sum += k;
            ans += k * a[p];
            q = s[i] - sum * m;
            k = 0;
            if (q % m) k += q / m + 1;
            else k += q / m;
            p = i;
        }
        else
        {
            q = s[i] - s[p - 1] - k * m;
            if (q % m) k += q / m + 1;
            else k += q / m;
        }
    }
    ans += k * a[p];
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
