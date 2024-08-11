# include <bits/stdc++.h>

using namespace std ;

int n , m ;
int id[100005] , st[100005] ;
struct Edge
{
    int to , next , w ;
} g[200005] ;
int fte[100005] , gsz ;
void addedge( int x,  int y , int z )
{
    g[++ gsz] = ( Edge ) { y , fte[x] , z } ;
    fte[x] = gsz ;
}
int col[100005] ;
int trans( int c , int v )
{
    if ( c == 3)  return 3 ;
    else if ( v == 0 ) return c ;
    return 3 - c ;
}
vector < int > tmp ;
bool dfs( int x , int c )
{
    tmp.push_back( x ) ;
    col[x] = c ;
    bool flag = true ;
    for ( int i = fte[x] ; i ; i = g[i].next )
    {
        int y = g[i].to ;
        // printf("%d -> %d %d\n" , x , y , g[i].w) ;
        // printf("%d %d\n" , col[x] , col[y]) ;
        int nc = trans( c , g[i].w ) ;
        if ( ! col[y] ) flag &= dfs( y , nc ) ;
        else if ( col[y] != nc ) flag = false ;
    }
    return flag ;
}
void solve()
{
    gsz = 0 ;
    memset( fte,  0 , sizeof( fte ) ) ;
    memset( col , 0 , sizeof( col ) ) ;
    scanf("%d%d" , &n , &m) ;
    for ( int i = 1 ; i <= n ; i++ ) id[i] = i , st[i] = 0 ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        char ch ;
        cin >> ch ;
        if ( ch == '+' )
        {
            int x , y ;
            scanf("%d%d" , &x , &y) ;
            id[x] = id[y] , st[x] = st[y] ;
        }
        else if ( ch == '-' ) 
        {
            int x , y ;
            scanf("%d%d" , &x , &y) ;
            id[x] = id[y] , st[x] = ( 1 - st[y] ) ;
        }
        else
        {
            int x ;
            scanf("%d" , &x) ;
            st[x] = 0 ;
            if ( ch == 'T' ) id[x] = n + 1 ;
            else if ( ch == 'F' ) id[x] = n + 2 ;
            else id[x] = n + 3 ;
        }
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        // printf("now:%d %d %d\n" , i , id[i] , st[i]) ;
        addedge( i , id[i] , st[i] ) ;
        addedge( id[i] , i , st[i] ) ;
    }
    int ans = 0 ;
    dfs( n + 3 , 3 ) ;
    dfs( n + 1 , 1 ) ;
    dfs( n + 2 , 2 ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( ! col[i] ) 
        {
            tmp.clear() ;
            if ( ! dfs( i , 1 ) ) 
            {
                for ( auto v : tmp ) col[v] = 0 ;
                tmp.clear() ;
                dfs( i , 3 ) ;
                // printf("test:%d\n" , tmp.size()) ;
            }
            // printf("test:%d\n" , tmp.size()) ;
        }
    }
    for ( int i = 1 ; i <= n ; i++ )
        if ( col[i] == 3 ) ans++ ;
    printf("%d\n" , ans) ;
}
int main()
{
    freopen("tribool.in" , "r" , stdin) ;
    freopen("tribool.out" , "w" , stdout) ;
    int c,  t ;
    scanf("%d%d" , &c , &t) ;
    while ( t -- ) solve() ;
    return 0 ;
}