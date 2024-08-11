#include <iostream>

#define ll long long
#define maxn 107

using namespace std;

ll n , ans , f[maxn] , g[maxn] , a[5][maxn];

void dfs( ll k )
{
    if( k == 5 ) {
        for( int i = 1 ; i <= n ; ++i ) {
            ll sum = 0 , tmp = 0;
            for( int j = 0 ; j < 5 ; ++j ) g[j] = ( a[i][j] - f[j] + 10 + 10 ) % 10;
            for( int j = 0 ; j < 5 ; ++j ) sum += ( g[j] > 0 );
            if( sum == 0 || sum > 2 ) return;
            if( sum == 2 ) {
                for( int j = 0 ; j < 4 ; ++j ) if( g[j] != 0 && g[j] == g[j + 1] ) tmp = 1;
                if( !tmp ) return;
            }
        }
        ans ++;
        return;
    }
    for( int i = 0 ; i < 10 ; ++i ) {
        f[k] = i; dfs( k + 1 );
    }
}

int main()
{
    freopen( "lock.in" , "r" , stdin );
    freopen( "lock.out" , "w" , stdout );
    cin >> n;
    for( int i = 1 ; i <= n ; ++i )
        for( int j = 0 ; j < 5 ; ++j )
            cin >> a[i][j];
    dfs( 0 );
    cout << ans;
    return 0;
}
