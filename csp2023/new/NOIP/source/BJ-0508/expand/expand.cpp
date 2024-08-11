#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5+5 ;
int x[N] , y[N] , q , n , m , xz[N] , yz[N] , s[N] ;
bool dfs ( int ax[N] , int nx , int ay[N] , int my , int xs ) {
    if ( s[xs-1] == my ) {
        for ( int i = xs ; i <= nx ; ++ i ) {
            if ( ax[i] <= ay[my] ) return 0 ;
        }
        return 1 ;
    }
    if ( xs == nx ) {
        for ( int i = s[xs-1] ; i <= my ; ++ i ) {
            if ( ax[xs] <= ay[i] ) return 0 ;
        }
        return 1 ;
    }
    if ( ax[xs] <= ay[s[xs-1]]) return 0 ;
    if ( ax[xs] <= ay[s[xs-1]+1] ) {
        s[xs] = s[xs-1] ;
        if ( dfs ( ax , nx , ay , my , xs + 1 ) ) return 1 ;
    }
    else {
        for ( int i = 0 ; s[xs-1] + i <= my && ay[s[xs-1] + i] < ax[xs] ; ++ i ) {
            s[xs] = s[xs-1] + i ;
            if ( dfs ( ax , nx , ay , my , xs + 1 ) ) return 1 ;
        }
    }
}
bool fl ( int ax[N] , int nx , int ay[N] , int my ) {
    if ( ax[1] == ay[1] || ax[n] == ay[m]|| ( ax[1] - ay[1] ) * ( ax[n]-ay[m] ) <= 0 ) return 0 ;
    if ( nx == 1 ) {
        for ( int i = 1 ; i <= my ; ++ i ) {
            if ( ax[1] <= ay[i] ) return 0 ;
        }
        return 1 ;
    }
    for ( int i = 2 ; i <= my ; ++ i ) {
        bool fs = 0 ;
        for (int j = 1 ; j <= min ( i , nx ) ; ++ j ) {
            if ( ay[i] < ax[j] ) fs = 1 ;
        }
        if ( !fs ) return 0 ;
    }
    for ( int i = 2 ; i <= nx ; ++ i ) {
        bool fs = 0 ;
        for (int j = 1 ; j <= min ( i , my ) ; ++ j ) {
            if ( ay[j] < ax[i] ) fs = 1 ;
        }
        if ( !fs ) return 0 ;
    }
    s[1] = 1 ;
    return dfs(ax,nx,ay,my,2) ;
}
int main () {
    freopen("expand.in","r",stdin) ;
    freopen("expand.out","w",stdout) ;
    int c ;
    cin >> c >> n >> m >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) { cin >> x[i] ; }
    for ( int i = 1 ; i <= m ; ++ i ) { cin >> y[i] ; }
    if ( x[1] > y[1] ) {
        if ( fl ( x , n ,  y , m ) ) cout << 1 ;
        else cout << 0 ;
    }
    else {
        if ( fl( y , m , x , n ) ) cout << 1 ;
        else cout << 0 ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            xz[j] = x[j] ;
            yz[j] = y[j] ;
        }
        int kx , ky ;
        cin >> kx >> ky ;
        for ( int j = 1 ; j <= kx ; ++ j ) {
            int u , v ;
            cin >> u >>v ;
            xz[u] = v ;
        }
        for ( int j = 1 ; j <= ky ; ++ j  ){
            int u , v ;
            cin >> u >> v ;
            yz[u] = v ;
        }
        if ( xz[1] > yz[1] ) {
            if ( fl ( xz , n , yz , m ) ) cout << 1 ;
            else cout << 0 ;
        }
        else {
            if ( fl( yz , m , xz , n ) ) cout << 1 ;
            else cout << 0 ;
        }
    }
    return 0 ;
}
