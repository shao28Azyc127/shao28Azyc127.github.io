# include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
int n , m , k , d ;
struct node
{
    int l , r ;
    ll maxa , maxb , maxab , lazya , lazyb ;
    int ch[2] ;
} seg[100005 * 80] ;
int rt ;
int idx ;
void pushup( int id )
{
    if ( seg[id].ch[0] || seg[id].ch[1] )
        seg[id].maxa = max( seg[seg[id].ch[0]].maxa , seg[seg[id].ch[1]].maxa ) ,
        seg[id].maxb = max( seg[seg[id].ch[0]].maxb , seg[seg[id].ch[1]].maxb ) ,
        seg[id].maxab = max( seg[seg[id].ch[0]].maxab , seg[seg[id].ch[1]].maxab ) ;
}
void maketag( int id , ll v1 , ll v2 )
{
    seg[id].maxa += v1 ;
    seg[id].lazya += v1 ;
    if ( v2 )
    {
        seg[id].maxb = v2 ;
        seg[id].lazyb = v2 ;
        seg[id].maxab = seg[id].maxa + seg[id].maxb ;
    }
    else seg[id].maxab += v1 ;
}
int getnode( int l , int r )
{
    idx++ ;
    seg[idx].l = l , seg[idx].r = r ;
    seg[idx].maxa = 1ll * d * ( n - l - 1 ) , seg[idx].maxb = 0 ;
    seg[idx].maxab = seg[idx].maxa ;
    seg[idx].lazya = seg[idx].lazyb = 0 ;
    seg[idx].ch[0] = seg[idx].ch[1] = 0 ;
    // printf("query:%d [%d %d] [%d %d] %lld %lld %lld %lld %lld\n" , idx , seg[idx].l , seg[idx].r , l , r
    // , seg[idx].maxa , seg[idx].maxb , seg[idx].maxab, seg[idx].lazya , seg[idx].lazyb) ;
    return idx ;
}
void pushdown( int id )
{
    int mid = ( seg[id].l + seg[id].r ) >> 1 ;
    // printf("now:%d [%d,%d] %d\n" , id , seg[id].l , seg[id].r , mid) ;
    if ( ! seg[id].ch[0] ) seg[id].ch[0] = getnode( seg[id].l , mid ) ;
    maketag( seg[id].ch[0] , seg[id].lazya , seg[id].lazyb ) ;
    if ( ! seg[id].ch[1] ) seg[id].ch[1] = getnode( mid + 1 , seg[id].r ) ;
    maketag( seg[id].ch[1] , seg[id].lazya , seg[id].lazyb ) ;
    seg[id].lazya = seg[id].lazyb = 0 ;
}
void update1( int id , int l , int r , ll v ) //qujianjia
{
    if ( l <= seg[id].l && seg[id].r <= r ) 
    {
        maketag( id , v , 0 )  ;
        return ;
    }
    int mid = ( seg[id].l + seg[id].r ) >> 1 ;
    pushdown( id ) ;
    if ( l <= mid ) update1( seg[id].ch[0] , l , r , v ) ;
    if ( mid + 1 <= r ) update1( seg[id].ch[1] , l , r , v ) ;
    pushup( id ) ;
}
void update2( int id , int l , int r , ll v ) //qujianfuzhi
{
    if ( l <= seg[id].l && seg[id].r <= r ) 
    {
        maketag( id , 0 , v )  ;
        return ;
    }
    int mid = ( seg[id].l + seg[id].r ) >> 1 ;
    pushdown( id ) ;
    if ( l <= mid ) update2( seg[id].ch[0] , l , r , v ) ;
    if ( mid + 1 <= r ) update2( seg[id].ch[1] , l , r , v ) ;
    pushup( id ) ;
}
const ll INF = 1e18 ;
ll query( int id , int l , int r )
{
    if ( l <= seg[id].l && seg[id].r <= r ) 
    {
        return seg[id].maxab ;
    }
    int mid = ( seg[id].l + seg[id].r ) >> 1 ;
    pushdown( id ) ;
    ll ans = -INF ;
    if ( l <= mid ) ans = max( ans , query( seg[id].ch[0] , l , r ) ) ;
    if ( mid + 1 <= r ) ans = max( ans , query( seg[id].ch[1] , l , r ) ) ;
    return ans ;
}
struct node2 
{
    int l , r , v ;
} g[100005] ;
bool cmp( node2 a , node2 b )
{
    return a.l > b.l ;
}

void solve()
{
    scanf("%d%d%d%d" , &n , &m , &k , &d) ;
    idx = 0 ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        scanf("%d%d%d" , &g[i].l , &g[i].r , &g[i].v) ;
        int l = g[i].l - g[i].r + 1 , r = g[i].l ;
        g[i].l = l , g[i].r = r ;
        // printf("[%d,%d] %d\n" , g[i].l , g[i].r , g[i].v) ;
        // assert( g[i].l > 0 ) ;
        // assert( g[i].r <= n ) ;
    }
    sort( g + 1 , g + m + 1 , cmp ) ;
    ll ans = 0 ;
    int lstl = n ;
    getnode( 1 , n ) ;
    // printf("idx:%d\n" , idx) ;
    // puts("OK") ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        // printf("lstl:%d nowl:%d\n" , lstl , g[i].l) ;
        int j = i ;
        while ( j < m && g[j + 1].l == g[j].l ) j++ ;
        // printf("[%d,%d]\n" , i , j) ;
        update1( 1 , 1 , n , -1ll * d * ( lstl - g[i].l ) ) ;
        // puts("OK") ;
        for ( int x = i ; x <= j ; x++ ) update1( 1 , g[x].r , n , g[x].v ) ;
        ll res = query( 1 , g[i].l , min( g[i].l + k - 1 , n )) ;
        // puts("OK") ;
        if ( res > ans )
        {
            ans = res ;
            if ( g[i].l > 2 )
                update2( 1 , 1 , g[i].l - 2 , res ) ;
        }
        lstl = g[i].l ;
        i = j ;
    }
    printf("%lld\n" , ans) ;
}

int main()
{
    freopen("run.in" , "r" , stdin) ;
    freopen("run.out" , "w" , stdout) ;
    int c , t ;
    scanf("%d%d" , &c , &t) ;
    while ( t -- ) solve() ;
    return 0 ;
}