#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5 ;
char a[N] ;
int n , ans = 0 ,l[N][2] , ls = 0 , r[N][2] ;
void dfs ( int lx , int rx ) {
    if ( lx == 0 ) return ;
    if ( rx == n - 1 ) return ;
    if ( a[lx-1] == a[rx+1] && a[rx] != a[rx + 1]) {
        ++ ans ;
        dfs ( lx - 1 , rx + 1 ) ;
    }
    for ( int i = 1 ; i <= ls ; ++ i )
        if ( lx - 1 <= r[i][0] && lx >= r[i][1] ) ++ ans , dfs ( 2 * r[i][1] - 1 - lx , rx ) ;
}
int main (){
    freopen ("game.in","r",stdin) ;
    freopen ("game.out","w",stdout) ;
    cin >> n >> a ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[i] == a[i-1] ) {
            ++ ans ;
            dfs ( i-1 , i ) ;
            int j = 1 ;
            for ( ; i - 1 >= j && a[i+j] == a[i-1-j] && a[i+j]!= a[i+j+1]; ++ j ) ;
            l[++ls][0] = i - 1 - j ;
            l[ls][1] = i - 1 ;
            r[ls][1] = i ;
            r[ls][0] = i + j ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}
