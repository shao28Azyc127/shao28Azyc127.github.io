# include <bits/stdc++.h>

using namespace std ;

int n , m , q , c ;
int a[500005] , b[500005] ;
int aa[500005] , bb[500005] ;
bool dp[2005][2005] ;
void solve()
{
    if ( n <= 2000 && m <= 2000 )
    {
        memset( dp , 0 , sizeof( dp ) ) ;
        // puts("now:") ;
        // for ( int i = 1 ; i <= n ; i++ ) printf("%d " , a[i]) ;
        // puts("") ;
        // for ( int i = 1 ; i <= m ; i++ ) printf("%d " , b[i]) ;
        if ( a[1] > b[1] ) 
        {
            dp[n][m] = ( a[n] > b[m] ) ;
            for ( int i = n ; i >= 1 ; i-- )
                for ( int j = m ; j >= 1 ; j-- )
                {
                    if ( i == n && j == m ) continue ;
                    if ( a[i] <= b[j] ) continue ;
                    dp[i][j] |= ( dp[i + 1][j] | dp[i][j + 1] | dp[i + 1][j + 1] ) ;
                    // printf("dp[%d][%d] %d\n" , i , j , dp[i][j]) ;
                }
            printf("%d" , dp[1][1]) ;
        }
        else if ( a[1] < b[1] ) 
        {
            dp[n][m] = ( a[n] < b[m] ) ;
            for ( int i = n ; i >= 1 ; i-- )
                for ( int j = m ; j >= 1 ; j-- )
                {
                    if ( i == n && j == m ) continue ;
                    if ( a[i] >= b[j] ) continue ;
                    dp[i][j] |= ( dp[i + 1][j] | dp[i][j + 1] | dp[i + 1][j + 1] ) ;
                    // printf("dp[%d][%d] %d\n" , i , j , dp[i][j]) ;
                }
            printf("%d" , dp[1][1]) ;
        }
        else printf("0") ;
    }
    else printf("0") ;
}
int main()
{
    freopen("expand.in" , "r" , stdin) ;
    freopen("expand.out" , "w" , stdout) ;
    scanf("%d%d%d%d" , &c , &n , &m , &q) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf("%d" , a + i) ;
        aa[i] = a[i] ;
    }
    for ( int i = 1 ; i <= m ; i++ ) scanf("%d" , b + i) , bb[i] = b[i] ;
    solve() ;
    while ( q -- )
    {
        for ( int i = 1 ; i <= n ; i++ ) a[i] = aa[i] ;
        for ( int i = 1 ; i <= m ; i++ ) b[i] = bb[i] ;
        int kx , ky ;
        scanf("%d%d" , &kx , &ky) ;
        for ( int i = 1 ; i <= kx ; i++ )
        {
            int p , v ;
            scanf("%d%d" , &p , &v) ;
            a[p] = v ;
        }
        for ( int i = 1 ; i <= ky ; i++ )
        {
            int p , v ;
            scanf("%d%d" , &p , &v) ;
            b[p] = v ;
        }
        solve() ;
    }
    puts("") ;
    return 0 ;
}