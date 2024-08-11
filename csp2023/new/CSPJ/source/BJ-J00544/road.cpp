//road
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n , v[100005] , a[100005] , d , val , ans , MIN , Sv[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) , cout.tie(NULL);
    freopen( "road.in" , "r" , stdin );
    freopen( "road.out" , "w" , stdout );
    cin >> n >> d;
    for ( int i = 1; i < n; i++ )   cin >> v[i] , Sv[i] = Sv[i - 1] + v[i];
    for ( int i = 1; i <= n; i++ )  cin >> a[i];
    MIN = a[1];
    for ( int i = 2; i <= n; i++ )
    {
        if ( a[i] < MIN || i == n )
        {
            ll cost = ( Sv[i - 1] - 1 ) / d + 1 - val;
            val += cost;
            ans += cost * MIN;
            MIN = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
