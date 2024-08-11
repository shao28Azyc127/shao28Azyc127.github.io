# include <bits/stdc++.h>

using namespace std ;

int n ;
int num[10][10] ;
int cnt[100005] ;

int main()
{
    freopen("lock.in" , "r" , stdin) ;
    freopen("lock.out" , "w" , stdout) ;
    scanf("%d" , &n) ;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= 5 ; j++ ) scanf("%d" , &num[i][j]) ;
    int ans = 0 ;
    for ( int i = 0 ; i <= 99999 ; i++ )
    {
        int dig[10] , now = i ;
        for ( int j = 1 ; j <= 5 ; j++ ) dig[j] = now % 10 , now /= 10 ;
        // bool tmp = false ;
        // if ( dig[1] == 0 && dig[2] == 0 && dig[3] == 1 && dig[4] == 1 )
        // {
        //     for ( int j = 1 ; j <= 5 ; j++ )
        //     {
        //         printf("%d " , dig[j]) ;
        //     }
        //     puts("") ;
        //     tmp = true ;
        // }
        for ( int j = 1 ; j <= n ; j++ )
        {
            int cnt1 = 0 , pos1 = 0 , pos2 = 0 ;
            for ( int k = 1 ; k <= 5 ; k++ )
            {
                if ( dig[k] == num[j][k] ) cnt1++ ;
                else
                {
                    if ( ! pos1 ) pos1 = k ;
                    else if ( ! pos2 ) pos2 = k ;
                }
            }
            // if ( tmp ) printf("cnt1:%d\n" , cnt1) ;
            if ( cnt1 == 5 ) continue ;
            else if ( cnt1 == 4 ) cnt[i] ++ ;
            else if ( cnt1 == 3 )
            {
                if ( pos2 - pos1 == 1 && ( dig[pos1] - num[j][pos1] + 10 ) % 10 == ( dig[pos2] - num[j][pos2] + 10 ) % 10 ) cnt[i] ++ ;
            }
        }
        if ( cnt[i] == n ) ans++ ;
    }
    printf("%d\n" , ans) ;
    return 0 ;
}