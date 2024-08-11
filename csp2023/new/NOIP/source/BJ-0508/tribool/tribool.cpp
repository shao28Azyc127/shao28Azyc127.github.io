#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 5 ;
int c , t , x[N] , n , m ;
void dfs ( int xa ) {
    if ( x[xa] == n + 1 || x[xa] == - ( n + 1 ) || x[xa] == 0 ) return ;
    if ( xa == x[xa] || xa == -x[xa] ) {
        if ( x[xa] < 0 ) x[xa] = 0 ;
        return ;
    }
    if ( x[xa] < 0) {
        x[xa] = - x[-x[xa]] ;
        dfs ( -x[xa] ) ;
    }
    else {
        x[xa] = x[x[xa]] ;
        dfs ( x[xa] ) ;
    }
    if ( x[xa] < 0) {
        x[xa] = - x[-x[xa]] ;
    }
    else {
        x[xa] = x[x[xa]] ;
    }
    return ;
}
int main () {
    freopen("tribool.in","r",stdin) ;
    freopen("tribool.out","w",stdout) ;
    cin >> c >> t ;
    for ( int aas = 1 ; aas <= t ; ++ aas ) {
        int ans = 0 ;
        cin >> n >> m ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            x[i] = i ;
        }
        for ( int i = 1 ; i <= m ; ++ i ) {
            char s ;
            int ax , ay ;
            cin >> s ;
            if ( s == 'T' ){
                cin >> ax ;
                x[ax] = n + 1 ;
            }
            if ( s == 'F' ) {
                cin >> ax ;
                x[ax] = -(n+1) ;
            }
            if ( s == 'U' ) {
                cin >> ax ;
                x[ax] = 0 ;
            }
            if ( s == '+' ) {
                cin >> ax >> ay ;
                x[ax] = x[ay] ;
            }
            if ( s == '-' ) {
                cin >> ax >> ay ;
                x[ax] = -x[ay] ;
            }
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( x[i] == -i ) x[i] = 0 ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( x[i] == n + 1 || x[i] == 0 || x[i]== -(n+1) ) continue ;
            if ( x[i] == i || x[i] == -i ) continue ;
            if (x[i] < 0 ) dfs ( -x[i] ) , x[i] = -x[-x[i]] ;
            else dfs ( x[i] ) , x[i]=x[x[i]] ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( x[i] == 0 ) ++ ans ;
        }
        cout << ans << endl ;
    }
    return 0 ;
}
