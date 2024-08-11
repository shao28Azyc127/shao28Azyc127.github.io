#include <bits/stdc++.h>
using namespace std;

const int N= 1e4 +5 ;
int m[10][6] , ma[100][6] , ans = 0 ;
bool f[100] ;
int main (){
    freopen ("lock.in","r",stdin) ;
    freopen ("lock.out","w",stdout) ;
    int n ;
    cin >> n ;
    for (int i = 1 ; i <= n ; ++i )
        for (int j = 1 ; j <= 5 ; ++j )
            cin >> m[i][j];
    if ( n == 1 ) {
        cout << 81 << endl ;
    }
    else {
        int x[6] ;
        for ( int i = 1 ; i <= 5 ; ++i ) {
            x[i] = m[1][i] ;
        }
        for ( int i = 1 ; i <= 5 ; ++ i ){
            for (int j = 1 ; j <= 9 ; ++ j ) {
                int y[6] ;
                for ( int k = 1 ; k <= 5 ; ++k ) {
                    y[k] = x[k] ;
                }
                y[i] += j ;
                y[i] %= 10 ;
                ++ ans;
                for ( int k = 1 ; k <= 5 ; ++k ) {
                    ma[ans][k] = y[k] ;
                }
                f[ans] = 1 ;
                if ( i <= 4 ) {
                    y[i+1] += j ;
                    y[i+1] %= 10 ;
                    ++ans;
                    for ( int k = 1 ; k <= 5 ; ++k ) {
                        ma[ans][k] = y[k] ;
                    }
                    f[ans] = 1 ;
                }
            }
        }
        int d = ans ;
        for ( int i = 1 ; i <= d ; ++ i ) {
            for ( int j = 2 ; j <= n ; ++j ) {
                if ( f[i] ) {
                        int ms1 = 0 , ms2 = 0 ;
                        for ( int k = 1 ; k <= 5 ; ++k ) {
                            if ( ma[i][k] != m[j][k] ) {
                                if ( ms1 == 0 ) ms1 = k ;
                                else if ( ms2 == 0 ) ms2 = k ;
                                else {
                                    f[i] = 0 ;
                                    -- ans ;
                                    break ;
                                }
                            }
                        }
                        if ( ms1 == 0 ) {
                            f[i] = 0 ;
                            -- ans ;
                        }
                        if ( f[i] == 1 && ms2 != 0 ) {
                            if ( ms2 - ms1 > 1 ) {
                                f[i] = 0 ;
                                -- ans ;
                            }
                            else {
                                int x1 = ma[i][ms1] - m[j][ms1] , x2 = ma[i][ms2] - m[j][ms2] ;
                                if ( x1 < 0 ) x1 += 10 ;
                                if ( x2 < 0 ) x2 += 10 ;
                                if ( x1 != x2 ) {
                                    f[i] = 0 ;
                                    -- ans ;
                                }
                            }
                        }
                }
                else break ;
            }
        }
        cout << ans << endl ;
    }
    return 0 ;
}
