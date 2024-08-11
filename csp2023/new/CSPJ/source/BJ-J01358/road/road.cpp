#include <bits/stdc++.h>
using namespace std ;
int my_floor(int a, int b)
{
    return (a + b - 1) / b ;
}
int n, d, v[100010], a[100010], ans ;
int main()
{
    freopen("road.in", "r", stdin) ;
    freopen("road.out", "w", stdout) ;
    cin >> n >> d ;
    for(int i = 1 ; i < n ; i++)
    {
        scanf("%d", &v[i]) ;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d", &a[i]) ;
    }
    int lu = 0, youq = 99999999, oil = 0 ;
    for(int i = 1 ; i < n ; i++)
    {
        if(youq > a[i])
        {
            ans += my_floor(lu - oil, d) * youq ;
            oil += my_floor(lu - oil, d) * d ;
            oil -= lu ;
            lu = 0 ;
            youq = a[i] ;
        }
        lu += v[i] ;
    }
    ans += my_floor(lu - oil, d) * youq ;
    cout << ans ;
    return 0 ;
}
