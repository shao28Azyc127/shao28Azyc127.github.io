#include <iostream>

#define ll long long
#define maxn 1000007

using namespace std;

ll n , d , ans , now , v[maxn] , a[maxn];

int main()
{
    freopen( "road.in" , "r" , stdin );
    freopen( "road.out" , "w" , stdout );
    cin >> n >> d;
    for( int i = 1 ; i < n ; ++i ) cin >> v[i];
    for( int i = 1 ; i <= n ; ++i ) cin >> a[i];
    for( int i = 2 ; i <= n ; ++i ) a[i] = min( a[i] , a[i - 1] );
    for( int i = 1 ; i < n ; ++i ) {
        if( v[i] <= now ) { now -= v[i]; }
        else {
            v[i] -= now; now = 0;
            ll tmp = v[i] / d + ( v[i] % d > 0 );
            ans += tmp * a[i];
            now = tmp * d - v[i];
        }
    }
    cout << ans;
    return 0;
}
