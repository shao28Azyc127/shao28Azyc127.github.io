# include <bits/stdc++.h>

using namespace std ;

int n ;
char ch[2000005] ;
typedef long long ll ;
int le[2000005] , ans[2000005] ;
int stk[2000005] , top , rtop ;
typedef long long ll ;
int rpos[2000005][30] , pos[30] , tmp[200005] , id[2000005] ;
int main()
{
    freopen("game.in" , "r" , stdin) ;
    freopen("game.out" , "w" , stdout) ;
    scanf("%d" , &n) ;
    scanf("%s" , ch + 1) ;
    if ( n <= 8000 )
    {
        ll tt = 0 ;
        stack < int > stk2 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            while ( ! stk2.empty() ) stk2.pop() ;
            stk2.push( ch[i] ) ;
            int res = 0 ;
            for ( int j = i - 1 ; j >= 1 ; j-- )
            {
                if ( ! stk2.empty() && stk2.top() == ch[j] ) stk2.pop() ;
                else stk2.push( ch[j] ) ;
                if ( ! stk2.size() ) 
                {
                    res++ ;
                    //  printf("[%d,%d]\n" , j , i);
                }
            }
            tt += res ;
            // printf("now:%d %d\n" , i , res) ;
        }
        printf("%lld\n" , tt) ;
    }
    else 
    {
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( i == 1 || ch[i] != ch[i - 1] ) le[i] = i ;
            else le[i] = le[i - 1] ;
        }
        for ( int i = 1 ; i <= n ; i++ )
        {
            // printf("i:%d\n" , i) ;
            if ( ch[i] == ch[i - 1] ) ans[i] = ans[i - 2] + 1 ;
            else
            {
                if ( pos[ch[i] - 'a'] >= max( stk[rtop] , 1 ) )
                {
                    // printf("%d %d %d\n" , i , pos[ch[i] - 'a'] , stk[rtop]) ;
                    ans[i] = ans[pos[ch[i] - 'a'] - 1] + 1 ;
                }
            }
            if ( ch[i] != ch[i + 1] )
            {
                if ( ( i - le[i] + 1 ) % 2 == 1 ) 
                {
                    if ( rtop && ch[stk[rtop]] == ch[i] )
                    {
                        for ( int j = 0 ; j < 26 ; j++ ) pos[j] = rpos[stk[rtop]][j] ;
                        top = rtop + 1 ;
                        stk[top] = i ;
                        pos[ch[i] - 'a'] = i ;
                        for ( int j = 0 ; j < 26 ; j++ ) rpos[i][j] = pos[j] ;
                        rtop = tmp[stk[rtop]] ;
                    }
                    else
                    {
                        stk[++ top] = i ;
                        id[i] = top ;
                        tmp[i] = rtop ;
                        rtop = top ;
                        pos[ch[i] - 'a'] = i ;
                        for ( int j = 0 ; j < 26 ; j++ ) rpos[i][j] = pos[j] ;
                    }
                }
                else
                {
                    stk[++ top] = i - 1 ;
                    id[i - 1] = top , tmp[i - 1] = rtop ;
                    pos[ch[i] - 'a'] = i - 1 ;
                    for ( int j = 0 ; j < 26 ; j++ ) rpos[i - 1][j] = pos[j] ;
                    stk[++ top] = i ;
                    id[i] = top , tmp[i] = rtop ;
                    pos[ch[i] - 'a'] = i ;
                    for ( int j = 0 ;j  < 26 ; j ++ ) rpos[i][j] = pos[j] ;
                }
                // for ( int j = 0 ; j < 26 ; j++ )
                //     if ( pos[j] ) printf("pos[%c] %d\n" , j + 'a' , pos[j]) ;
            }
        }
        ll res = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) res += ans[i] ;
        printf("%lld\n" , res) ;
    }
    return 0 ;
}