# include <bits/stdc++.h>

using namespace std ;

int n , m ;
char s[3005][3005] ;
char s1[3005] , s2[3005] ;
bool cmp( char a , char b )
{
    return a > b ;
}
int main()
{
    freopen("dict.in" , "r" , stdin) ;
    freopen("dict.out" , "w" , stdout) ;
    scanf("%d%d" , &n , &m) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf("%s" , s[i] + 1) ;
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        int cnt[30] ;
        memset( cnt , 0 , sizeof( cnt ) ) ;
        for ( int j = 1 ; j <= m ; j++ ) cnt[s[i][j] - 'a'] ++ ;
        // int nowp = 1 ;
        for ( int j = 0 ; j < 26 ; j++ )
        {
            if ( ! cnt[j] ) continue ;
            s1[i] = j + 'a' ;
            break ;
        }
        // nowp = 1 ;
        for ( int j = 25 ; j >= 0 ; j-- )
        {
            if ( ! cnt[j] ) continue ;
            s2[i] = j + 'a' ;
            break ;
        }
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        bool flag = true ;
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( j == i ) continue ;
            if ( s1[i] >= s2[j] ) flag = false ;
        }
        if ( flag ) printf("1") ;
        else printf("0") ;
    }
    puts("") ;
    return 0 ;
}