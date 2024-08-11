#include <iostream>
#include <vector>

#define ll long long
#define maxn 1007

using namespace std;

ll n , ans , l , r , f[maxn][maxn]; char a[maxn]; vector< ll >v[maxn];

int main()
{
    freopen( "game.in" , "r" , stdin );
    freopen( "game.out" , "w" , stdout );
    cin >> n;
    for( int i = 1 ; i <= n ; ++i ) cin >> a[i];
    for( int i = 1 ; i <= n ; ++i ) f[i + 1][i] = 1;
    for( int i = 1 ; i <= n ; ++i ) {
        for( int j = 1 ; j <= n - i + 1 ; ++j ) {
            l = j; r = i + j - 1;
            if( a[l] == a[r] ) f[l][r] |= f[l + 1][r - 1];
            for( int k = l ; k < r ; ++k )
                f[l][r] |= ( f[l][k] & f[k + 1][r] );
            ans += f[l][r];
        }
    }
    cout << ans;
    return 0;
}
