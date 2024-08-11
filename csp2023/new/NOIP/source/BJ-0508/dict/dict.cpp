#include<bits/stdc++.h>
using namespace std ;

const int N = 3005 ;
int n , m ;
string a[N] ;
char mi[N][N] , ma[N][N] ;
int x[N][30] , y[N][30] ;
bool f[N] ;
int main () {
    freopen("dict.in","r",stdin) ;
    freopen("dict.out","w",stdout) ;
    cin >> n >> m ;
    for (int i = 1; i <= n ; ++ i ) {
        cin >> a[i] ;
        for ( int j = 0 ; j < m ; ++ j ) {
            int ii = a[i][j]-'a'+1;
            x[i][ii] ++;
            y[i][ii] ++ ;
        }
    }
    if ( n == 1 ) cout << 1 << endl ;
    else {
        for ( int i = 1 ; i <= n ; ++ i ) {
            int xi = 0 ;
            for ( int j = 1 ; j <= 26 ; ++ j ) {
                if ( x[i][j] != 0 ) {
                    for ( ; x[i][j] != 0 ; ) {
                        char ii = 'a' + j - 1 ;
                        mi[i][xi++] = ii ;
                        -- x[i][j] ;
                    }
                }
            }
            for ( int j = m - 1 ; j >= 0 ; -- j ) {
                ma[i][j] = mi[i][m - j -1] ;
            }
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            bool aay = 0 ;
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( i == j ) continue ;
                if ( f[j] ) continue ;
                bool aax = 0 ;
                for ( int k = 0 ;k < m ; ++ k ) {
                    int axa = mi[i][k] ;
                    int bxb = ma[j][k] ;
                    if ( axa < bxb ) {
                        aax = 1 ;
                        break ;
                    }
                    if ( axa > bxb ) {
                        cout << 0 ;
                        f[i] = 1;
                        aax = 1 ;
                        aay = 1 ;
                        break ;
                    }
                }
                if ( f[i] ) break ;
                if( !aax ) f[i] = 1 , aay = 1 , cout << 0 ;
            }
            if ( !aay ) {
                cout << 1 ;
            }
        }
        cout << endl ;
    }
    return 0 ;
}
