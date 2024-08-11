#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +5 ;
int n , a[N] , b[N] , c[N] , u[N] , v[N] , ans = 0 ;
int main (){
    freopen ("tree.in","r",stdin) ;
    freopen ("tree.out","w",stdout) ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >>a[i] >> b[i] >>c[i] ;
    }
    for (int i = 1 ; i < n ; ++ i ) {
        cin >> u[i] >> v[i] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int s = i , h = 0 ;
        for ( ; h < a[i] ; ++ s , h += max ( b[i] + s * c[i] , 1 ) ) ;
        ans = max ( ans , s ) ;
    }
    cout << ans << endl ;
    return 0 ;
}
