#include <iostream>
#include <queue>

#define ll long long
#define maxn 20007

using namespace std;

ll n , m , k , u , v , a , f[maxn][200]; vector< ll >e[maxn] , w[maxn] , g[2000000];

void get( ll x , ll y )
{
    for( int i = 0 ; i < e[x].size() ; ++i ) {
        ll to = e[x][i] , tmp = w[x][i] / k * k + y;
        while( tmp < w[x][i] ) tmp += k;
        tmp = max( tmp , f[x][y] );
        g[tmp + 1].push_back( to );
    }
}

void bfs( )
{
    g[0].push_back( 1 );
    for( int i = 0 ; i < 1500000 ; ++i )
        for( int j = 0 ; j < g[i].size() ; ++j )
            if( f[g[i][j]][i % k] >= 1145141141541145 ) {
                f[g[i][j]][i % k] = i;
                get( g[i][j] , i % k );
            }
}

int main()
{
    freopen( "bus.in" , "r" , stdin );
    freopen( "bus.out" , "w" , stdout );
    cin >> n >> m >> k;
    while( m -- ) {
        cin >> u >> v >> a;
        e[u].push_back( v ); w[u].push_back( a );
    }
    for( int i = 1 ; i <= n ; ++i ) for( int j = 0 ; j <= k ; ++j ) f[i][j] = 114514114514114514;
    bfs(  );
    if( f[n][0] > 11451411451411451 ) cout << -1;
    else cout << f[n][0];
    return 0;
}
